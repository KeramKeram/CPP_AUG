#pragma once

#include "common/CommonEnums.h"
#include "factories/IFilterFactory.h"

#include <map>

namespace factories {
    class RotationFilterFactory : public factories::IFilterFactory {
    public:
        ~RotationFilterFactory() override = default;

        std::shared_ptr<filters::IFilterCommand> createFilter(AugumentationData &data) override;

        private:
        std::map<int, RotateCode> mCodeMap;
    };
}