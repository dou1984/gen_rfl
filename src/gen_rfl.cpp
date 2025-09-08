#include <iostream>
#include <tuple>
#include <regex>
#include "gen_rfl.h"
#include "analyzer.h"
#include "format_tpl.h"
#include "branch.h"
#include "reflect.h"
#include "filter.h"
#include "config.h"

// #define LLVM_OUT
using namespace reflect;
std::tuple<QualType, QualType> get_type_name(FieldDecl *FD)
{
    QualType FieldType = FD->getType();

    // 获取去修饰后的类型（原始类型）
    QualType CanonicalType = FieldType.getCanonicalType();
    QualType UnqualifiedType = CanonicalType.getUnqualifiedType();

    // 处理指针和引用
    while (true)
    {
        if (UnqualifiedType->isPointerType())
        {
            UnqualifiedType = UnqualifiedType->getPointeeType();
        }
        else if (UnqualifiedType->isReferenceType())
        {
            UnqualifiedType = UnqualifiedType->getPointeeType();
        }
        else
        {
            break;
        }
    }
    return {FieldType, UnqualifiedType};
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
    analyzer ana;
    auto &conf = ana.get_config();
    conf.clear();
    conf.m_file = FileName;
    conf.m_class = D->getNameAsString();

    std::string header, source;
    if (ana.is_generated(header, source))
    {
        std::cout << "Skip " << FileName << ": " << conf.m_class << " is generated." << std::endl;
        return true;
    }

    switch (D->getTagKind())
    {
    case TTK_Class:
        conf.m_raw_class = "class " + conf.m_class;
        break;
    case TTK_Struct:
        conf.m_raw_class = "struct " + conf.m_class;
        break;
    case TTK_Union:
        conf.m_raw_class = "union " + conf.m_class;
        break;
    default:
        exit(1);
    }
    if (D->hasDefinition())
    {
        if (D->getNumBases() > 0)
        {
#ifdef LLVM_OUT
            llvm::outs() << "  Base Classes:\n";
#endif
            for (const auto &Base : D->bases())
            {
                QualType BaseType = Base.getType();
                auto Name = BaseType.getAsString();
                std::string BaseTypeName;
                auto flag = 0;
                if (Name.find("struct ") == 0)
                {
                    flag = flag_struct;
                    BaseTypeName = Name.substr(7);
                }
                else if (Name.find("class ") == 0)
                {
                    flag = flag_class;
                    BaseTypeName = Name.substr(6);
                }
                else
                {
                    throw std::runtime_error("Unsupported base class type.");
                }
                analyzer::info_t detail = {
                    .m_variant = BaseTypeName,
                    .m_raw_variant = BaseTypeName,
                    .m_type = BaseTypeName,
                    .m_raw_type = BaseTypeName,
                    .m_flags = __flags(flag),
                };
                ana.push_back(BaseTypeName, detail);
#ifdef LLVM_OUT
                llvm::outs() << "    - " << BaseTypeName;
                // Print access specifier
                switch (Base.getAccessSpecifier())
                {
                case AS_public:
                    llvm::outs() << " (public)";
                    break;
                case AS_protected:
                    llvm::outs() << " (protected)";
                    break;
                case AS_private:
                    llvm::outs() << " (private)";
                    break;
                case AS_none:
                    break;
                }

                // Print if virtual inheritance is used
                if (Base.isVirtual())
                {
                    llvm::outs() << " [virtual]";
                }

                llvm::outs() << "\n";
#endif
            }
        }
    }
    // 获取打印策略
    PrintingPolicy PP(D->getASTContext().getLangOpts());

    // 遍历类的成员
    for (auto Member : D->decls())
    {
        // 成员变量
        if (FieldDecl *FD = llvm::dyn_cast<FieldDecl>(Member))
        {

            auto [FieldType, UnqualifiedType] = get_type_name(FD);
            auto TypeName = FieldType.getAsString();
            auto Name = FD->getNameAsString();
            if (UnqualifiedType->isBuiltinType())
            {
                const BuiltinType *BT = UnqualifiedType->getAs<BuiltinType>();
                auto BaseTypeName = BT->getName(PP).str();
                analyzer::info_t detail = {
                    .m_raw_variant = Name,
                    .m_type = TypeName,
                    .m_raw_type = BaseTypeName,
                };
                ana.push_back(Name, detail);
#ifdef LLVM_OUT
                llvm::outs() << "    - Field: " << FD->getNameAsString() << " (Type: " << TypeName << ", Base Type: " << BaseTypeName << ")\n";
#endif
            }
            else
            {
                analyzer::info_t detail = {
                    .m_raw_variant = Name,
                    .m_type = TypeName,
                    .m_raw_type = TypeName,
                };
                ana.push_back(Name, detail);
#ifdef LLVM_OUT
                llvm::outs() << "    - Field: " << FD->getNameAsString() << " (Type: " << TypeName << ")\n";
#endif
            }
#ifdef LLVM_OUT
        }
        // 成员函数（保持不变）
        else if (CXXMethodDecl *Method = llvm::dyn_cast<CXXMethodDecl>(Member))
        {
            if (Method->isImplicit())
                continue;

            llvm::outs() << "    - Method: " << Method->getNameAsString();
            if (Method->isConst())
            {
                llvm::outs() << " [const]";
            }
            if (Method->isVirtual())
            {
                llvm::outs() << " [virtual]";
            }
            llvm::outs() << "\n";

            // 打印参数列表
            llvm::outs() << "        Parameters: ";
            for (unsigned i = 0, e = Method->getNumParams(); i != e; ++i)
            {
                ParmVarDecl *Parm = Method->getParamDecl(i);
                if (i != 0)
                    llvm::outs() << ", ";
                llvm::outs() << Parm->getType().getAsString() << " " << Parm->getNameAsString();
            }
            llvm::outs() << "\n";

            // 打印返回类型
            llvm::outs() << "        Return type: " << Method->getReturnType().getAsString() << "\n";
        }
        // 嵌套类
        else if (CXXRecordDecl *Nested = llvm::dyn_cast<CXXRecordDecl>(Member))
        {
            if (!Nested->isImplicit())
            {
                llvm::outs() << "    - Nested class: " << Nested->getNameAsString() << "\n";
            }
#endif
        }
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