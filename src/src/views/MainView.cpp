#include "views/MainView.h"

namespace views {

    MainView::MainView(std::shared_ptr<controllers::GuiController> guiController) : mGuiController(guiController) {
    }
    auto MainView::createButtons(std::vector<std::string> &buttonsNames) {
        mButtonOption = ftxui::ButtonOption();

        auto buttonsLayout = ftxui::Container::Horizontal({Button(buttonsNames[0],
        [this] {
                    mGuiController->okButton(mMenuData.mData);}, &mButtonOption)});

        return buttonsLayout;
    }

    void MainView::show() {
        auto screen = ftxui::ScreenInteractive::FitComponent();

        ftxui::Component input = createPathInput(mMenuData.mInputPathName, mMenuData.mData.mInputPathString);
        auto radiobox = createRadioBox(mMenuData.mRotationMenuName, mMenuData.mData.selectedRotation,
                                       mMenuData.radioboxEntries);

        std::vector<std::string> buttonsNames{"[OK]"};
        auto buttonLayout = createButtons(buttonsNames);

        std::vector<ftxui::Component> elements = {input, radiobox, buttonLayout};
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

