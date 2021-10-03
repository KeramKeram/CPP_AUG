#pragma once

#include <opencv2/opencv.hpp>

namespace filters {

    enum class CommandCode {
        ROTATE_90 = 0,
        ROTATE_180 = 1,
        ROTATE_270 = 2
    };

    class IFilterCommand {
    public:
        virtual ~IFilterCommand() = default;

        virtual cv::Mat execute(cv::Mat img, CommandCode code) = 0;
    };
}