#include "io/Directory.h"
#include "spdlog/spdlog.h"

#include <algorithm>
#include <filesystem>

namespace io {

    std::vector<std::string>
    Directory::loadFilesList(std::string &pathToDir) {
        std::filesystem::path systemPath{pathToDir};
        if (!std::filesystem::exists(systemPath)) {
            spdlog::error("Directory with files not exist. Return empty vector!");
            return std::vector<std::string>();
        }
        std::vector<std::string> filesList;
        for (const auto & elem: std::filesystem::directory_iterator(systemPath)) {
            std::filesystem::file_status fs{std::filesystem::status(elem)};
            if (std::filesystem::is_regular_file(fs)) {
                filesList.emplace_back(elem.path().string());
            }
        }
        return filesList;
    }
}// namespace io