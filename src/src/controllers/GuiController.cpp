#include "controllers/GuiController.h"
#include "factories/RotationFilterFactory.h"

#include <iostream>

namespace controllers {

    void GuiController::updateModel(AugumentationData data) {
        auto factory = std::make_unique<factories::RotationFilterFactory>();
        auto rotationItem = factory->createFilter(data);
        std::cout << "Call Ok Update!" << data.selectedRotation;
    }

    void GuiController::clearModel() {
        std::cout << "Call Ok Clear!";
    }

    void GuiController::okButton() {
        std::cout << "Call Ok!";
    }
}