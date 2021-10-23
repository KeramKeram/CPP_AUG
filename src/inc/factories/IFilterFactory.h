#pragma once

#include "common/CommonStructs.h"
#include "filters/IFilterCommand.h"

namespace factories {
    class IFilterFactory {
    public:
        virtual ~IFilterFactory() = default;

        virtual std::shared_ptr<filters::IFilterCommand> createFilter(AugumentationData &data, std::string &name) = 0;

    };
}