#include "catch.hpp"

#include <AvlTree.cpp>

using namespace std;

void assert_preorder_traversal(AvlTree<int>& avl, vector<int>& avlPreorderExpected, int line)
{
    auto avlPreorderIter = avl.cbegin_preorder();
    for (int i = 0; avlPreorderIter != avl.cend_preorder(); ++i, ++avlPreorderIter)
    {
        INFO("Line number: " + to_string(line));
        REQUIRE(*avlPreorderIter == avlPreorderExpected[i]);
    }
}

void assert_inorder_traversal(AvlTree<int>& avl, vector<int>& avlInorderExpected, int line)
{
    auto avlInorderIter = avl.cbegin_inorder();
    for (int i = 0; avlInorderIter != avl.cend_inorder(); ++i, ++avlInorderIter)
    {
        INFO("Line number: " + to_string(line));
        REQUIRE(*avlInorderIter == avlInorderExpected[i]);
    }
}

void assert_postorder_traversal(AvlTree<int>& avl, vector<int>& avlPostorderExpected, int line)
{
    auto avlPostorderIter = avl.cbegin_postorder();
    for (int i = 0; avlPostorderIter != avl.cend_postorder(); ++i, ++avlPostorderIter)
    {
        INFO("Line number: " + to_string(line));
        REQUIRE(*avlPostorderIter == avlPostorderExpected[i]);
    }
}

#define ASSERT_PREORDER_TRAVERSAL(avl, avlExpected) assert_preorder_traversal(avl, avlExpected, __LINE__);
#define ASSERT_INORDER_TRAVERSAL(avl, avlExpected) assert_inorder_traversal(avl, avlExpected, __LINE__);
#define ASSERT_POSTORDER_TRAVERSAL(avl, avlExpected) assert_postorder_traversal(avl, avlExpected, __LINE__);

