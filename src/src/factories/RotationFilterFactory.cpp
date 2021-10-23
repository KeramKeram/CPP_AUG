#include "common/CommonStructs.h"
#include "factories/RotationFilterFactory.h"
#include "filters/FilterRotateImg.h"

#include <memory>


namespace factories {
    factories::RotationFilterFactory::RotationFilterFactory() {
        mCodeMap[0] = RotateCode::ROTATE_90;
        mCodeMap[1] = RotateCode::ROTATE_180;
        mCodeMap[2] = RotateCode::ROTATE_270;
    }

    std::shared_ptr<filters::IFilterCommand>
    factories::RotationFilterFactory::createFilter(AugumentationData &data) {

        return std::make_shared<filters::FilterRotateImg>(mCodeMap[data.selectedRotation]);
    }

}