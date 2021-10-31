#include "io/DirectoryFileFilter.h"

#include <filesystem>

namespace io {

    std::vector<std::string> DirectoryFileFilter::filterByExtension(std::string &pathToDir, std::string &extension) {
        std::filesystem::path systemPath{pathToDir};
        if (!std::filesystem::exists(systemPath)) {

        }
        extension.clear();
        return std::vector<std::string>();
    }
}