TEST_CASE("AVLTree Test", "")
{
    SECTION("clear, contains, empty, min, max, insert")
    {
        auto avl = AvlTree<int>();

        avl.insert(3);
        REQUIRE(avl.min() == 3);
        REQUIRE(avl.max() == 3);

        REQUIRE(avl.contains(3));
        REQUIRE_FALSE(avl.empty());

        avl.insert(2);
        REQUIRE(avl.min() == 2);
        REQUIRE(avl.max() == 3);

        REQUIRE(avl.contains(2));
        REQUIRE(avl.contains(3));
        REQUIRE_FALSE(avl.empty());

        avl.insert(1);
        avl.insert(4);
        REQUIRE(avl.min() == 1);
        REQUIRE(avl.max() == 4);

        REQUIRE(avl.contains(1));
        REQUIRE(avl.contains(2));
        REQUIRE(avl.contains(3));
        REQUIRE(avl.contains(4));

        REQUIRE_FALSE(avl.empty());

        avl.insert(5);
        avl.insert(9);
        REQUIRE(avl.min() == 1);
        REQUIRE(avl.max() == 9);

        REQUIRE(avl.contains(1));
        REQUIRE(avl.contains(2));
        REQUIRE(avl.contains(3));
        REQUIRE(avl.contains(4));
        REQUIRE(avl.contains(5));
        REQUIRE(avl.contains(9));

        REQUIRE_FALSE(avl.empty());

        avl.clear();
        REQUIRE(avl.empty());

        REQUIRE_THROWS(avl.find_min());
        REQUIRE_THROWS(avl.find_max());

        REQUIRE_NOTHROW(avl.clear());
    }

    SECTION("find, find_max, find_min, insert, remove, preorder iterator, inorder iterator, postorder iterator")
    {
        auto avl = AvlTree<int>();

        // 1
        //   2
        //     3
        avl.insert(1);
        avl.insert(2);
        avl.insert(3);
        vector<int> avlPreorderExpected = { 1, 2, 3 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        vector<int> avlInorderExpected = { 1, 2, 3 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        vector<int> avlPostorderExpected = { 3, 2, 1 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);

        avl.remove(2);
        // 1
        //   3
        avlPreorderExpected = { 1, 3 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        avlInorderExpected = { 1, 3 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        avlPostorderExpected = { 3, 1 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);

        avl = AvlTree<int>();
        avl.insert(5);
        avl.insert(1);
        avl.insert(6);
        avl.insert(7);

        //   5
        // 1   6
        //       7
        avlPreorderExpected = { 5, 1, 6, 7 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        avlInorderExpected = { 1, 5, 6, 7 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        avlPostorderExpected = { 1, 7, 6, 5 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);

        avl.remove(5);
        //   6
        // 1   7
        avlPreorderExpected = { 6, 1, 7 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        avlInorderExpected = { 1, 6, 7 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        avlPostorderExpected = { 1, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);

        avl.remove(1);
        //   6
        //     7
        avlPreorderExpected = { 6, 7 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        avlInorderExpected = { 6, 7 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        avlPostorderExpected = { 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);

        avl.insert(10);
        //   6
        //     7
        //       10
        avlPreorderExpected = { 6, 7, 10 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        avlInorderExpected = { 6, 7, 10 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        avlPostorderExpected = { 10, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);

        avl.insert(8);
        //   6
        //     7
        //       10
        //     8
        avlPreorderExpected = { 6, 7, 10, 8 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        avlInorderExpected = { 6, 7, 8, 10 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        avlPostorderExpected = { 8, 10, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);

        avl.insert(9);
        //   6
        //     7
        //       10
        //     8
        //       9
        avlPreorderExpected = { 6, 7, 10, 8, 9 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        avlInorderExpected = { 6, 7, 8, 9, 10 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        avlPostorderExpected = { 9, 8, 10, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);

        auto *node = avl.find(10);
        REQUIRE(node->left->item == 8);
        REQUIRE(node->left->right->item == 9);

        node = avl.find_min();
        REQUIRE(node->item == 6);

        node = avl.find_max();
        REQUIRE(node->item == 10);

        avl.insert(11);
        //   6
        //     7
        //       10
        //     8    11
        //       9
        avlPreorderExpected = { 6, 7, 10, 8, 9, 11 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        avlInorderExpected = { 6, 7, 8, 9, 10, 11 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        avlPostorderExpected = { 9, 8, 11, 10, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);

        avl.insert(15);
        //   6
        //     7
        //       10
        //     8    11
        //       9     15
        avlPreorderExpected = { 6, 7, 10, 8, 9, 11, 15 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        avlInorderExpected = { 6, 7, 8, 9, 10, 11, 15 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        avlPostorderExpected = { 9, 8, 15, 11, 10, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);

        avl.insert(12);
        //   6
        //     7
        //       10
        //     8    11
        //       9     15
        //          12
        avlPreorderExpected = { 6, 7, 10, 8, 9, 11, 15, 12 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        avlInorderExpected = { 6, 7, 8, 9, 10, 11, 12, 15 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        avlPostorderExpected = { 9, 8, 12, 15, 11, 10, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);

        avl.remove(10);
        //   6
        //     7
        //       11
        //     8    15
        //      9  12
        avlPreorderExpected = { 6, 7, 11, 8, 9, 15, 12 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        avlInorderExpected = { 6, 7, 8, 9, 11, 12, 15 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        avlPostorderExpected = { 9, 8, 12, 15, 11, 7, 6 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);

        avl = AvlTree<int>();
        avl.insert(11);
        avl.insert(9);
        avl.insert(13);
        avl.insert(8);
        avl.insert(10);
        avl.insert(12);
        avl.insert(14);
        //     11
        //   9    13
        // 8  10 12 14
        avlPreorderExpected = { 11, 9, 8, 10, 13, 12, 14 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        avlInorderExpected = { 8, 9, 10, 11, 12, 13, 14 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        avlPostorderExpected = { 8, 10, 9, 12, 14, 13, 11 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);

        avl.remove(11);
        //     12
        //   9    13
        // 8  10    14
        avlPreorderExpected = { 12, 9, 8, 10, 13, 14 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        avlInorderExpected = { 8, 9, 10, 12, 13, 14 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        avlPostorderExpected = { 8, 10, 9, 14, 13, 12 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);
    }

    SECTION("copy constructor, clone")
    {
        auto avl = AvlTree<int>();
        avl.insert(11);
        avl.insert(9);
        avl.insert(13);
        avl.insert(8);
        avl.insert(10);
        avl.insert(12);
        avl.insert(14);
        //     11
        //   9    13
        // 8  10 12 14
        vector<int> avlPreorderExpected = { 11, 9, 8, 10, 13, 12, 14 };
        ASSERT_PREORDER_TRAVERSAL(avl, avlPreorderExpected);
        vector<int> avlInorderExpected = { 8, 9, 10, 11, 12, 13, 14 };
        ASSERT_INORDER_TRAVERSAL(avl, avlInorderExpected);
        vector<int> avlPostorderExpected = { 8, 10, 9, 12, 14, 13, 11 };
        ASSERT_POSTORDER_TRAVERSAL(avl, avlPostorderExpected);

        auto avlClone = AvlTree<int>(avl);
        ASSERT_PREORDER_TRAVERSAL(avlClone, avlPreorderExpected);
        ASSERT_INORDER_TRAVERSAL(avlClone, avlInorderExpected);
        ASSERT_POSTORDER_TRAVERSAL(avlClone, avlPostorderExpected);
    }
}
