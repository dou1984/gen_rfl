// Copyright (c) 2023-2025 Zhao Yun Shan
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
#include "analyzer.h"
#include "format_tpl.h"
#include "branch.h"
#include "reflect.h"
#include "filter.h"
#include "config.h"
#include "gen_rfl.h"
#include "travel_src.h"

// #define LLVM_OUT
namespace reflect
{

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
            return flag_member;
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

    bool HasConst(const std::string &type)
    {
        constexpr char _const[] = "const ";
        return type.compare(0, sizeof(_const) - 1, _const) == 0;
    }
    std::string RemoveExtents(const std::string &type)
    {
        std::string_view view = type;
        if (HasConst(type))
        {
            view = view.substr(6);
        }
        constexpr char _ampersand[] = "&";
        auto l = view.size();
        if (l > 0)
        {
            if (view.compare(l - 1, l, _ampersand) == 0)
            {
                view = view.substr(0, l - 2);
            }
        }
        return std::string(view.data(), view.size());
    }
    bool GetNamespaces(CXXRecordDecl *D, std::string &NamespaceName)
    {

        DeclContext *Context = D->getDeclContext();
        while (Context && !Context->isTranslationUnit())
        {
            if (auto *NS = dyn_cast<NamespaceDecl>(Context))
            {
                std::string Part = NS->getNameAsString();
                if (Part == "std")
                {
                    Part = "";
                }
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

#ifdef ALPINE
#define TTK_Class TagTypeKind::Class
#define TTK_Struct TagTypeKind::Struct
#define TTK_Union TagTypeKind::Union
#endif
    bool GetRawClass(CXXRecordDecl *D)
    {
        switch (D->getTagKind())
        {
        case TTK_Class:
            ::reflect::get_config().m_raw_class = "class " + ::reflect::get_config().m_class;
            return true;
        case TTK_Struct:
            ::reflect::get_config().m_raw_class = "struct " + ::reflect::get_config().m_class;
            return true;
        case TTK_Union:
            ::reflect::get_config().m_raw_class = "union " + ::reflect::get_config().m_class;
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
            std::cerr << "Name: " << Name << "BaseTypeName: " << BaseTypeName << std::endl;
            return false;
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
        ::reflect::get_config().clear();
        ::reflect::get_config().m_file = FileName;
        ::reflect::get_config().m_class = D->getNameAsString();
        if (!GetNamespaces(D, ::reflect::get_config().m_namespace))
        {
            return false;
        }

        auto ana_config = std::make_shared<analyzer::config_t>();
        branch_info bra;
        bra.ana().init(ana_config);

        std::map<std::string, branch_info> bra_func;
        auto ana_config_func = std::make_shared<analyzer::config_t>();

        std::string header, source;
        if (is_generated(header, source))
        {
            std::cout << "skip " << FileName << ":" << ::reflect::get_config().m_raw_class << " is generated." << std::endl;
            return true;
        }

        if (!GetRawClass(D))
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
                    auto flag_virtual_ = Base.isVirtual() ? flag_virtual : flag_member;
                    auto detail = std::make_shared<analyzer::info_t>();
                    detail->m_variant = BaseTypeName;
                    detail->m_raw_variant = BaseTypeName;
                    detail->m_raw_type = BaseTypeName;
                    detail->m_flags = __flags(flag_object_type, get_access(Base.getAccessSpecifier()), flag_virtual_);

                    bra.ana().push_back(BaseTypeName, detail);
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
                    auto detail = std::make_shared<analyzer::info_t>();
                    detail->m_raw_variant = Name;
                    detail->m_raw_type = BaseTypeName;
                    detail->m_flags = __flags(get_access(FD->getAccess()), flag_const_, flag_volatile_);

                    bra.ana().push_back(Name, detail);

                    insert_base_types(BaseTypeName);
                }
                else
                {
                    auto detail = std::make_shared<analyzer::info_t>();
                    detail->m_raw_variant = Name;
                    detail->m_raw_type = TypeName;
                    detail->m_flags = __flags(get_access(FD->getAccess()), flag_const_, flag_volatile_);

                    bra.ana().push_back(Name, detail);

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
                    auto detail = std::make_shared<analyzer::info_t>();
                    detail->m_raw_variant = Name;
                    detail->m_raw_type = BaseTypeName;
                    detail->m_flags = __flags(get_access(VD->getAccess()), flag_const_, flag_volatile_, flag_static);

                    bra.ana().push_back(Name, detail);

                    insert_base_types(BaseTypeName);
                }
                else
                {

                    auto detail = std::make_shared<analyzer::info_t>();
                    detail->m_raw_variant = Name;
                    detail->m_raw_type = TypeName;
                    detail->m_flags = __flags(get_access(VD->getAccess()), flag_const_, flag_volatile_, flag_static);

                    bra.ana().push_back(Name, detail);

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
                auto flag_const_ = Method->isConst() ? flag_const : flag_member;
                auto flag_virtual_ = Method->isVirtual() ? flag_virtual : flag_member;

                std::list<std::string> _input;
                // auto i = 0;
                // uint32_t _t_flags = 0;
                auto parameters = Method->parameters();
                for (auto &Param : parameters)
                {
                    auto [FieldType, UnqualifiedType] = get_type_name(Param);
                    auto _field_type = FieldType.getAsString();
                    _input.push_back(RemoveExtents(_field_type));
                    // if (HasConst(_field_type))
                    // {
                    //     _t_flags |= __flag(i++);
                    // }
                    // auto _unqualified_type = UnqualifiedType.getAsString();
                    // insert_base_types(RemoveExtents(_unqualified_type));
                }

                {
                    std::string _output = Method->getReturnType().getAsString();
                    if (_output == "void")
                    {
                        _output = "";
                    }
                    else
                    {
                        auto _tmp_type = _output + std::string("@") + join(_input, ",");
                        auto detail = std::make_shared<analyzer::info_t>();
                        detail->m_variant = _tmp_type;
                        detail->m_raw_variant = MethodName;
                        detail->m_raw_type = _tmp_type;
                        detail->m_input = _input;
                        detail->m_output = _output;
                        detail->m_flags = __flags(get_access(Method->getAccess()), flag_const_, flag_virtual_, flag_argument);
                        // detail->m_t_flags = _t_flags;

                        bra_func[MethodName].ana().init(ana_config_func).push_back(_tmp_type, detail);
                    }
                    {
                        auto _tmp_type = std::string("@") + join(_input, ",");
                        auto detail = std::make_shared<analyzer::info_t>();
                        detail->m_variant = _tmp_type;
                        detail->m_raw_variant = MethodName;
                        detail->m_raw_type = _tmp_type;
                        detail->m_input = _input;
                        detail->m_output = "";
                        detail->m_flags = __flags(get_access(Method->getAccess()), flag_const_, flag_virtual_, flag_argument);
                        // detail->m_t_flags = _t_flags;

                        bra_func[MethodName].ana().init(ana_config_func).push_back(_tmp_type, detail);
                    }
                }

                if (auto it = bra.ana().get_data().find(MethodName); it == bra.ana().get_data().end())
                {
                    auto detail = std::make_shared<analyzer::info_t>();
                    detail->m_variant = MethodName;
                    detail->m_raw_variant = MethodName;
                    detail->m_raw_type = "";
                    detail->m_flags = __flags(get_access(Method->getAccess()), flag_const_, flag_virtual_, flag_function);

                    bra.ana().push_back(MethodName, detail);
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

        format_tpl fmt;

        fmt.to_rfl(bra, bra_func);
        fmt.to_file(header, source);

        ::reflect::get_config().save();
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
}