#pragma once

#include <opencv2/opencv.hpp>

namespace io {
    class ILoadImg {
    public:
        virtual ~ILoadImg() = default;

        virtual cv::Mat loadImage(std::string path) = 0;

        virtual cv::Mat loadImage(std::string path, cv::ImreadModes mode) = 0;
    };
}