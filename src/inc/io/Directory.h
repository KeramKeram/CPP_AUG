#pragma once

#include <string>
#include <vector>
#include <filesystem>

namespace io {
    class Directory {
    public:
        std::vector<std::string> loadFileListByExtension(std::string &pathToDir, std::string &extension);

    };
}