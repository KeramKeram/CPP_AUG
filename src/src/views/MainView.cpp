#include "views/MainView.h"

namespace views {

    MainView::MainView() {
    }

    void MainView::show() {
        auto screen = ftxui::ScreenInteractive::FitComponent();
        mInputPathName = "Path";
        ftxui::Component input = createPathInput(mInputPathName);

        std::vector<std::string> radiobox_entries = {
                "Rotate 90",
                "Rotate 180",
                "Rotate 270",
        };
        int selected = 0;
        mRotationName = "Rotation";
        auto radiobox = createRadioBox(mRotationName, selected, radiobox_entries);

        ftxui::Component component = initRenderer(input, radiobox);

        screen.Loop(component);
    }

    ftxui::Component MainView::initRenderer(ftxui::Component &input, ftxui::Component &radiobox) const {
        auto layout = ftxui::Container::Vertical({
                                                         input,
                                                         radiobox
                                                 });

        auto component = ftxui::Renderer(layout, [&] {
            return ftxui::vbox({
                                       input->Render(),
                                       ftxui::separator(),
                                       radiobox->Render(),
                                       ftxui::separator()
                               }) |
                   ftxui::xflex | size(ftxui::WIDTH, ftxui::GREATER_THAN, 40) | ftxui::border;
        });
        return component;
    }

    ftxui::Component MainView::createRadioBox(std::string& name, int &selected, std::vector<std::string>& entries) {
        auto radiobox = ftxui::Radiobox(&entries, &selected);
        radiobox = Wrap(name, radiobox);
        return radiobox;
    }

    ftxui::Component MainView::createPathInput(std::string& name) {
        auto input = ftxui::Input(&mPathInput, name);
        input = Wrap("Input", input);
        return input;
    }

    ftxui::Component MainView::Wrap(std::string name, ftxui::Component component) {
        return Renderer(component, [name, component] {
            return ftxui::hbox({
                                       ftxui::text(name) | size(ftxui::WIDTH, ftxui::EQUAL, 8),
                                       ftxui::separator(),
                                       component->Render() | ftxui::xflex,
                               }) |
                   ftxui::xflex;
        });
    }
}

