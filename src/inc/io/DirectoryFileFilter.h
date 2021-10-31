#pragma once

#include <string>
#include <vector>

namespace io {
    class DirectoryFileFilter {
    public:
        std::vector<std::string> filterByExtension(std::string &pathToDir, std::string &extension);
    };
}