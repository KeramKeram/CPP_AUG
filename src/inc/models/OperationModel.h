#pragma once

#include "models/IModel.h"

#include <mutex>
#include <vector>

namespace models {
    template<class T>
    class MOperationModel : public IModel<T> {
    public:
        ~MOperationModel() override = default;

        void add(std::shared_ptr<T> ptr) override {
            std::lock_guard<std::mutex> lk(mMutex);
            mModel.emplace_back(ptr);
        }

        bool hasNext() override {
            std::lock_guard<std::mutex> lk(mMutex);
            return mModel.size() > mVectorCounter;
        }

        std::shared_ptr<T> &next() override {
            std::lock_guard<std::mutex> lk(mMutex);
            return mModel[mVectorCounter++];
        }

    private:
        std::vector<std::shared_ptr<T>> mModel;
        std::mutex mMutex;
        unsigned int mVectorCounter;
    };
}