#pragma once

#include <memory>

namespace models {
    template<class T>
    class IModel {
    public:
        virtual ~IModel() = default;

        virtual void add(std::shared_ptr<T>) = 0;

        virtual void clear() = 0;

        virtual bool hasNext() = 0;

        virtual std::shared_ptr<T>& next() = 0;

        virtual void resetIterator() = 0;
    };
}