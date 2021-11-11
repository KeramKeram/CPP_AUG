#include "controllers/AugumentationFacade.h"
#include "io/Directory.h"
#include "io/DirectoryFilter.h"
#include "io/LoadOpencvImg.h"

namespace controllers {

    AugumentationFacade::AugumentationFacade(
            const std::string &imgPath, std::shared_ptr<models::OperationModel<filters::IFilterCommand>> filterModel)
        : mImagesPath(imgPath), mModel(filterModel) {}

    void AugumentationFacade::runAugmentation() {
        auto files = io::Directory::loadFilesList(mImagesPath);
        files = io::DirectoryFilter::filterByExtension(files, {".jpg", ".png"});
        io::LoadOpencvImg loader;
        for (const auto& path: files) {
            auto img = loader.loadImage(path);

        }
    }
}// namespace controllers