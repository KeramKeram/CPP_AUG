/*
 * Author: KeramKeram
 * github: https://github.com/KeramKeram/
 * License: MIT
 * Short description: Test program for learning FTXUI and opencv in c++. Program will do basic augmentation on image files.
 */
#include "controllers/GuiController.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/spdlog.h"
#include "views/MainView.h"

#include <memory>
#include <stdlib.h>


std::unique_ptr<views::MainView> createMainView(int arg, std::shared_ptr<controllers::GuiController> gController,
                                                const char *argv[]) {
    std::unique_ptr<views::MainView> ptr = nullptr;
    if (arg == 2) {
        std::string path(argv[1]);
        ptr = std::make_unique<views::MainView>(gController, path);
        return ptr;
    }
    ptr = std::make_unique<views::MainView>(gController);
    return ptr;
}

int main(int argc, const char *argv[]) {
    auto guiController = std::make_shared<controllers::GuiController>();
    auto mainView = createMainView(argc, guiController, argv);
    size_t max_size = 1048576 * 5;
    size_t max_files = 1;
    auto logger = spdlog::rotating_logger_mt("AugumentatorLog", "AugumentatorLog.txt", max_size, max_files);
    spdlog::flush_every(std::chrono::seconds(60));
    spdlog::set_default_logger(logger);
    mainView->show();
    return EXIT_SUCCESS;
}
