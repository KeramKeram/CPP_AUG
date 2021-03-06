#pragma once

#include "models/IModel.h"

#include <mutex>
#include <vector>

namespace models {
    template<class T>
    class OperationModel : public IModel<T> {
    public:
        OperationModel() = default;

        ~OperationModel() override = default;

        void add(std::shared_ptr<T> ptr) override {
            std::lock_guard<std::mutex> lk(mMutex);
            mModel.emplace_back(ptr);
        }

        bool hasNext() override {
            std::lock_guard<std::mutex> lk(mMutex);
            return mModel.size() > mVectorCounter;
        }

        void clear() override {
            std::lock_guard<std::mutex> lk(mMutex);
            mModel.clear();
            mVectorCounter = 0;
        }

        std::shared_ptr<T> &next() override {
            std::lock_guard<std::mutex> lk(mMutex);
            return mModel.at(mVectorCounter++);
        }

        void resetIterator() override {
            std::lock_guard<std::mutex> lk(mMutex);
            mVectorCounter = 0;
        }

    private:
        std::vector<std::shared_ptr<T>> mModel;
        std::mutex mMutex;
        unsigned int mVectorCounter{0};
    };
}