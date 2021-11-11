#include "controllers/AugumentationFacade.h"
#include "io/Directory.h"
#include "io/DirectoryFilter.h"
#include "io/LoadOpencvImg.h"
#include "io/SaveOpencvImg.h"
#include "spdlog/spdlog.h"


namespace controllers {

    AugumentationFacade::AugumentationFacade(
            const std::string &imgPath, std::shared_ptr<models::OperationModel<filters::IFilterCommand>> filterModel)
        : mImagesPath(imgPath), mModel(filterModel) {}

    void AugumentationFacade::runAugmentation() {
        auto files = io::Directory::loadFilesList(mImagesPath);
        files = io::DirectoryFilter::filterByExtension(files, {".jpg", ".png"});
        io::LoadOpencvImg loader;
        io::SaveImage saver;
        for (const auto& path: files) {
            spdlog::warn(path);
            auto img = loader.loadImage(path);

            while(mModel->hasNext()) {
                auto filter = mModel->next();
                auto augumentImg = filter->execute(img);
                saver.saveImageOCV(augumentImg, path + "_1");
            }
            mModel->resetIterator();
        }
    }
}// namespace controllers