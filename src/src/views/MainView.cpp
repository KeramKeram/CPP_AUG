#include "views/MainView.h"

namespace views {

    MainView::MainView() {
    }

    void MainView::show() {
        auto screen = ftxui::ScreenInteractive::FitComponent();

        ftxui::Component input = createPathInput(mMenuData.mInputPathName, mMenuData.mInputPathString);
        auto radiobox = createRadioBox(mMenuData.mRotationMenuName, mMenuData.selectedRotation,
                                       mMenuData.radioboxEntries);

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

    ftxui::Component MainView::createRadioBox(std::string &name, int &selected, std::vector<std::string> &entries) {
        auto radiobox = ftxui::Radiobox(&entries, &selected);
        radiobox = Wrap(name, radiobox);
        return radiobox;
    }

    ftxui::Component MainView::createPathInput(std::string &name, std::string &inputString) {
        auto input = ftxui::Input(&inputString, name);
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

