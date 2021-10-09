#include "filters/FilterRotateImg.h"

namespace filters {

    cv::Mat FilterRotateImg::execute(cv::Mat img, RotateCode code) {
        double angle = toUnderlyingType(code);
        float cols = static_cast<float>(img.cols);
        float rows = static_cast<float>(img.rows);

        return rotate(img, angle, cols, rows);
    }

    cv::Mat FilterRotateImg::rotate(cv::Mat img, double angle, float cols, float rows) {
        cv::Point2f center((cols - 1.0f) / 2.0f, (rows - 1.0f) / 2.0f);
        cv::Mat rotation_matix = getRotationMatrix2D(center, angle, 1.0);
        cv::Mat rotated_image;
        warpAffine(img, rotated_image, rotation_matix, img.size());
        return rotated_image;
    }

}