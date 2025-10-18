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
