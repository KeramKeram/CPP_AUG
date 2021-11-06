#pragma once

#include <string>
#include <vector>

namespace io {
class DirectoryFilter {
public:
    static std::vector<std::string> filterByExtension(const std::vector<std::string> &files, const std::vector<std::string> &extensions);
};
}