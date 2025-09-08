#pragma once
#include <memory>
#include <clang/AST/ASTConsumer.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/Tooling/Tooling.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/raw_ostream.h>
#include <clang/Tooling/CompilationDatabase.h>

using namespace clang;

class GenRflASTVisitor : public RecursiveASTVisitor<GenRflASTVisitor>
{
public:
    explicit GenRflASTVisitor(ASTContext *Context);

    // 访问函数声明
    bool VisitFunctionDecl(FunctionDecl *FD);

    bool VisitCXXRecordDecl(CXXRecordDecl *D);

    bool VisitVarDecl(VarDecl *VD);

private:
    SourceManager *SM;
};

class GenRflASTConsumer : public ASTConsumer
{
public:
    explicit GenRflASTConsumer(ASTContext *Context);

    void HandleTranslationUnit(ASTContext &Context) override;

private:
    GenRflASTVisitor Visitor;
};

class GetRflFrontendAction : public ASTFrontendAction
{
public:
    std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI, StringRef File) override;
};
