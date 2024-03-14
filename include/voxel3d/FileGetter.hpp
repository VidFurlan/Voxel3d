#ifndef FILE_GETTER_H
#define FILE_GETTER_H

#include <fstream>
#include <string>

class FileGetter {
public:
    FileGetter(const std::string& rootPath) : root(rootPath) {}

    std::string GetFilePath(const std::string& path) const {
        return root + '/' + path;
    }

    bool FileExists(const std::string& path) const {
        std::string filePath = GetFilePath(path);
        std::ifstream file(filePath);
        return file.good();
    }

private:
    std::string root;
};
#endif
