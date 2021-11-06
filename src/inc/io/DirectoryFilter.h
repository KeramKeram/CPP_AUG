#pragma once

#include <string>
#include <vector>

namespace io {
class DirectoryFilter {
public:
    std::vector<std::string> filterByExtension(std::vector<std::string> files);
};
}