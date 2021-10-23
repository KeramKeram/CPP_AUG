#include "common/CommonStructs.h"
#include "factories/RotationFilterFactory.h"
#include "filters/FilterRotateImg.h"

#include <memory>


namespace factories {
    std::shared_ptr<filters::IFilterCommand>
    factories::RotationFilterFactory::createFilter(AugumentationData &data) {

        return std::make_shared<filters::FilterRotateImg>(mCodeMap[data.selectedRotation]);
    }

}