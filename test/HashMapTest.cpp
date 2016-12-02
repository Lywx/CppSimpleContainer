#include "catch.hpp"

#include <iostream>
#include <string>
#include <HashMap.cpp>

using namespace std;

TEST_CASE("HashMap Test", "")
{
    SECTION("")
    {
        CloseHashMap<int, int> a;
        a.find(1);
    }
}
