#include "common/NameGenerators.h"
#include "controllers/AugumentationFacade.h"
#include "io/Directory.h"
#include "io/DirectoryFilter.h"
#include "io/LoadOpencvImg.h"
#include "io/SaveOpencvImg.h"
#include "spdlog/spdlog.h"

#include <filesystem>
#include <string>


namespace controllers {
    constexpr char subFolder[] = "output";

    AugumentationFacade::AugumentationFacade(
            const std::string &imgPath, std::shared_ptr<models::OperationModel<filters::IFilterCommand>> filterModel)
        : mImagesPath(imgPath), mModel(filterModel) {}

    void AugumentationFacade::runAugmentation() {
        std::filesystem::create_directory(mImagesPath + "/" + subFolder);
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
            saver.saveImageOCV(augumentImg, common::generateNewRandomFilePath(subFolder, path));
        }
        mModel->resetIterator();
    }

}// namespace controllers