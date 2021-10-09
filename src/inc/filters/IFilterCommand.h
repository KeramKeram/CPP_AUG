#pragma once

#include "common/CommonEnums.h"

#include <opencv2/opencv.hpp>

namespace filters {

    class IFilterCommand {
    public:
        virtual ~IFilterCommand() = default;

        virtual cv::Mat execute(cv::Mat img, RotateCode code) = 0;
    };
}