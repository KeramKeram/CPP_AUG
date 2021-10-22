#pragma once

#include "common/CommonEnums.h"
#include "common/CommonStructs.h"

#include <string>

namespace controllers {
    class GuiController {
    public:
        void setRotation(RotateCode code, int percent);

        void setPathToImages(std::string path);

        void okButton(AugumentationData data);
    };
}
