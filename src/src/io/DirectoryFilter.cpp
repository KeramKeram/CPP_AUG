#include "io/DirectoryFilter.h"

#include <algorithm>
#include <filesystem>

namespace io {

    std::vector<std::string> DirectoryFilter::filterByExtension(std::vector<std::string> files, const std::vector<std::string> &extensions) {
        for (const auto &extension : extensions) {
            auto noSpacEnd = std::remove_if(files.begin(), files.end(), [extension = extension](auto file) {
                using namespace std::filesystem;
                path filePath(file);
                if (auto ex = filePath.extension(); ex.empty() || ex.u8string().compare(extension) != 0) {
                    return true;
                }
                return false;
            });
            files.erase(noSpacEnd, files.end());
        }
        return files;
    }
}// namespace io