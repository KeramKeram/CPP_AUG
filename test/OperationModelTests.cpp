#include <catch2/catch.hpp>
#include "models/OperationModel.h"

TEST_CASE("Models with data", "[operationsmodel]")
{
    models::OperationModel<int> model;
    SECTION("Test with one element.") {
        auto item1 = std::make_shared<int>(1);
        model.add(item1);
        REQUIRE(model.hasNext() == true);
    }

    SECTION("Test with two element.") {
        auto item2 = std::make_shared<int>(2);
        model.add(item2);
        REQUIRE(model.hasNext() == true);
    }
}

TEST_CASE("Models with no items", "[operationsmodel]")
{
    models::OperationModel<int> model;

    SECTION("Test for no next element.") {
        REQUIRE(model.hasNext() == false);
    }

    SECTION("Test for access not existing item.") {
        REQUIRE_THROWS(model.next());
    }
}
