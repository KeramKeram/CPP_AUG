#pragma once

#include "models/IModel.h"

#include <condition_variable>
#include <mutex>
#include <vector>

namespace models {
    template<class T>
    class MOperationModel : public IModel<T> {
    public:
        ~MOperationModel() override = default;

        void add(std::shared_ptr<T> ptr) override {
            std::lock_guard<std::mutex> lk(mMutex);
            mModel.template emplace_back(ptr);
            mCondVar.notify_one();
        }

        bool hasNext() const override {
            return false;
        }

        std::shared_ptr<T> &next() override {
            return nullptr;
        }

    private:
        std::vector<std::shared_ptr<T>> mModel;
        std::mutex mMutex;
        std::condition_variable mCondVar;
    };
}