#pragma once

#include "io/ISaveImg.h"
#include <opencv2/core/mat.hpp>

namespace io {
    class SaveImage : public ISaveImage {
    public:
        void saveImageOCV(cv::Mat img, const std::string path) override;
    };
}// namespace io