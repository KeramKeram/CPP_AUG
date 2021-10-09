#include <memory>
#include <stdlib.h>

#include "views/MainView.h"

int main(int, const char* []) {
    auto mainView = std::make_unique<views::MainView>();
    mainView->show();
    return EXIT_SUCCESS;
}

