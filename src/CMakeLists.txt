option(CPP_STARTER_USE_QT "Enable compilation of QT sample" OFF)
option(CPP_STARTER_USE_FLTK "Enable compilation of FLTK sample" OFF)
option(CPP_STARTER_USE_GTKMM "Enable compilation of GTKMM sample" OFF)
option(CPP_STARTER_USE_IMGUI "Enable compilation of ImGui sample" OFF)
option(CPP_STARTER_USE_NANA "Enable compilation of Nana GUI sample" OFF)
option(CPP_STARTER_USE_SDL "Enable compilation of SDL sample" OFF)
option(CPP_STARTER_USE_FTXUI "Enable compilation of FTXUI sample" ON)

# sdl
if (CPP_STARTER_USE_SDL)
    message("Using SDL2")
    add_subdirectory(sdl)
endif ()

# qt
if (CPP_STARTER_USE_QT)
    message("Using Qt")
    add_subdirectory(qt)
endif ()

# fltk test
if (CPP_STARTER_USE_FLTK)
    message("Using FLTK")
    add_subdirectory(fltk)
endif ()

# gtkmm test
if (CPP_STARTER_USE_GTKMM)
    message("Using gtkmm")
    add_subdirectory(gtkmm)
endif ()

# imgui example
if (CPP_STARTER_USE_IMGUI)
    message("Using Dear ImGui")
    add_subdirectory(imgui)
endif ()

# Nana
if (CPP_STARTER_USE_NANA)
    message("Using Nana")
    add_subdirectory(nana)
endif ()

if (CPP_STARTER_USE_FTXUI)
    include_directories(FTXUI/include)
    message("Using FTXUI")
    add_subdirectory(FTXUI)
endif ()

find_package(fmt)
find_package(spdlog)
find_package(OpenCV REQUIRED)

include_directories(inc/)
set(HEADER_FILES inc/io/ILoadImg.h
        inc/io/LoadOpencvImg.h
        inc/filters/IFilterCommand.h
        inc/filters/FilterRotateImg.h
        inc/controllers/GuiController.h
        inc/models/IModel.h
        inc/common/CommonEnums.h
        inc/models/OperationModel.h
        inc/views/MainView.h
        inc/common/CommonStructs.h
        inc/factories/IFilterFactory.h
        inc/views/IView.h
        inc/factories/RotationFilterFactory.h
        inc/io/Directory.h inc/io/DirectoryFilter.h
        inc/controllers/AugmentationFacade.h inc/io/ISaveImg.h inc/io/SaveOpencvImg.h inc/common/NameGenerators.h)


set(SOURCE_FILES src/io/LoadOpencvImg.cpp
        src/filters/FilterRotateImg.cpp
        src/controllers/GuiController.cpp
        src/models/OperationModel.cpp
        src/views/MainView.cpp
        src/factories/RotationFilterFactory.cpp
        src/io/Directory.cpp src/io/DirectoryFilter.cpp
        src/controllers/AugmentationFacade.cpp src/io/SaveOpencvImg.cpp src/common/NameGenerators.cpp)


# Generic test that uses conan libs
add_executable(CPP_AUG main.cpp ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(
        CPP_AUG
        PRIVATE project_options
        project_warnings
        fmt::fmt
        screen
        dom
        component
        spdlog::spdlog
        ${OpenCV_LIBS})
