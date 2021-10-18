#pragma once

#include <memory>

namespace models {
    template<class T>
    class IModel {
    public:
        virtual ~IModel() = default;

        virtual void add(std::shared_ptr<T>) = 0;

        void clear() = 0;

        [[nodiscard]] virtual int size() const = 0;

        virtual bool hasNext() const = 0;

        virtual shared_ptr<T>& next() = 0;
    };
}