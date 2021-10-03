option(CPP_STARTER_USE_QT "Enable compilation of QT sample" OFF)
option(CPP_STARTER_USE_FLTK "Enable compilation of FLTK sample" OFF)
option(CPP_STARTER_USE_GTKMM "Enable compilation of GTKMM sample" OFF)
option(CPP_STARTER_USE_IMGUI "Enable compilation of ImGui sample" OFF)
option(CPP_STARTER_USE_NANA "Enable compilation of Nana GUI sample" OFF)
option(CPP_STARTER_USE_SDL "Enable compilation of SDL sample" OFF)

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

include_directories(FTXUI/include)
message("Using FTXUI")
add_subdirectory(FTXUI)


find_package(fmt)
find_package(spdlog)

# Generic test that uses conan libs
add_executable(CPP_AUG main.cpp)
target_link_libraries(
        CPP_AUG
        PRIVATE project_options
        project_warnings
        fmt::fmt
        screen
        dom
        component
        spdlog::spdlog)
