#include <catch2/catch.hpp>
#include "io/DirectoryFilter.h"

TEST_CASE("Filtering empty files list", "[io]")
{
    io::DirectoryFilter filter;
    std::vector<std::string> emptyVector;
    SECTION("Test filtering by extension empty list, return list need to be empty.") {
        REQUIRE(filter.filterByExtension(emptyVector, {}).size() == 0);
    }
}

