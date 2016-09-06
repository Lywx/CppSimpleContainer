#include "catch.hpp"

#include <iostream>
#include <string>
#include <List.cpp>

using namespace std;

TEST_CASE("List Test", "")
{
    SECTION("clear")
    {
        auto list = List<int>();
        list.push_front(3);
        list.push_front(2);
        list.push_front(1);
        list.push_front(4);
        list.push_back(5);
        list.push_back(9);
        list.push_back(1);

        list.clear();
        REQUIRE(list.size() == 0);
    }

    SECTION("push_back, push_front, pop_back, pop_front")
    {
        auto list = List<int>();
        int  listExpected[] = { 1, 2, 3, 9, 1 };
        list.push_front(3);
        list.push_front(2);

        list.push_front(4);
        REQUIRE(list.pop_front() == 4);

        list.push_back(5);
        REQUIRE(list.pop_back() == 5);

        list.push_front(1);
        list.push_back(9);
        list.push_back(1);

        auto i = 0;
        for (auto iter = list.cbegin(); iter != list.cend(); ++iter)
        {
            REQUIRE(*iter == listExpected[i]);
            ++i;
        }
    }

    SECTION("push_front")
    {
        auto list = List<int>();
        int  listExpected[] = { 1, 2, 3 };
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
