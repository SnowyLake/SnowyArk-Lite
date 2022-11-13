#include <iostream>
#include "ArkSoftRenderer.h"

int main()
{
    ArkLite::Math::Vector<4, float> vec{};
    ArkLite::Math::Vector<vec.GetDimension(), decltype(vec)::ValueType> vec2{};
    std::cout << vec.GetDimension();
}

