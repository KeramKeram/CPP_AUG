#pragma once

#include "filters/IFilterCommand.h"
#include "models/OperationModel.h"

#include <io/LoadOpencvImg.h>
#include <io/SaveOpencvImg.h>
#include <string>

namespace controllers {
    class AugumentationFacade {
    public:
        AugumentationFacade(const std::string &imgPath,
                            std::shared_ptr<models::OperationModel<filters::IFilterCommand>> filterModel);
        void runAugmentation();

    private:
        std::string mImagesPath;
        std::shared_ptr<models::OperationModel<filters::IFilterCommand>> mModel;
        void augumentImages(io::LoadOpencvImg &loader, io::SaveImage &saver, const std::string &path);
    };
}// namespace controllers