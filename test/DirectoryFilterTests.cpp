#include "io/DirectoryFilter.h"
#include <catch2/catch.hpp>

TEST_CASE("Filtering empty files list", "[io]") {
    io::DirectoryFilter filter;
    std::vector<std::string> emptyVector;
    SECTION("Test filtering by extension empty list, return list need to be empty.") {
        REQUIRE(filter.filterByExtension(emptyVector, {}).size() == 0);
    }
}

TEST_CASE("Filtering list by one extension", "[io]") {
    io::DirectoryFilter filter;
    std::vector<std::string> files = {"main.cpp", "main.h", "foo.c", "foo.hpp", "readme.txt"};

    SECTION("Test filtering by cpp extension") {
        std::vector<std::string> extensions = {".cpp"};
        REQUIRE(filter.filterByExtension(files, extensions).size() == 1);
    }

    SECTION("Test filtering by c extension") {
        std::vector<std::string> extensions = {".c"};
        REQUIRE(filter.filterByExtension(files, extensions).size() == 1);
    }

    SECTION("Test filtering by hpp extension") {
        std::vector<std::string> extensions = {".hpp"};
        REQUIRE(filter.filterByExtension(files, extensions).size() == 1);
    }

    SECTION("Test filtering by txt extension") {
        std::vector<std::string> extensions = {".txt"};
        REQUIRE(filter.filterByExtension(files, extensions).size() == 1);
    }

    SECTION("Test filtering by . extension") {
        std::vector<std::string> extensions = {"."};
        REQUIRE(filter.filterByExtension(files, extensions).size() == 0);
    }
}

TEST_CASE("Filtering files list by not existing extension in set", "[io]") {
    io::DirectoryFilter filter;
    std::vector<std::string> files = {"main.cpp", "main.h", "foo.c", "foo.hpp", "readme.txt"};

    SECTION("Test filtering by md extension") {
        std::vector<std::string> extensions = {".md"};
        REQUIRE(filter.filterByExtension(files, extensions).size() == 0);
    }
}