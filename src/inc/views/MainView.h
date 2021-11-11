#pragma once

#include "common/CommonStructs.h"
#include "controllers/GuiController.h"
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Button, Horizontal, Renderer
#include "ftxui/component/component.hpp"  // for Menu, Renderer, Horizontal, Vertical
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/component_options.hpp"   // for ButtonOption
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for separator, gauge, Element, operator|, vbox, border
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
        MainView(std::shared_ptr<controllers::GuiController> guiController);

        MainView(std::shared_ptr<controllers::GuiController> guiController, std::string path);

        void show() override;

    private:

        struct MainMenuStaticData {
            std::string mInputPathName{"Path"};
            // Rotation Menu
            std::vector<std::string> radioboxEntries = {
                    "Rotate 90",
                    "Rotate 180",
                    "Rotate 270",
            };
            std::string mRotationMenuName = "Rotation";
        };

        auto createButtons(std::vector<std::string> &buttonsNames, std::function<void()> &clickCallback);

        ftxui::Component Wrap(std::string name, ftxui::Component component);

        ftxui::Component createRadioBox(std::string &name, int &selected, std::vector<std::string> &entries);

        ftxui::Component createPathInput(std::string &name, std::string &inputString);

        ftxui::Component initRenderer(std::vector<ftxui::Component> &input) const;

        std::shared_ptr<controllers::GuiController> mGuiController;

        MainMenuStaticData mMenuData;

        ftxui::ButtonOption mButtonOption;

        AugumentationData mData;

        IOData mIO;
    };
}