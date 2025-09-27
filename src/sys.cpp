#include "sys.h"
#include <string>
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
    std::string_view _base_file = baseFile;
    std::string_view _target_path = targetPath;
    if (!_base_file.empty() && _base_file.back() == '/')
    {
        _base_file.remove_suffix(1);
    }
    if (!_target_path.empty() && _target_path.back() == '/')
    {
        _target_path.remove_suffix(1);
    }

    if (_base_file.empty())
    {
        return std::string(_target_path);
    }

    size_t commonComponents = findCommonPrefixLength(_base_file, _target_path);

    size_t upLevels = 0;
    size_t pos = 0;
    std::string_view remainingBase = _base_file.front() == '/' ? _base_file.substr(1) : _base_file;

    for (size_t i = 0; i < commonComponents; i++)
    {
        size_t pos = remainingBase.find('/');
        if (pos == std::string_view::npos)
        {
            remainingBase = "";
            break;
        }
        else
        {
            remainingBase = remainingBase.substr(pos + 1);
        }
    }

    forEachPathComponent(remainingBase, [&upLevels](std::string_view)
                         { upLevels++; });

    std::string relativePath;
    for (size_t i = 0; i < upLevels; i++)
    {
        if (!relativePath.empty())
        {
            relativePath += '/';
        }
        relativePath += "..";
    }

    std::string_view _remaining_target = _target_path;
    pos = _target_path.front() == '/' ? 1 : 0;

    for (size_t i = 0; i < commonComponents; i++)
    {
        pos = _remaining_target.find('/', pos);
        if (pos == std::string_view::npos)
        {
            pos = _remaining_target.length();
            break;
        }
        pos = pos + 1;
    }

    _remaining_target = _target_path.substr(pos);
    if (!_remaining_target.empty())
    {
        if (!relativePath.empty())
        {
            relativePath += '/';
        }
        relativePath += _remaining_target;
    }

    if (relativePath.empty())
    {
        return ".";
    }

    return relativePath;
}
