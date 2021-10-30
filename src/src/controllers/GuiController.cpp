#include "controllers/GuiController.h"
#include "factories/RotationFilterFactory.h"
#include "spdlog/spdlog.h"


namespace controllers {

    void GuiController::createFilters(AugumentationData data) {
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
        spdlog::info("call ok");
    }

    GuiController::GuiController() {
        mModel = std::make_unique<models::OperationModel<filters::IFilterCommand>>();
    }
}