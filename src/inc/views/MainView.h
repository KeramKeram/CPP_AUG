#pragma once

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Menu, Renderer, Horizontal, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, Element, operator|, window, flex, vbox
#include "views/IView.h"

#include <array>
#include <memory>    // for allocator, __shared_ptr_access
#include <stdlib.h>  // for EXIT_SUCCESS
#include <string>
#include <vector>


namespace views {
    class MainView : public IView {
    public:
        MainView();

        void show() override;

    private:

        struct MainMenuData {
            // Input Menu
            std::string mInputPathName{"Path"};
            std::string mInputPathString;
            // Rotation Menu
            std::vector<std::string> radioboxEntries = {
                    "Rotate 90",
                    "Rotate 180",
                    "Rotate 270",
            };
            int selectedRotation{0};
            std::string mRotationMenuName = "Rotation";
        };

        ftxui::Component Wrap(std::string name, ftxui::Component component);

        ftxui::Component createRadioBox(std::string &name, int &selected, std::vector<std::string> &entries);

        ftxui::Component createPathInput(std::string &name, std::string &inputString);

        ftxui::Component initRenderer(ftxui::Component &input, ftxui::Component &radiobox) const;

        MainMenuData mMenuData;
    };
}