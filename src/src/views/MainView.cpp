#include "views/MainView.h"

namespace views {
    void MainView::show() {
        auto info = ftxui::Renderer([&] {
            auto g = static_cast<std::size_t>(mMenuSelectedGlobal);
            auto menu_selected_g = static_cast<std::size_t>(mMenuSelectedGlobal[g]);
            std::string value = mMenuEntries[g][menu_selected_g];
            return window(ftxui::text("Content"),  //
                          ftxui::vbox({
                                       ftxui::text("menu_selected_global = " + std::to_string(g)),
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

