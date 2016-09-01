#include <iostream>
#include <string>

#include "catch.hpp"
#include <List.h>

using namespace std;

TEST_CASE("List Test", "")
{
    SECTION("{1, 2, 3}")
    {
        List<int> list = List<int>();
        int listExpected [] = { 1, 2, 3 };
        list.push_front(3);
        list.push_front(2);
        list.push_front(1);

        auto i = 0;
        for (auto iter = list.cbegin(); iter != list.cend(); ++iter)
        {
            REQUIRE(*iter == listExpected[i]);
            ++i;
        }
    }
}
