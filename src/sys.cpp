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

#include "sys.h"
#include <string>
#include <string_view>
#include <cstring>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>

bool __mkdir(const std::string &path)
{
    struct stat file_stat;
    if (stat(path.data(), &file_stat) == 0)
    {
        if (S_ISDIR(file_stat.st_mode))
        {
            return true;
        }
        if (S_ISREG(file_stat.st_mode))
        {
            return false;
        }
    }
    if (errno == EACCES)
    {
        return false;
    }
    auto pos = path.find_last_of("/");
    if (pos == std::string::npos)
    {
        std::cout << "create path " << path << std::endl;
        return mkdir(path.data(), 0755) == 0;
    }
    auto upper = path.substr(0, pos);
    if (!__mkdir(upper))
    {
        return false;
    }
    std::cout << "create path " << path << std::endl;
    return mkdir(path.data(), 0755) == 0;
};
int MkDir(const std::string &path)
{
    auto r = __mkdir(path);
    return r ? 0 : -1;
}

void TraverseDir(const std::string &path, const std::function<void(const std::string &path)> &func)
{
    DIR *dir = opendir(path.c_str());
    if (dir == nullptr)
    {
        perror("无法打开目录");
        return;
    }

    dirent *entry;
    while ((entry = readdir(dir)) != nullptr)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }
        auto slash = path.back() == '/' ? "" : "/";
        std::string fullPath = path + slash + entry->d_name;

        struct stat statBuf;
        if (stat(fullPath.c_str(), &statBuf) == 0)
        {
            if (S_ISREG(statBuf.st_mode))
            {
                func(fullPath);
            }
            else if (S_ISDIR(statBuf.st_mode))
            {
                TraverseDir(fullPath, func);
            }
        }
    }

    closedir(dir);
}

std::chrono::system_clock::time_point GetFileModified(const std::string &path)
{

    struct stat file_stat;
    if (stat(path.c_str(), &file_stat) != 0)
    {
        return std::chrono::system_clock::time_point::min();
    }
    return std::chrono::system_clock::from_time_t(file_stat.st_mtime);
}

std::string SplitFile(const std::string &str)
{
    auto pos = str.find_last_of("/");
    if (pos == std::string::npos)
    {
        return str;
    }
    return str.substr(pos + 1);
}

template <typename F>
void forEachPathComponent(std::string_view path, F &&callback)
{
    size_t start = 0;
    size_t end = 0;
    const size_t length = path.length();

    while (start < length)
    {
        while (start < length && path[start] == '/')
        {
            start++;
        }
        if (start >= length)
        {
            break;
        }
        end = path.find('/', start);
        if (end == std::string_view::npos)
        {
            end = length;
        }

        std::string_view component = path.substr(start, end - start);
        if (!component.empty())
        {
            std::forward<F>(callback)(component);
        }

        start = end + 1;
    }
}

size_t findCommonPrefixLength(std::string_view basePath, std::string_view targetPath)
{
    size_t commonComponents = 0;
    size_t basePos = 0;
    size_t targetPos = 0;
    auto baseLen = basePath.length();
    auto targetLen = targetPath.length();

    while (basePos < baseLen && targetPos < targetLen)
    {
        while (basePos < baseLen && basePath[basePos] == '/')
        {
            basePos++;
        }
        while (targetPos < targetLen && targetPath[targetPos] == '/')
        {
            targetPos++;
        }

        size_t baseEnd = basePath.find('/', basePos);
        std::string_view baseComp = baseEnd != std::string_view::npos ? basePath.substr(basePos, baseEnd - basePos) : basePath.substr(basePos);

        size_t targetEnd = targetPath.find('/', targetPos);
        std::string_view targetComp = targetEnd != std::string_view::npos ? targetPath.substr(targetPos, targetEnd - targetPos) : targetPath.substr(targetPos);

        if (baseComp != targetComp)
        {
            break;
        }

        commonComponents++;
        basePos = baseEnd + 1;
        targetPos = targetEnd + 1;
    }

    return commonComponents;
}

std::string GetRelativePath(const std::string &baseFile, const std::string &targetPath)
{
    std::string base_dir = baseFile;
    size_t pos = base_dir.find_last_of('/');
    if (pos != std::string::npos) {
        base_dir = base_dir.substr(0, pos);
    }

    std::string relative_path;
    std::string current_dir = base_dir;
    std::string target_file = targetPath;
    
    // 确保路径使用正斜杠
    std::replace(current_dir.begin(), current_dir.end(), '\\', '/');
    std::replace(target_file.begin(), target_file.end(), '\\', '/');
    
    // 移除路径中的 ./ 前缀和中间的 /./
    auto remove_dot_slashes = [](std::string &path) {
        std::string result;
        std::stringstream ss(path);
        std::string component;
        while (std::getline(ss, component, '/')) {
            if (component == ".") {
                continue;
            }
            if (!result.empty()) {
                result += "/";
            }
            result += component;
        }
        return result;
    };
    
    current_dir = remove_dot_slashes(current_dir);
    target_file = remove_dot_slashes(target_file);
    
    // 分割路径为组件
    std::vector<std::string> base_components;
    std::vector<std::string> target_components;
    
    std::stringstream base_ss(current_dir);
    std::string component;
    while (std::getline(base_ss, component, '/')) {
        if (!component.empty()) {
            base_components.push_back(component);
        }
    }
    
    std::stringstream target_ss(target_file);
    while (std::getline(target_ss, component, '/')) {
        if (!component.empty()) {
            target_components.push_back(component);
        }
    }
    
    // 找到公共前缀
    size_t common_prefix = 0;
    while (common_prefix < base_components.size() && common_prefix < target_components.size() && 
           base_components[common_prefix] == target_components[common_prefix]) {
        common_prefix++;
    }
    
    // 向上一级目录的次数
    for (size_t i = common_prefix; i < base_components.size(); i++) {
        relative_path += "../";
    }
    
    // 添加目标路径的剩余部分
    for (size_t i = common_prefix; i < target_components.size(); i++) {
        if (!relative_path.empty() && relative_path.back() != '/') {
            relative_path += "/";
        }
        relative_path += target_components[i];
    }
    
    return relative_path;
}

bool IsCurDir(const std::string &path)
{
    return path == "." || path == "./" || path == "";
}

bool IsExist(const std::string &path)
{
    struct stat buffer;
    return stat(path.c_str(), &buffer) == 0;
}