#pragma once

#include "common/CommonEnums.h"
#include "common/CommonStructs.h"

#include <string>

namespace controllers {
    class GuiController {
    public:
        void updateModel(AugumentationData data);

        void clearModel();

        void okButton();
    };
}
