#include "common/NameGenerators.h"

#include <chrono>
#include <filesystem>
#include <random>
#include <sstream>
#include <string>

namespace common {
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;
    using std::chrono::seconds;
    using std::chrono::system_clock;

    std::string generateNewRandomFilePath(const std::string &subFolder, const std::string &filePath) {
        auto millisec_since_epoch =
                std::chrono::duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 10000);
        std::filesystem::path currentPath(filePath);
        std::string parentDir = currentPath.parent_path().u8string();
        std::string fileName = currentPath.filename().u8string();
        std::stringstream ss;
        ss << parentDir << "/" << subFolder << "/" << std::to_string(millisec_since_epoch)
           << std::to_string(distrib(gen)) << fileName;
        return ss.str();
    }
}// namespace common