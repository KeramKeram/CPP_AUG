#include "controllers/GuiController.h"
#include "factories/RotationFilterFactory.h"

#include <iostream>

namespace controllers {

    void GuiController::updateModel(AugumentationData data) {
        auto factory = std::make_unique<factories::RotationFilterFactory>();
        mModel->add(factory->createFilter(data));
    }

    void GuiController::clearModel() {
        std::cout << "Call Ok Clear!";
    }

    void GuiController::okButton() {
        std::cout << "Call Ok!";
    }

    GuiController::GuiController() {
        mModel = std::make_unique<models::OperationModel<filters::IFilterCommand>>();
    }
}