#pragma once

#include "filters/IFilterCommand.h"
#include "models/OperationModel.h"

#include <string>

namespace controllers {
    class AugumentationFacade {
    public:
        AugumentationFacade(const std::string &imgPath,
                            std::shared_ptr<models::OperationModel<filters::IFilterCommand>> filterModel);

    private:
        std::string mImagesPath;
        std::shared_ptr<models::OperationModel<filters::IFilterCommand>> mModel;
    };
}// namespace controllers