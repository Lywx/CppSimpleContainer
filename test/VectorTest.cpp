#include "catch.hpp"

#include <iostream>
#include <string>
#include <Vector.cpp>

using namespace std;

TEST_CASE("Vector Test", "")
{
    SECTION("clear")
    {
        auto vector = Vector<int>(10);
        vector.push_back(3);
        vector.push_back(2);
        vector.push_back(1);
        vector.push_back(4);
        vector.push_back(5);
        vector.push_back(9);
        vector.push_back(1);

        vector.clear();
        REQUIRE(vector.size() == 0);
    }

    SECTION("push_back")
    {
        auto vector = Vector<int>(10);
        int  vectorExpected[] = { 1, 2, 3 };
        vector.push_back(3);
        vector.push_back(2);
        vector.push_back(1);

        auto i = 0;
        for (auto iter = vector.cbegin(); iter != vector.cend(); ++iter)
        {
            REQUIRE(*iter == vectorExpected [i]);
            ++i;
        }
    }
}
