#pragma once

#include "common/CommonEnums.h"
#include "common/CommonStructs.h"
#include "filters/IFilterCommand.h"
#include "models/OperationModel.h"

#include <functional>
#include <string>

namespace controllers {
    class GuiController {
    public:
        GuiController();

        void createFilters(AugumentationData data);

        void clearModel();

        void okButton(std::function<void(std::string)>& statusCallback);

    private:
        std::shared_ptr<models::OperationModel<filters::IFilterCommand>> mModel;

        std::string mPathImages;
    public:
        void setPathToImages(const std::string &path);
    };
}
