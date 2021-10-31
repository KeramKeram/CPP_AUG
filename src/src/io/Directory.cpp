#include "io/Directory.h"
#include "spdlog/spdlog.h"

#include <filesystem>

namespace io {

    std::vector<std::string>
    Directory::loadFileListByExtension(std::string &pathToDir, std::string &extension) {
        std::filesystem::path systemPath{pathToDir};
        if (!std::filesystem::exists(systemPath)) {
            spdlog::error("Directory with files not exist. Return empty vector!");
            return std::vector<std::string>();
        }
        std::vector<std::string> fileList;

        return std::vector<std::string>();
    }
}