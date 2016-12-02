#include "AvlTree.h"
#include <cassert>
#include <utility>

using namespace std;

template <typename T>
AvlTree<T>::Node::Node(const T& item, Node *left, Node *right, int height)
    : BinarySearchTree<T>::Node(item, left, right),
      height(height)
{
}

template <typename T>
AvlTree<T>::Node::Node(T&& item, Node *left, Node *right, int height)
    : BinarySearchTree<T>::Node(move(item), left, right),
      height(height)
{
}

template <typename T>
AvlTree<T>::const_iterator::const_iterator()
{
}

template <typename T>
AvlTree<T>::const_iterator::const_iterator(Node *current)
    : BinarySearchTree<T>::const_iterator(current)
{
}

template <typename T>
AvlTree<T>::const_preorder_iterator::const_preorder_iterator()
{
}

template <typename T>
AvlTree<T>::const_preorder_iterator::const_preorder_iterator(Node *current)
    : BinarySearchTree<T>::const_preorder_iterator(current)
{
}

template <typename T>
AvlTree<T>::const_inorder_iterator::const_inorder_iterator()
{
}

template <typename T>
AvlTree<T>::const_inorder_iterator::const_inorder_iterator(Node *current)
    : BinarySearchTree<T>::const_inorder_iterator(current)
{
}

template <typename T>
AvlTree<T>::const_postorder_iterator::const_postorder_iterator()
{
}

template <typename T>
AvlTree<T>::const_postorder_iterator::const_postorder_iterator(Node *current)
    : BinarySearchTree<T>::const_postorder_iterator(current)
{
}

template <typename T>
AvlTree<T>::AvlTree()
{
}

template <typename T>
typename AvlTree<T>::const_preorder_iterator AvlTree<T>::cbegin_preorder() const
{
    Node *root = dynamic_cast<Node *>(m_root);
    assert(root != nullptr);

    return root;
}

template <typename T>
typename AvlTree<T>::const_preorder_iterator AvlTree<T>::cend_preorder() const
{
    return nullptr;
}

template <typename T>
typename AvlTree<T>::const_inorder_iterator AvlTree<T>::cbegin_inorder() const
{
    Node *root = dynamic_cast<Node *>(m_root);
    assert(root != nullptr);

    return root;
}

template <typename T>
typename AvlTree<T>::const_inorder_iterator AvlTree<T>::cend_inorder() const
{
    return nullptr;
}

template <typename T>
typename AvlTree<T>::const_postorder_iterator AvlTree<T>::cbegin_postorder() const
{
    Node *root = dynamic_cast<Node *>(m_root);
    assert(root != nullptr);

    return root;
}

template <typename T>
typename AvlTree<T>::const_postorder_iterator AvlTree<T>::cend_postorder() const
{
    return nullptr;
}

template <typename T>
int AvlTree<T>::height(Node *node) const
{
    // -1 is required here in the definition
    return node != nullptr ? node->height : -1;
}

template <typename T>
void AvlTree<T>::insert(const T& item)
{

}

template <typename T>
void AvlTree<T>::insert(T&& item)
{
}

template <typename T>
void AvlTree<T>::remove(const T& item)
{
}
