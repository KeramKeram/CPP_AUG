#include "io/Directory.h"
#include "spdlog/spdlog.h"

#include <filesystem>
#include <sstream>

namespace io {

    std::vector<std::string>
    Directory::loadFilesList(std::string &pathToDir) {
        std::filesystem::path systemPath{pathToDir};
        if (!std::filesystem::exists(systemPath)) {
            spdlog::error("Directory with files not exist. Return empty vector!");
            return std::vector<std::string>();
        }
        std::vector<std::pair<bool, std::string>> elementList;
        std::transform(std::filesystem::directory_iterator(systemPath), {}, std::back_inserter(elementList),
                       [](const std::filesystem::directory_entry &de) {
            std::filesystem::file_status fs{std::filesystem::status(de)};
            return std::pair<bool, std::string>{std::filesystem::is_regular_file(fs),de.path().string()}; });
        elementList.erase(std::remove_if(elementList.begin(), elementList.end(), [](const auto &elem) {
            return !elem.first;
        }));

        std::vector<std::string> filesList;
        std::transform(elementList.begin(), elementList.end(), std::back_inserter(filesList),
                       [](const auto &elem) { return elem.second; });

        return filesList;
    }
}// namespace io