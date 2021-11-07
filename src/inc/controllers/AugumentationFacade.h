#pragma once
#include <string>

namespace controllers {
    class AugumentationFacade {
    public:
        AugumentationFacade(const std::string &imgPath);

    private:
        std::string mImagesPath;
    };
}// namespace controllers