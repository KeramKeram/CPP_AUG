#pragma once

#include "common/CommonEnums.h"
#include "common/CommonStructs.h"
#include "filters/IFilterCommand.h"
#include "models/OperationModel.h"

#include <string>

namespace controllers {
    class GuiController {
    public:
        void updateModel(AugumentationData data);

        void clearModel();

        void okButton();

    private:
        std::unique_ptr<models::OperationModel<filters::IFilterCommand>> mModel;
    };
}
