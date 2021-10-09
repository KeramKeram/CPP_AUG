#pragma once

#include <type_traits>

// Function for enum conersion to type
template<typename E>
constexpr auto toUnderlyingType(E e)
{
    return static_cast<typename std::underlying_type<E>::type>(e);
}

enum class RotateCode {
    ROTATE_90 = 90,
    ROTATE_180 = 180,
    ROTATE_270 = 270
};

