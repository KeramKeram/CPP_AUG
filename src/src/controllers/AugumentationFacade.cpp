#include "controllers/AugumentationFacade.h"
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

    AugumentationFacade::~AugumentationFacade() { this->stop(); }

    void AugumentationFacade::start(const std::string &imgPath,
                                    std::shared_ptr<models::OperationModel<filters::IFilterCommand>> filterModel) {
        mImagesPath = imgPath;
        mModel = filterModel;
        this->mTask = std::thread(&AugumentationFacade::runAugmentation, this);
    }

    void AugumentationFacade::stop() {
        mRun.store(false);
        if (mTask.joinable()) { mTask.join(); }
    }

    void AugumentationFacade::runAugmentation() {
        mRun.store(true);
        std::filesystem::create_directory(mImagesPath + "/" + subFolder);
        auto files = io::Directory::loadFilesList(mImagesPath);
        files = io::DirectoryFilter::filterByExtension(files, {".jpg", ".png"});
        io::LoadOpencvImg loader;
        io::SaveImage saver;
        for (const auto &path : files) {
            if (mRun.load() == false) { return; }
            try {
                augumentImages(loader, saver, path);
            } catch (...) {
                spdlog::error("Exception during augment file:" + path);
                std::exception_ptr p = std::current_exception();
                spdlog::error((p ? p.__cxa_exception_type()->name() : "null"));
            };
        }
        mRun.store(false);
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