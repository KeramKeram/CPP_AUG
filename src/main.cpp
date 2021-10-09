#include <stdlib.h>  // for EXIT_SUCCESS
#include "views/MainView.h"

#include <memory>



int main(int, const char* []) {
    auto mainView = std::make_unique<views::MainView>();
    mainView->show();
    return EXIT_SUCCESS;
}

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
