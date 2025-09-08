#pragma once
#include <string>
#include <chrono>
#include <functional>

int MkDir(const std::string &path);

void TraverseDir(const std::string &path, const std::function<void(const std::string &path)> &);

std::chrono::system_clock::time_point GetFileModified(const std::string &path);

std::string SplitFile(const std::string &str);

std::string GetRelativePath(const std::string& basePath, const std::string& targetPath);