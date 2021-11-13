#include "controllers/GuiController.h"
#include "factories/RotationFilterFactory.h"
#include "spdlog/spdlog.h"

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

    void GuiController::okButton(std::function<void(std::string)>& statusCallback) {
        spdlog::info("call ok");
        mAugment.start(mPathImages, mModel);
        statusCallback("Finished");
    }

    GuiController::GuiController() {
        mModel = std::make_unique<models::OperationModel<filters::IFilterCommand>>();
    }
}// namespace controllers