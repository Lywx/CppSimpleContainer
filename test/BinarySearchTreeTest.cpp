#include "catch.hpp"

#include <BinarySearchTree.cpp>

using namespace std;
TEST_CASE("BinarySearchTree Test", "")
{
    SECTION("clear, find, ")
    {
        auto bst = BinarySearchTree<int>();
        bst.insert(3);

        REQUIRE(bst.findMin() == 3);

        bst.insert(2);
        bst.insert(1);
        bst.insert(4);
        bst.insert(5);
        bst.insert(9);
        bst.insert(1);

        bst.clear();
    }

    SECTION("insert")
    {
        auto bst = BinarySearchTree<int>();
        int  vectorExpected[] = { 1, 2, 3 };
        bst.insert(1);
        bst.insert(2);
        bst.insert(3);

        auto i = 0;
    }

    SECTION("")
    {

    }
}
