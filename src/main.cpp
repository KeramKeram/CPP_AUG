/*
 * Author: KeramKeram
 * github: https://github.com/KeramKeram/
 * License: MIT
 * Short description: Test program for learning FTXUI and opencv in c++. Program will do basic augmentation on image files.
 */

#include <memory>
#include <stdlib.h>

#include "views/MainView.h"

int main(int, const char* []) {
    auto mainView = std::make_unique<views::MainView>();
    mainView->show();
    return EXIT_SUCCESS;
}

