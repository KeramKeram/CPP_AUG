#pragma once

#include "IFilterCommand.h"
#include <map>

namespace filters {
    class FilterRotateImg : public IFilterCommand {
    public:
        FilterRotateImg() = default;

        ~FilterRotateImg() = default;

        cv::Mat execute(cv::Mat img, RotateCode code) override;

    private:
        cv::Mat rotate(cv::Mat img, double angle, float cols, float rows);
    };
}