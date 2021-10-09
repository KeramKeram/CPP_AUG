#include "views/MainView.h"

namespace views {

    MainView::MainView() {
        mMenuEntries = {
                {
                        "IO"
                },
                {
                        "Rotation"
                }
        };

        mGlobalMenu = ftxui::Container::Vertical(
                {
                        Window("General", ftxui::Menu(&mMenuEntries[0], &mMenuSelected[0])),
                        Window("Augmentation", ftxui::Menu(&mMenuEntries[1], &mMenuSelected[1])),
                },
                &mMenuSelectedGlobal);
    }

    void MainView::show() {
        auto info = ftxui::Renderer([this] {
            auto selectedGlobalSize_t = static_cast<std::size_t>(mMenuSelectedGlobal);
            auto menuSelectedSize_t = static_cast<std::size_t>(mMenuSelected[selectedGlobalSize_t]);
            std::string value = mMenuEntries[selectedGlobalSize_t][menuSelectedSize_t];
            return window(ftxui::text("Content"),  //
                          ftxui::vbox({
                                              ftxui::text(
                                                      "menu_selected_global = " + std::to_string(mMenuSelectedGlobal)),
                                              ftxui::text("menu_selected[0]     = " +
                                                          std::to_string(mMenuSelected[0])),
                                              ftxui::text("menu_selected[1]     = " +
                                                          std::to_string(mMenuSelected[1])),
                                              ftxui::text("Value                = " + value),
                                      })) |
                   ftxui::flex;
        });

        auto global = ftxui::Container::Horizontal({
                                                           mGlobalMenu,
                                                           info,
                                                   });
        auto screen = ftxui::ScreenInteractive::TerminalOutput();
        screen.Loop(global);
    }

    ftxui::Component MainView::Window(std::string title, ftxui::Component component) {
        return Renderer(component, [component, title] {  //
            return window(ftxui::text(title), component->Render()) | ftxui::flex;
        });
    }
}

