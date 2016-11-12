#pragma once

template<typename T>
class BinaryTree
{
    struct Node
    {
        T     item;
        Node *left;
        Node *right;

        Node(const T& item, Node *left, Node *right);
        Node(T&& item, Node *left, Node *right);
    };

    BinaryTree();
    ~BinaryTree();
};

