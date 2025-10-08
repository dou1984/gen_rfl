// Copyright (c) 2023-2025 ZhaoYunshan
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include <iostream>
#include <tuple>
#include <regex>
#include <list>
#include <string>
#include "gen_rfl.h"
#include "analyzer.h"
#include "format_tpl.h"
#include "branch.h"
#include "reflect.h"
#include "filter.h"
#include "config.h"

// #define LLVM_OUT
using namespace reflect;

template <class S, class D>
auto join(const S str, const D &delimiter)
{
    std::ostringstream oss;
    auto it = str.begin();
    if (it != str.end())
    {
        oss << *it++;
    }
    while (it != str.end())
    {
        oss << delimiter << *it++;
    }
    return oss.str();
}

template <class T>
auto get_access(const T &t)
{
    switch (t)
    {
    case AS_public:
        return flag_public;
    case AS_protected:
        return flag_protected;
    case AS_private:
        return flag_private;
    default:
        return flag_none;
    }
}
template <class T>
std::tuple<QualType, QualType> get_type_name(T *_t)
{
    QualType FieldType = _t->getType();

    QualType CanonicalType = FieldType.getCanonicalType();
    QualType UnqualifiedType = CanonicalType.getUnqualifiedType();

    while (true)
    {
        if (UnqualifiedType->isReferenceType())
        {
            UnqualifiedType = UnqualifiedType->getPointeeType();
        }
        // else if (UnqualifiedType->isPointerType())
        // {
        //     UnqualifiedType = UnqualifiedType->getPointeeType();
        // }
        else
        {
            break;
        }
    }
    return {FieldType, UnqualifiedType};
}

void insert_base_types(const std::string &type)
{
    if (type.find("const ") == 0)
    {
        ::get_config().base_types.emplace(type);
        ::get_config().base_types.emplace(type.substr(strlen("const ")));
    }
    else
    {
        ::get_config().base_types.emplace(type);
        ::get_config().base_types.emplace(std::string("const ") + type);
    }
}

bool GetNamespaces(CXXRecordDecl *D, std::string &NamespaceName)
{

    DeclContext *Context = D->getDeclContext();
    while (Context && !Context->isTranslationUnit())
    {
        if (auto *NS = dyn_cast<NamespaceDecl>(Context))
        {
            std::string Part = NS->getNameAsString();
            if (!NamespaceName.empty())
            {
                NamespaceName = Part + "::" + NamespaceName;
            }
            else
            {
                NamespaceName = Part;
            }
            Context = Context->getParent();
        }
    }
    return true;
}
bool GetRawClass(CXXRecordDecl *D, analyzer::config_t &conf)
{
    switch (D->getTagKind())
    {
    case TTK_Class:
        conf.m_raw_class = "class " + conf.m_class;
        return true;
    case TTK_Struct:
        conf.m_raw_class = "struct " + conf.m_class;
        return true;
    case TTK_Union:
        conf.m_raw_class = "union " + conf.m_class;
        return true;
    default:
        return false;
    }
}
bool GetBaseTypeName(const std::string &Name, std::string &BaseTypeName, int &flag_object_type)
{
    if (Name.find("struct ") == 0)
    {
        flag_object_type = flag_struct;
        BaseTypeName = Name.substr(strlen("struct "));
    }
    else if (Name.find("class ") == 0)
    {
        flag_object_type = flag_class;
        BaseTypeName = Name.substr(strlen("class "));
    }
    else if (Name.find("union ") == 0)
    {
        flag_object_type = flag_union;
        BaseTypeName = Name.substr(strlen("union "));
    }
    else
    {
        throw std::runtime_error("Unsupported base class type.");
    }
    return true;
}
GenRflASTVisitor::GenRflASTVisitor(ASTContext *Context)
{
    SM = &Context->getSourceManager();
}
bool GenRflASTVisitor::VisitFunctionDecl(FunctionDecl *FD)
{
    if (FD->isImplicit() || SM->isInSystemHeader(FD->getLocation()))
    {
        return true;
    }

    // 只处理成员函数（非全局函数）
    if (llvm::dyn_cast<CXXMethodDecl>(FD))
    {
        return true;
    }

#ifdef LLVM_OUT
    llvm::outs() << "Function: " << FD->getNameAsString() << "\n";
    if (FD->hasBody())
    {
        llvm::outs() << "  - Has a body (definition)\n";
    }
#endif
    return true;
}

