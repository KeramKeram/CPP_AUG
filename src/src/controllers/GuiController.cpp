#include "controllers/GuiController.h"

#include <iostream>

namespace controllers {

    void GuiController::updateModel(AugumentationData data) {
        std::cout << "Call Ok Update!" << data.selectedRotation;
    }

    void GuiController::clearModel() {
        std::cout << "Call Ok Clear!";
    }

    void GuiController::okButton() {
        std::cout << "Call Ok!";
    }
}