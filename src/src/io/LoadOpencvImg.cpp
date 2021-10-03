#include "io/LoadOpencvImg.h"

#include <exception>
#include <opencv4/opencv2/opencv.hpp>

namespace io {
    cv::Mat LoadOpencvImg::loadImage(std::string path) {
        auto image = cv::imread(path);
        if (image.empty()) {
            if (image.empty()) {
                throw std::runtime_error{"Wrong Path!"};
            }
        }
        return image;
    }

    cv::Mat LoadOpencvImg::loadImage(std::string path, cv::ImreadModes mode) {
        auto image = cv::imread(path, mode);
        if (image.empty()) {
            if (image.empty()) {
                throw std::runtime_error{"Wrong Path!"};
            }
        }
        return image;
    }

}
