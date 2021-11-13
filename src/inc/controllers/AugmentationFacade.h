#pragma once

#include "filters/IFilterCommand.h"
#include "models/OperationModel.h"
#include <io/LoadOpencvImg.h>
#include <io/SaveOpencvImg.h>

#include <atomic>
#include <string>
#include <thread>

namespace controllers {
    class AugmentationFacade {
    public:
        AugmentationFacade() = default;

        ~AugmentationFacade();

        void start(const std::string &imgPath,
                   std::shared_ptr<models::OperationModel<filters::IFilterCommand>> filterModel,
                   std::function<void(std::string)> statusCallback);

        void stop();

    private:

        void runAugmentation();

        void augmentImages(io::LoadOpencvImg &loader, io::SaveImage &saver, const std::string &path);

        std::atomic_bool mRun;
        std::thread mTask;
        std::string mImagesPath;
        std::shared_ptr<models::OperationModel<filters::IFilterCommand>> mModel;
        std::function<void(std::string)> mStatusCallback;
    };
}// namespace controllers