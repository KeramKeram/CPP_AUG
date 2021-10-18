#pragma once

#include "IFilterCommand.h"

#include <map>

namespace filters {
    class FilterRotateImg : public IFilterCommand {
    public:
        FilterRotateImg(RotateCode code);

        ~FilterRotateImg() = default;

        cv::Mat execute(cv::Mat img) override;

    private:
        cv::Mat rotate(cv::Mat img, double angle, float cols, float rows);

        RotateCode mCode;
    };
}