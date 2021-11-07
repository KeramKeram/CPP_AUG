#include "controllers/GuiController.h"
#include "factories/RotationFilterFactory.h"
#include "io/Directory.h"
#include "io/DirectoryFilter.h"
#include "spdlog/spdlog.h"

#include <iostream>
namespace controllers {

    void GuiController::createFilters(AugumentationData data) {
        mModel = std::make_shared<models::OperationModel<filters::IFilterCommand>>();
        auto factory = std::make_unique<factories::RotationFilterFactory>();
        mModel->add(factory->createFilter(data));
    }

    void GuiController::setPathToImages(const std::string &path) {
        GuiController::mPathImages = path;
    }

    void GuiController::clearModel() {
        mModel->clear();
    }

    void GuiController::okButton() {
        auto files = io::Directory::loadFilesList(mPathImages);
        files = io::DirectoryFilter::filterByExtension(files, {".jpg", ".png"});
        spdlog::info("call ok");
    }

    GuiController::GuiController() {
        mModel = std::make_unique<models::OperationModel<filters::IFilterCommand>>();
    }
}// namespace controllers