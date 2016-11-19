#include "catch.hpp"

#include <BinarySearchTree.cpp>

using namespace std;

void assert_preorder_traversal(BinarySearchTree<int>& bst, vector<int>& bstPreorderExpected, int line)
{
    auto bstPreorderIter = bst.cbegin_preorder();
    for (int i = 0; bstPreorderIter != bst.cend_preorder(); ++i, ++bstPreorderIter)
    {
        INFO("Line number: " + to_string(line));
        REQUIRE(*bstPreorderIter == bstPreorderExpected[i]);
    }
}

void assert_inorder_traversal(BinarySearchTree<int>& bst, vector<int>& bstInorderExpected, int line)
{
    auto bstInorderIter = bst.cbegin_inorder();
    for (int i = 0; bstInorderIter != bst.cend_inorder(); ++i, ++bstInorderIter)
    {
        INFO("Line number: " + to_string(line));
        REQUIRE(*bstInorderIter == bstInorderExpected[i]);
    }
}

void assert_postorder_traversal(BinarySearchTree<int>& bst, vector<int>& bstPostorderExpected, int line)
{
    auto bstPostorderIter = bst.cbegin_postorder();
    for (int i = 0; bstPostorderIter != bst.cend_postorder(); ++i, ++bstPostorderIter)
    {
        INFO("Line number: " + to_string(line));
        REQUIRE(*bstPostorderIter == bstPostorderExpected[i]);
    }
}

#define ASSERT_PREORDER_TRAVERSAL(bst, bstExpected) assert_preorder_traversal(bst, bstExpected, __LINE__);
#define ASSERT_INORDER_TRAVERSAL(bst, bstExpected) assert_inorder_traversal(bst, bstExpected, __LINE__);
#define ASSERT_POSTORDER_TRAVERSAL(bst, bstExpected) assert_postorder_traversal(bst, bstExpected, __LINE__);