bool GenRflASTVisitor::VisitCXXRecordDecl(CXXRecordDecl *D)
{
    if (D->isImplicit() || SM->isInSystemHeader(D->getLocation()))
    {
        return true;
    }

    // 获取源文件信息
    SourceLocation Loc = D->getLocation();
    auto FileName = SM->getFilename(Loc).str();
#ifdef LLVM_OUT
    llvm::outs() << "Class/Struct: " << D->getNameAsString() << " (defined in: " << FileName << ")\n";
#endif

    auto filter = reflect::get_rfl_filter();
    if (filter(FileName))
    {
        return true;
    }

    static int __init = format_tpl::init();
    std::map<std::string, analyzer::info_t> _methods;
    analyzer ana;
    auto &conf = ana.get_config();
    conf.clear();
    conf.m_file = FileName;
    conf.m_class = D->getNameAsString();
    if (!GetNamespaces(D, conf.m_namespace))
    {
        return false;
    }

    std::string header, source;
    if (ana.is_generated(header, source))
    {
        std::cout << "skip " << FileName << ":" << conf.m_raw_class << " is generated." << std::endl;
        return true;
    }

    if (!GetRawClass(D, conf))
    {
        return false;
    }
    if (D->hasDefinition())
    {
        if (D->getNumBases() > 0)
        {
            for (const auto &Base : D->bases())
            {
                QualType BaseType = Base.getType();
                auto Name = BaseType.getAsString();
                std::string BaseTypeName;
                auto flag_object_type = 0;
                if (!GetBaseTypeName(Name, BaseTypeName, flag_object_type))
                {
                    continue;
                }
                auto flag_virtual_ = Base.isVirtual() ? flag_virtual : 0;
                analyzer::info_t detail = {
                    .m_variant = BaseTypeName,
                    .m_raw_variant = BaseTypeName,
                    .m_raw_type = BaseTypeName,
                    .m_flags = __flags(flag_object_type, get_access(Base.getAccessSpecifier()), flag_virtual_),
                };
                ana.push_back(BaseTypeName, detail);
            }
        }
    }
    PrintingPolicy PP(D->getASTContext().getLangOpts());

    // 遍历类的成员
    for (auto Member : D->decls())
    {
        if (auto *FD = llvm::dyn_cast<FieldDecl>(Member))
        {

            auto [FieldType, UnqualifiedType] = get_type_name(FD);
            auto TypeName = FieldType.getAsString();
            auto Name = FD->getNameAsString();

            auto flag_const_ = FD->getType().isConstQualified() ? flag_const : 0;
            auto flag_volatile_ = FD->getType().isVolatileQualified() ? flag_volatile : 0;

            if (UnqualifiedType->isBuiltinType())
            {
                auto *BT = UnqualifiedType->getAs<BuiltinType>();
                auto BaseTypeName = BT->getName(PP).str();
                analyzer::info_t detail = {
                    .m_raw_variant = Name,
                    .m_raw_type = BaseTypeName,
                    .m_flags = __flags(get_access(FD->getAccess()), flag_const_, flag_volatile_),
                };
                ana.push_back(Name, detail);

                insert_base_types(BaseTypeName);
            }
            else
            {
                analyzer::info_t detail = {
                    .m_raw_variant = Name,
                    .m_raw_type = TypeName,
                    .m_flags = __flags(get_access(FD->getAccess()), flag_const_, flag_volatile_),
                };
                ana.push_back(Name, detail);

                insert_base_types(TypeName);
            }
        }
        else if (auto *VD = llvm::dyn_cast<VarDecl>(Member))
        {
            assert(VD->isStaticDataMember());

            auto [FieldType, UnqualifiedType] = get_type_name(VD);
            std::string TypeName = FieldType.getAsString();
            std::string Name = VD->getNameAsString();

            auto flag_const_ = VD->getType().isConstQualified() ? flag_const : 0;
            auto flag_volatile_ = VD->getType().isVolatileQualified() ? flag_volatile : 0;

            if (UnqualifiedType->isBuiltinType())
            {
                auto *BT = UnqualifiedType->getAs<BuiltinType>();
                auto BaseTypeName = BT->getName(PP).str();
                analyzer::info_t detail = {
                    .m_raw_variant = Name,
                    .m_raw_type = BaseTypeName,
                    .m_flags = __flags(get_access(VD->getAccess()), flag_const_, flag_volatile_, flag_static),
                };
                ana.push_back(Name, detail);

                insert_base_types(BaseTypeName);
            }
            else
            {
                analyzer::info_t detail = {
                    .m_raw_variant = Name,
                    .m_raw_type = TypeName,
                    .m_flags = __flags(get_access(VD->getAccess()), flag_const_, flag_volatile_, flag_static),
                };
                ana.push_back(Name, detail);

                insert_base_types(TypeName);
            }
        }
        else if (auto Method = llvm::dyn_cast<CXXMethodDecl>(Member))
        {
            if (Method->isImplicit())
            {
                continue;
            }
            auto MethodName = Method->getNameAsString();
            auto flag_const_ = Method->isConst() ? flag_const : 0;
            auto flag_virtual_ = Method->isVirtual() ? flag_virtual : 0;

            std::list<std::string> _input;
            auto parameters = Method->parameters();
            for (auto &Param : parameters)
            {
                auto [FieldType, UnqualifiedType] = get_type_name(Param);
                _input.push_back(FieldType.getAsString());
            }

            {
                std::string _output = Method->getReturnType().getAsString();

                uint32_t flag_return_ = flag_return;
                if (_output == "void")
                {
                    _output = "";
                    flag_return_ = 0;
                }
                auto _tmp_type = _output + std::string("(") + join(_input, ",") + std::string(")");
                analyzer::info_t detail = {
                    .m_variant = MethodName,
                    .m_raw_variant = MethodName,
                    .m_raw_type = _tmp_type,
                    .m_input = std::move(_input),
                    .m_output = _output,
                    .m_flags = __flags(get_access(Method->getAccess()), flag_const_, flag_virtual_, flag_argument, flag_return_),
                };
                ana.push_back(MethodName, detail);
            }
            {
                analyzer::info_t detail = {
                    .m_variant = MethodName,
                    .m_raw_variant = MethodName,
                    .m_raw_type = "",
                    .m_flags = __flags(get_access(Method->getAccess()), flag_const_, flag_virtual_, flag_function),
                };
                _methods.emplace(MethodName, detail);
            }
        }

        // 嵌套类
        else if (auto Nested = llvm::dyn_cast<CXXRecordDecl>(Member))
        {
            // if (!Nested->isImplicit())
            // {
            //     llvm::outs() << "    - Nested class: " << Nested->getNameAsString() << "\n";
            // }
        }
    }
    for (auto &it : _methods)
    {
        ana.push_back(it.first, it.second);
    }
    format_tpl fmt;
    auto bs = branch_builder(0, ana);
    fmt.to_rfl(bs, ana);
    fmt.to_file(ana, header, source);

    return true;
}
bool GenRflASTVisitor::VisitVarDecl(VarDecl *VD)
{
    if (SM->isInSystemHeader(VD->getLocation()))
    {
        return true;
    }

    if (llvm::dyn_cast<FieldDecl>(VD))
    {
        return true;
    }
#ifdef LLVM_OUT
    llvm::outs() << "Variable: " << VD->getNameAsString() << " (Type: " << VD->getType().getAsString() << ")\n";
#endif
    return true;
}

GenRflASTConsumer::GenRflASTConsumer(ASTContext *Context) : Visitor(Context)
{
}

void GenRflASTConsumer::HandleTranslationUnit(ASTContext &Context)
{
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
}

std::unique_ptr<ASTConsumer> GetRflFrontendAction::CreateASTConsumer(CompilerInstance &CI, StringRef File)
{
    return std::make_unique<GenRflASTConsumer>(&CI.getASTContext());
}