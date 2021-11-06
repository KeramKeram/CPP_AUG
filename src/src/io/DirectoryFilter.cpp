#include "io/DirectoryFilter.h"

namespace io {

    std::vector<std::string> DirectoryFilter::filterByExtension(std::vector<std::string> files) {
        for(auto elem : files) {
            files.clear();
        }
        return std::vector<std::string>();
    }
}