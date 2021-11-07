#include "controllers/AugumentationFacade.h"

namespace controllers {

    AugumentationFacade::AugumentationFacade(
            const std::string &imgPath, std::shared_ptr<models::OperationModel<filters::IFilterCommand>> filterModel)
        : mImagesPath(imgPath), mModel(filterModel) {}

    void AugumentationFacade::runAugmentation() {}
}// namespace controllers