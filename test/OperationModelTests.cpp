#include <catch2/catch.hpp>
#include "models/OperationModel.h"

TEST_CASE("Models with data", "[operationsmodel]")
{
    models::OperationModel<int> model;
    auto item1 = std::make_shared<int>(1);

    SECTION("Test has next with one element.") {
        model.add(item1);
        REQUIRE(model.hasNext() == true);
    }

    SECTION("Test take one element from one element model and check if has next.") {
        model.add(item1);
        model.next();
        REQUIRE(model.hasNext() == false);
    }

    SECTION("Test has next with two element.") {
        model.add(item1);
        auto item2 = std::make_shared<int>(2);
        model.add(item2);
        REQUIRE(model.hasNext() == true);
    }

    SECTION("Test with two element on the should not be next element.") {
        model.add(item1);
        auto item2 = std::make_shared<int>(2);
        model.add(item2);
        model.next();
        model.next();
        REQUIRE(model.hasNext() == false);
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
