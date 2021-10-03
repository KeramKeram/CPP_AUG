#pragma once

#include <string>
#include "ILoadImg.h"

namespace io {
    class LoadOpencvImg : public ILoadImg {
    public:
        cv::Mat loadImage(std::string path) override;

        cv::Mat loadImage(std::string path, cv::ImreadModes mode) override;
    };
}