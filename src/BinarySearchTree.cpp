#include "BinarySearchTree.h"

/************************************************************************/
/* Inner Class Implementation                                           */
/************************************************************************/
template <typename T>
BinarySearchTree<T>::const_iterator::const_iterator()
    : m_current(nullptr)
{
}

template <typename T>
BinarySearchTree<T>::const_iterator::const_iterator(Node *current)
    : m_current(current)
{
}

template <typename T>
BinarySearchTree<T>::const_iterator::~const_iterator()
{
}

template <typename T>
const T& BinarySearchTree<T>::const_iterator::operator*() const
{
    return m_current->item;
}

template <typename T>
typename BinarySearchTree<T>::const_iterator& BinarySearchTree<T>::const_iterator::operator++()
{
    return m_current->left != nullptr ? m_current->left : m_current->right;
}

template <typename T>
typename BinarySearchTree<T>::const_iterator& BinarySearchTree<T>::const_iterator::operator++(int)
{
    // TOOD
}

template <typename T>
typename BinarySearchTree<T>::const_iterator& BinarySearchTree<T>::const_iterator::operator--()
{
    // TOOD
}

template <typename T>
typename BinarySearchTree<T>::const_iterator& BinarySearchTree<T>::const_iterator::operator--(int)
{
    // TOOD
}

template <typename T>
bool BinarySearchTree<T>::const_iterator::operator==(const_iterator& rhs) const
{
    // TOOD
}

template <typename T>
bool BinarySearchTree<T>::const_iterator::operator==(const_iterator&& rhs) const
{
    // TOOD
}

template <typename T>
bool BinarySearchTree<T>::const_iterator::operator!=(const_iterator& rhs) const
{
    // TOOD
}

template <typename T>
bool BinarySearchTree<T>::const_iterator::operator!=(const_iterator&& rhs) const
{
    // TOOD
}

template <typename T>
T& BinarySearchTree<T>::const_iterator::retrieve() const
{
    // TOOD
}

template <typename T>
BinarySearchTree<T>::Node::Node(const T& item, Node *left, Node *right) :
    item(item),
    left(left),
    right(right)
{
}

template <typename T>
BinarySearchTree<T>::Node::Node(T&& item, Node *left, Node *right) :
    item(std::move(item)),
    left(left),
    right(right)
{
}

/************************************************************************/
/* Class Implementation                                                 */
/************************************************************************/
template <typename T>
BinarySearchTree<T>::BinarySearchTree() :
    root(nullptr)
{
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    clear();
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& rhs)
{
    root = clone(rhs.root);
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree& rhs)
{
    using std::swap;

    BinarySearchTree copy = rhs;
    swap(*this, copy);
    return *this;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree&& rhs) noexcept :
    root(rhs.root)
{
    rhs.root = nullptr;
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree&& rhs) noexcept
{
    using std::swap;

    swap(root, rhs.root);
    return *this;
}

template <typename T>
bool BinarySearchTree<T>::empty() const
{
    return root == nullptr;
}

template <typename T>
void BinarySearchTree<T>::clear()
{
    clear(root);
}

template <typename T>
const T& BinarySearchTree<T>::findMax() const
{
    auto *node = findMax(root);
    if (node != nullptr)
    {
        return node->item;
    }
    else
    {
        throw std::underflow_error("Bst is empty.");
    }
}

template <typename T>
const T& BinarySearchTree<T>::findMin() const
{
    auto *node = findMin(root);
    if (node != nullptr)
    {
        return node->item;
    }
    else
    {
        throw std::underflow_error("Bst is empty.");
    }
}

template <typename T>
bool BinarySearchTree<T>::contains(const T& item) const
{
    return contains(root, item);
}

template <typename T>
typename BinarySearchTree<T>::iterator BinarySearchTree<T>::find(const T& item) const
{
    // TODO
}

template <typename T>
void BinarySearchTree<T>::insert(const T& item)
{
    insert(root, item);
}

template <typename T>
void BinarySearchTree<T>::insert(T&& item)
{
    insert(root, std::move(item));
}

template <typename T>
void BinarySearchTree<T>::remove(const T& item)
{
    if (find(item))
    {
        // TODO
    }
}

template <typename T>
bool BinarySearchTree<T>::contains(const Node *node, const T& item)
{
    // TODO find?
    if (node == nullptr)
    {
        return false;
    }
    else if (node->item > item)
    {
        return contains(node->left);
    }
    else if (node->item < item)
    {
        return contains(node->right);
    }
    else
    {
        return true;
    }
}

// Non-recursive contains
/*
    template <typename T>
    bool Bst<T>::contains(const Node *node, const T& item)
    {
    while (node != nullptr)
    {
        if (node->item > item)
        {
            node = node->left;
        }
        else if (node->item < item)
        {
            node = node->right;
        }
        else
        {
            return true;
        }
    }

    return false;
    }
*/

template <typename T>
void BinarySearchTree<T>::clear(Node *node)
{
    if (node != nullptr)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }

    node = nullptr;
}

template <typename T>
typename BinarySearchTree<T>::Node *BinarySearchTree<T>::clone(Node *node) const
{
    // TODO
}

template <typename T>
const typename BinarySearchTree<T>::Node *BinarySearchTree<T>::findMax(Node *node) const
{
    while (node != nullptr && node->right != nullptr)
    {
        node = node->right;
    }

    return node;
}

template <typename T>
const typename BinarySearchTree<T>::Node *BinarySearchTree<T>::findMin(Node *node) const
{
    while (node != nullptr && node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}

template <typename T>
void BinarySearchTree<T>::insert(Node *&node, const T& item)
{
    if (node == nullptr)
    {
        node = new Node(item, nullptr, nullptr);
    }
    else if (node->item > item)
    {
        insert(node->left, item);
    }
    else if (node->item < item)
    {
        insert(node->right, item);
    }
    else
    {
        ; // Duplication
    }
}

template <typename T>
void BinarySearchTree<T>::insert(Node *&node, T&& item)
{
    if (node == nullptr)
    {
        node = new Node(item, nullptr, nullptr);
    }
    else if (node->item > item)
    {
        insert(node->left, std::move(item));
    }
    else if (node->item < item)
    {
        insert(node->right, std::move(item));
    }
    else
    {
        ; // Duplication
    }
}
