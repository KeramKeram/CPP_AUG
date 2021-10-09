#pragma once

#include <opencv2/opencv.hpp>

namespace filters {

    enum class RotateCode {
        ROTATE_90 = 90,
        ROTATE_180 = 180,
        ROTATE_270 = 270
    };

    template<typename E>
    constexpr auto toUnderlyingType(E e)
    {
        return static_cast<typename std::underlying_type<E>::type>(e);
    }

    class IFilterCommand {
    public:
        virtual ~IFilterCommand() = default;

        virtual cv::Mat execute(cv::Mat img, RotateCode code) = 0;
    };
}