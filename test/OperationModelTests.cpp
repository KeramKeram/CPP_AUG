#include <catch2/catch.hpp>
#include "models/OperationModel.h"

TEST_CASE("Models with data", "[operationsmodel]")
{
    models::OperationModel<int> model;
    auto item1 = std::make_shared<int>(1);
    model.add(item1);
    SECTION("Test has next with one element.") {
        REQUIRE(model.hasNext() == true);
    }

    SECTION("Test take one element from one element model and check if has next.") {
        model.next();
        REQUIRE(model.hasNext() == false);
    }

    auto item2 = std::make_shared<int>(2);
    model.add(item2);

    SECTION("Test checking if returned first element is correct.") {
        auto item = model.next();
        REQUIRE(*item == 1);
    }

    SECTION("Test checking if returned last element is correct.") {
        auto item = model.next();
        item = model.next();
        REQUIRE(*item == 2);
    }

    SECTION("Test has next with two element.") {
        REQUIRE(model.hasNext() == true);
    }

    SECTION("Test with two element on the should not be next element.") {
        model.next();
        model.next();
        REQUIRE(model.hasNext() == false);
    }

    SECTION("Test resetting iterator.") {
        model.next();
        model.next();
        model.resetIterator();
        REQUIRE(model.hasNext() == true);
    }

    SECTION("Test resetting iterator and check if correct value is return.") {
        model.add(item2);
        auto item = model.next();
        REQUIRE(*item == 1);
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
