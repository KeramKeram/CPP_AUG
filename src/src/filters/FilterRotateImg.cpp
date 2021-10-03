#include "filters/FilterRotateImg.h"

namespace filters {

    FilterRotateImg::FilterRotateImg() {
        mRotation[CommandCode::ROTATE_90] = 90;
        mRotation[CommandCode::ROTATE_180] = 180;
        mRotation[CommandCode::ROTATE_270] = 270;
    }

    cv::Mat FilterRotateImg::execute(cv::Mat img, CommandCode code) {
        double angle = mRotation[code];
        // get the center coordinates of the image to create the 2D rotation matrix
        float cols = static_cast<float>(img.cols);
        float rows = static_cast<float>(img.rows);

        return rotate(img, angle, cols, rows);
    }

    cv::Mat FilterRotateImg::rotate(cv::Mat img, double angle, float cols, float rows) {
        cv::Point2f center((cols - 1.0f) / 2.0f, (rows - 1.0f) / 2.0f);
        // using getRotationMatrix2D() to get the rotation matrix
        cv::Mat rotation_matix = getRotationMatrix2D(center, angle, 1.0);
        // we will save the resulting image in rotated_image matrix
        cv::Mat rotated_image;
        // rotate the image using warpAffine
        warpAffine(img, rotated_image, rotation_matix, img.size());
        return rotated_image;
    }

}