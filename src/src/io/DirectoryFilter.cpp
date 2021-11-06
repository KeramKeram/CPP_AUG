#include "io/DirectoryFilter.h"

#include <algorithm>
#include <filesystem>

namespace io {

    std::vector<std::string> DirectoryFilter::filterByExtension(std::vector<std::string> files, const std::vector<std::string> &extensions) {
        std::vector<std::string> output;
        for (const auto &extension : extensions) {
            std::copy_if(files.begin(), files.end(),std::back_inserter(output), [extension = extension](auto file) {
                using namespace std::filesystem;
                path filePath(file);
                if (auto ex = filePath.extension(); ex.empty() || ex.u8string().compare(extension) != 0) {
                    return false;
                }
                return true;
            });
        }
        return output;
    }
}// namespace io