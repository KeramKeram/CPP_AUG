#pragma once

#include "common/CommonStructs.h"
#include "filters/IFilterCommand.h"

namespace factories {
    class IFactory {
    public:
        virtual ~IFactory() = default;

        std::shared_ptr<filters::IFilterCommand> createFilter(AugumentationData &data);

    };
}