#pragma once

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Menu, Renderer, Horizontal, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, Element, operator|, window, flex, vbox
#include "views/IView.h"

#include <array>
#include <vector>
#include <string>
#include <stdlib.h>  // for EXIT_SUCCESS
#include <memory>    // for allocator, __shared_ptr_access


namespace views {
    class MainView : public IView {
    public:
        MainView();

        void show();

    private:
        ftxui::Component Window(std::string title, ftxui::Component component);

        std::array<int, 2> mMenuSelected{0, 0};
        std::vector<std::vector<std::string>> mMenuEntries;
        int mMenuSelectedGlobal;
        ftxui::Component mGlobalMenu;
    };
}