#pragma once

namespace views {
    class IView {
    public:
        virtual ~IView() = default;

        virtual void show() = 0;
    };
}