#include "views/MainView.h"

namespace views {

    MainView::MainView(std::shared_ptr<controllers::GuiController> guiController) : mGuiController(guiController) {
    }

    void MainView::show() {
        auto screen = ftxui::ScreenInteractive::FitComponent();

        ftxui::Component input = createPathInput(mMenuData.mInputPathName, mMenuData.mInputPathString);
        auto radiobox = createRadioBox(mMenuData.mRotationMenuName, mMenuData.selectedRotation,
                                       mMenuData.radioboxEntries);

        mButtonOption = ftxui::ButtonOption();

        mButtonsLayout = ftxui::Container::Horizontal({
            Button("[Ok]", [this] {mGuiController->okButton();}, &mButtonOption)});

        std::vector<ftxui::Component> elements = {input, radiobox, mButtonsLayout};
        ftxui::Component component = initRenderer(elements);

        screen.Loop(component);
    }

    ftxui::Component MainView::initRenderer(std::vector<ftxui::Component> &input) const {
        auto layout = ftxui::Container::Vertical({
                                                         input[0],
                                                         input[1],
                                                         input[2]
                                                 });

        auto component = ftxui::Renderer(layout, [&] {
            return ftxui::vbox({
                                       input[0]->Render(),
                                       ftxui::separator(),
                                       input[1]->Render(),
                                       ftxui::separator(),
                                       input[2]->Render()
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