TEST_CASE("BinarySearchTree Test", "")
{
    SECTION("clear, contains, empty, min, max, insert")
    {
        auto bst = BinarySearchTree<int>();

        bst.insert(3);
        REQUIRE(bst.min() == 3);
        REQUIRE(bst.max() == 3);

        REQUIRE(bst.contains(3));
        REQUIRE_FALSE(bst.empty());

        bst.insert(2);
        REQUIRE(bst.min() == 2);
        REQUIRE(bst.max() == 3);

        REQUIRE(bst.contains(2));
        REQUIRE(bst.contains(3));
        REQUIRE_FALSE(bst.empty());

        bst.insert(1);
        bst.insert(4);
        REQUIRE(bst.min() == 1);
        REQUIRE(bst.max() == 4);

        REQUIRE(bst.contains(1));
        REQUIRE(bst.contains(2));
        REQUIRE(bst.contains(3));
        REQUIRE(bst.contains(4));

        REQUIRE_FALSE(bst.empty());

        bst.insert(5);
        bst.insert(9);
        REQUIRE(bst.min() == 1);
        REQUIRE(bst.max() == 9);

        REQUIRE(bst.contains(1));
        REQUIRE(bst.contains(2));
        REQUIRE(bst.contains(3));
        REQUIRE(bst.contains(4));
        REQUIRE(bst.contains(5));
        REQUIRE(bst.contains(9));

        REQUIRE_FALSE(bst.empty());

        bst.clear();
        REQUIRE(bst.empty());

        REQUIRE_THROWS(bst.find_min());
        REQUIRE_THROWS(bst.find_max());

        REQUIRE_NOTHROW(bst.clear());
    }

    SECTION("find, find_max, find_min, insert, remove, preorder iterator, inorder iterator, postorder iterator")
    {
        auto bst = BinarySearchTree<int>();

        // 1
        //   2
        //     3
        bst.insert(1);
        bst.insert(2);
        bst.insert(3);
        vector<int> bstPreorderExpected  = { 1, 2, 3 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        vector<int> bstInorderExpected   = { 1, 2, 3 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        vector<int> bstPostorderExpected = { 3, 2, 1 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);

        bst.remove(2);
        // 1
        //   3
        bstPreorderExpected = { 1, 3 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        bstInorderExpected  = { 1, 3 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        bstPostorderExpected = { 3, 1 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);

        bst = BinarySearchTree<int>();
        bst.insert(5);
        bst.insert(1);
        bst.insert(6);
        bst.insert(7);

        //   5
        // 1   6
        //       7
        bstPreorderExpected = { 5, 1, 6, 7 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        bstInorderExpected  = { 1, 5, 6, 7 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        bstPostorderExpected = { 1, 7, 6, 5 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);

        bst.remove(5);
        //   6
        // 1   7
        bstPreorderExpected = { 6, 1, 7 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        bstInorderExpected  = { 1, 6, 7 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        bstPostorderExpected = { 1, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);

        bst.remove(1);
        //   6
        //     7
        bstPreorderExpected = { 6, 7 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        bstInorderExpected  = { 6, 7 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        bstPostorderExpected = { 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);

        bst.insert(10);
        //   6
        //     7
        //       10
        bstPreorderExpected = { 6, 7, 10 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        bstInorderExpected  = { 6, 7, 10 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        bstPostorderExpected = { 10, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);

        bst.insert(8);
        //   6
        //     7
        //       10
        //     8
        bstPreorderExpected = { 6, 7, 10, 8 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        bstInorderExpected  = { 6, 7, 8, 10 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        bstPostorderExpected = { 8, 10, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);

        bst.insert(9);
        //   6
        //     7
        //       10
        //     8
        //       9
        bstPreorderExpected = { 6, 7, 10, 8, 9 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        bstInorderExpected  = { 6, 7, 8, 9, 10 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        bstPostorderExpected = { 9, 8, 10, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);

        auto *node = bst.find(10);
        REQUIRE(node->left->item == 8);
        REQUIRE(node->left->right->item == 9);

        node = bst.find_min();
        REQUIRE(node->item == 6);

        node = bst.find_max();
        REQUIRE(node->item == 10);

        bst.insert(11);
        //   6
        //     7
        //       10
        //     8    11
        //       9
        bstPreorderExpected = { 6, 7, 10, 8, 9, 11 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        bstInorderExpected  = { 6, 7, 8, 9, 10, 11 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        bstPostorderExpected = { 9, 8, 11, 10, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);

        bst.insert(15);
        //   6
        //     7
        //       10
        //     8    11
        //       9     15
        bstPreorderExpected = { 6, 7, 10, 8, 9, 11, 15 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        bstInorderExpected  = { 6, 7, 8, 9, 10, 11, 15 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        bstPostorderExpected = { 9, 8, 15, 11, 10, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);

        bst.insert(12);
        //   6
        //     7
        //       10
        //     8    11
        //       9     15
        //          12
        bstPreorderExpected = { 6, 7, 10, 8, 9, 11, 15, 12 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        bstInorderExpected  = { 6, 7, 8, 9, 10, 11, 12, 15 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        bstPostorderExpected = { 9, 8, 12, 15, 11, 10, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);

        bst.remove(10);
        //   6
        //     7
        //       11
        //     8    15
        //      9  12
        bstPreorderExpected = { 6, 7, 11, 8, 9, 15, 12 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        bstInorderExpected  = { 6, 7, 8, 9, 11, 12, 15 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        bstPostorderExpected = { 9, 8, 12, 15, 11, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);

        bst = BinarySearchTree<int>();
        bst.insert(11);
        bst.insert(9);
        bst.insert(13);
        bst.insert(8);
        bst.insert(10);
        bst.insert(12);
        bst.insert(14);
        //     11
        //   9    13
        // 8  10 12 14
        bstPreorderExpected = { 11, 9, 8, 10, 13, 12, 14 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        bstInorderExpected  = { 8, 9, 10, 11, 12, 13, 14 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        bstPostorderExpected = { 8, 10, 9, 12, 14, 13, 11 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);

        bst.remove(11);
        //     12
        //   9    13
        // 8  10    14
        bstPreorderExpected = { 12, 9, 8, 10, 13, 14 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        bstInorderExpected  = { 8, 9, 10, 12, 13, 14 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        bstPostorderExpected = { 8, 10, 9, 14, 13, 12 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);
    }

    SECTION("copy constructor, clone")
    {
        auto bst = BinarySearchTree<int>();
        bst.insert(11);
        bst.insert(9);
        bst.insert(13);
        bst.insert(8);
        bst.insert(10);
        bst.insert(12);
        bst.insert(14);
        //     11
        //   9    13
        // 8  10 12 14
        vector<int> bstPreorderExpected = { 11, 9, 8, 10, 13, 12, 14 };
        ASSERT_PREORDER_TRAVERSAL(bst, bstPreorderExpected);
        vector<int> bstInorderExpected  = { 8, 9, 10, 11, 12, 13, 14 };
        ASSERT_INORDER_TRAVERSAL(bst, bstInorderExpected);
        vector<int> bstPostorderExpected = { 8, 10, 9, 12, 14, 13, 11 };
        ASSERT_POSTORDER_TRAVERSAL(bst, bstPostorderExpected);

        auto bstClone = BinarySearchTree<int>(bst);
        ASSERT_PREORDER_TRAVERSAL(bstClone, bstPreorderExpected);
        ASSERT_INORDER_TRAVERSAL(bstClone, bstInorderExpected);
        ASSERT_POSTORDER_TRAVERSAL(bstClone, bstPostorderExpected);
    }
}
