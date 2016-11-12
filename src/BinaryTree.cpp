#include "BinaryTree.h"

#include <utility>

using namespace std;

/************************************************************************/
/* Inner Class Implementation                                           */
/************************************************************************/
template <typename T>
BinaryTree<T>::Node::Node(const T& item, Node *left, Node *right) :
    item(item),
    left(left),
    right(right)
{
}

template <typename T>
BinaryTree<T>::Node::Node(T&& item, Node *left, Node *right) :
    item(std::move(item)),
    left(left),
    right(right)
{
}

/************************************************************************/
/* Class Implementation                                                 */
/************************************************************************/
template <typename T>
BinaryTree<T>::BinaryTree()
{
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
}
