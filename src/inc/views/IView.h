#pragma once
#include <string>

namespace views {
    class IView {
    public:
        virtual ~IView() = default;

        virtual void show() = 0;

    protected:
        virtual void setStatus(std::string status) = 0;
    };
}// namespace views