#include <stdlib.h>  // for EXIT_SUCCESS
#include <memory>    // for allocator, __shared_ptr_access
#include <string>  // for string, operator+, basic_string, to_string, char_traits
#include <vector>  // for vector, __alloc_traits<>::value_type

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Menu, Renderer, Horizontal, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, Element, operator|, window, flex, vbox

using namespace ftxui;

Component Window(std::string title, Component component) {
    return Renderer(component, [component, title] {  //
        return window(text(title), component->Render()) | flex;
    });
}

int main(int, const char* []) {
    int menu_selected[] = {0, 0};
    std::vector<std::vector<std::string>> menu_entries = {
            {
                    "IO"
            },
            {
                    "Rotation"
            }
    };

    int menu_selected_global = 0;
    auto menu_global = Container::Vertical(
            {
                    Window("General", Menu(&menu_entries[0], &menu_selected[0])),
                    Window("Augmentation", Menu(&menu_entries[1], &menu_selected[1])),
            },
            &menu_selected_global);

    auto info = Renderer([&] {
        auto g = static_cast<std::size_t>(menu_selected_global);
        auto menu_selected_g = static_cast<std::size_t>(menu_selected[g]);
        std::string value = menu_entries[g][menu_selected_g];
        return window(text("Content"),  //
                      vbox({
                                   text("menu_selected_global = " + std::to_string(g)),
                                   text("menu_selected[0]     = " +
                                        std::to_string(menu_selected[0])),
                                   text("menu_selected[1]     = " +
                                        std::to_string(menu_selected[1])),
                                   text("Value                = " + value),
                           })) |
               flex;
    });

    auto global = Container::Horizontal({
                                                menu_global,
                                                info,
                                        });

    auto screen = ScreenInteractive::TerminalOutput();
    screen.Loop(global);
    return EXIT_SUCCESS;
}

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
