#include "controllers/AugmentationFacade.h"
#include "common/NameGenerators.h"
#include "io/Directory.h"
#include "io/DirectoryFilter.h"
#include "io/LoadOpencvImg.h"
#include "io/SaveOpencvImg.h"
#include "spdlog/spdlog.h"

#include <filesystem>
#include <string>


namespace controllers {
    constexpr char subFolder[] = "output";

    AugmentationFacade::~AugmentationFacade() { this->stop(); }

    void AugmentationFacade::start(const std::string &imgPath,
                                    std::shared_ptr<models::OperationModel<filters::IFilterCommand>> filterModel,
                                    std::function<void(std::string)> statusCallback) {
        mImagesPath = imgPath;
        mModel = filterModel;
        mStatusCallback = statusCallback;
        this->mTask = std::thread(&AugmentationFacade::runAugmentation, this);
        mTask.detach();
    }

    void AugmentationFacade::stop() {
        mRun.store(false);
        if (mTask.joinable()) { mTask.join(); }
    }

    void AugmentationFacade::runAugmentation() {
        mRun.store(true);
        std::filesystem::create_directory(mImagesPath + "/" + subFolder);
        auto files = io::Directory::loadFilesList(mImagesPath);
        files = io::DirectoryFilter::filterByExtension(files, {".jpg", ".png"});
        io::LoadOpencvImg loader;
        io::SaveImage saver;
        for (const auto &path : files) {
            if (mRun.load() == false) { break; }
            try {
                augmentImages(loader, saver, path);
            } catch (...) {
                spdlog::error("Exception during augment file:" + path);
                std::exception_ptr p = std::current_exception();
                spdlog::error((p ? p.__cxa_exception_type()->name() : "null"));
            };
        }
        mStatusCallback("Finished");
        mRun.store(false);
    }

    void AugmentationFacade::augmentImages(io::LoadOpencvImg &loader, io::SaveImage &saver, const std::string &path) {
        auto img = loader.loadImage(path);
        while (mModel->hasNext()) {
            auto filter = mModel->next();
            auto augmentImg = filter->execute(img);
            saver.saveImageOCV(augmentImg, common::generateNewRandomFilePath(subFolder, path));
        }
        mModel->resetIterator();
    }
    bool AugmentationFacade::getAugmentationStatus() const {
        return mRun.load();
    }
}// namespace controllers