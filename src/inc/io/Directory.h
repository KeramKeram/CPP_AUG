#pragma once

#include <string>
#include <vector>
#include <filesystem>

namespace io {
    class Directory {
    public:
        std::vector<std::string> loadFilesList(std::string &pathToDir);

    };
}