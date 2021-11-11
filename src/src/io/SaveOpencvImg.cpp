#include "io/SaveOpencvImg.h"

#include <exception>
#include <opencv4/opencv2/opencv.hpp>

namespace io {
    void io::SaveImage::saveImageOCV(cv::Mat img, const std::string path) {
        if (img.empty()) { throw std::runtime_error{"Emtpy image!"}; }
        cv::imwrite(path, img);
    }
}// namespace io
