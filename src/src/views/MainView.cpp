#include "views/MainView.h"

namespace views {

    MainView::MainView(std::shared_ptr<controllers::GuiController> guiController)
        : mGuiController(guiController), mScreen(ftxui::ScreenInteractive::FitComponent()) {}

    MainView::MainView(std::shared_ptr<controllers::GuiController> guiController, std::string path)
        : mGuiController(guiController), mScreen(ftxui::ScreenInteractive::FitComponent()) {
        mIO.mInputPathString = path;
    }

    auto MainView::createButton(std::vector<std::string> &buttonsNames, std::function<void()> &clickCallback) {
        mButtonOption = ftxui::ButtonOption();

        auto buttonsLayout = ftxui::Container::Horizontal({Button(buttonsNames[0], clickCallback, &mButtonOption)});

        return buttonsLayout;
    }

    void MainView::show() {
        ftxui::Component input = createPathInput(mMenuData.mInputPathName, mIO.mInputPathString);
        auto radiobox = createRadioBox(mMenuData.mRotationMenuName, mData.selectedRotation, mMenuData.radioboxEntries);

        std::vector<std::string> buttonsNames{"[OK]"};
        std::function<void()> clickCallback = [this] {
            setStatus("Working");
            mGuiController->clearModel();
            mGuiController->createFilters(mData);
            mGuiController->setPathToImages(mIO.mInputPathString);
            mGuiController->okButton(std::bind(&MainView::setStatus, this, std::placeholders::_1));
        };
        auto buttonLayout = createButton(buttonsNames, clickCallback);
        ftxui::Component status = createPathInput(mMenuData.mStatusLabel, mStatus);
        std::vector<ftxui::Component> elements = {input, radiobox, buttonLayout, status};
        ftxui::Component component = initRenderer(elements);

        mScreen.Loop(component);
    }

    ftxui::Component MainView::initRenderer(std::vector<ftxui::Component> &input) const {
        auto layout = ftxui::Container::Vertical({input[0], input[1], input[2], input[3]});

        auto component = ftxui::Renderer(layout, [&] {
            return ftxui::vbox({input[0]->Render(), ftxui::separator(), input[1]->Render(), ftxui::separator(),
                                input[2]->Render(), ftxui::separator(), input[3]->Render()}) |
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
        auto input = ftxui::Input(&inputString, "");
        input = Wrap(name, input);
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
    void MainView::setStatus(std::string status) {
        mStatus = status;
        // This part is required to refresh view. FTXUI have no direct method to repaint view. We send fake mouse event.
        ftxui::Mouse mouse;
        ftxui::Event event = ftxui::Event::Mouse("", mouse);
        mScreen.PostEvent(event);
    }
}// namespace views
