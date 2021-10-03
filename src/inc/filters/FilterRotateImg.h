#pragma once

#include "IFilterCommand.h"
#include <map>

namespace filters {
    class FilterRotateImg : public IFilterCommand {
    public:
        FilterRotateImg();

        cv::Mat execute(cv::Mat img, CommandCode code) override;

    private:
        cv::Mat rotate(cv::Mat img, double angle, float cols, float rows);

        std::map<CommandCode, double> mRotation;
    };
}