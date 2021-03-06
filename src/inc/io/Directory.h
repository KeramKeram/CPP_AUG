#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace io {
    class Directory {
    public:
        static std::vector<std::string> loadFilesList(std::string &pathToDir);
    };
}// namespace io