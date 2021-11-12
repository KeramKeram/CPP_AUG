#include "controllers/AugumentationFacade.h"
#include "io/Directory.h"
#include "io/DirectoryFilter.h"
#include "io/LoadOpencvImg.h"
#include "io/SaveOpencvImg.h"
#include "spdlog/spdlog.h"

#include <chrono>
#include <filesystem>
#include <random>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

namespace controllers {

    AugumentationFacade::AugumentationFacade(
            const std::string &imgPath, std::shared_ptr<models::OperationModel<filters::IFilterCommand>> filterModel)
        : mImagesPath(imgPath), mModel(filterModel) {}

    void AugumentationFacade::runAugmentation() {
        std::filesystem::create_directory(mImagesPath + "/output");
        auto files = io::Directory::loadFilesList(mImagesPath);
        files = io::DirectoryFilter::filterByExtension(files, {".jpg", ".png"});
        io::LoadOpencvImg loader;
        io::SaveImage saver;
        for (const auto &path : files) { augumentImages(loader, saver, path); }
    }

    void AugumentationFacade::augumentImages(io::LoadOpencvImg &loader, io::SaveImage &saver, const std::string &path) {
        auto img = loader.loadImage(path);
        while (mModel->hasNext()) {
            auto filter = mModel->next();
            auto augumentImg = filter->execute(img);
            saver.saveImageOCV(augumentImg, generateFileName(path));
        }
        mModel->resetIterator();
    }

    std::string AugumentationFacade::generateFileName(const std::string &path) const {
        auto millisec_since_epoch =
                std::chrono::duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 10000);
        std::filesystem::path filePath(path);
        std::string parentDir = filePath.parent_path().u8string();
        std::string fileName = filePath.filename().u8string();
        std::stringstream ss;
        ss << parentDir << "/output/" << std::to_string(millisec_since_epoch) << std::to_string(distrib(gen))
           << fileName;
        spdlog::warn(ss.str());
        return ss.str();
    }
}// namespace controllers