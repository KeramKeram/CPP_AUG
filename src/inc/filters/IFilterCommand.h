#pragma once

#include <opencv2/opencv.hpp>

namespace filters {

    enum class RotateCode {
        ROTATE_90 = 0,
        ROTATE_180 = 1,
        ROTATE_270 = 2
    };

    class IFilterCommand {
    public:
        virtual ~IFilterCommand() = default;

        virtual cv::Mat execute(cv::Mat img, RotateCode code) = 0;
    };
}