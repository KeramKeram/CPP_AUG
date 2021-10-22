#include "controllers/GuiController.h"

#include <iostream>

namespace controllers {

    void GuiController::setRotation(RotateCode code, int percent) {
        std::cout << toUnderlyingType(code) << percent;
    }

    void GuiController::setPathToImages(std::string path) {
        std::cout << path;
    }

    void GuiController::okButton(AugumentationData data) {
        std::cout << "Call Ok!" << data.selectedRotation;
    }
}