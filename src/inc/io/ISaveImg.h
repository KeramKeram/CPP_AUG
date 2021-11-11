#pragma once
#include <opencv4/opencv2/opencv.hpp>
#include <string>

namespace io {
    class ISaveImage {
    public:
            virtual ~ISaveImage() = default;
            virtual void saveImageOCV(cv::Mat img, const std::string path) = 0;
    };
}