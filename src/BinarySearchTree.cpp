#include "BinarySearchTree.h"

#include <algorithm>
#include <stdexcept>
#include <utility>

/************************************************************************/
/* Inner Class Implementation                                           */
/************************************************************************/
template <typename T>
BinarySearchTree<T>::const_iterator::const_iterator()
    : m_traversalTaskStack(),
      m_iterationNodeCurrent(nullptr)
{
}

template <typename T>
BinarySearchTree<T>::const_iterator::const_iterator(Node *current)
    : m_traversalTaskStack(),
      m_iterationNodeCurrent(nullptr)
{
    if (current != nullptr)
    {
        m_traversalTaskStack.emplace(current, 0);
    }
}

template <typename T>
BinarySearchTree<T>::const_iterator::~const_iterator()
{
    while (!m_traversalTaskStack.empty())
    {
        m_traversalTaskStack.pop();
    }
}

template <typename T>
const T& BinarySearchTree<T>::const_iterator::operator*() const
{
    return m_iterationNodeCurrent->item;
}

template <typename T>
bool BinarySearchTree<T>::const_iterator::operator==(const_iterator& rhs) const
{
    return m_iterationNodeCurrent == rhs.m_iterationNodeCurrent
           && m_traversalTaskStack == rhs.m_traversalTaskStack;
}

template <typename T>
bool BinarySearchTree<T>::const_iterator::operator==(const_iterator&& rhs) const
{
    return m_iterationNodeCurrent == rhs.m_iterationNodeCurrent
           && m_traversalTaskStack == rhs.m_traversalTaskStack;
}

template <typename T>
bool BinarySearchTree<T>::const_iterator::operator!=(const_iterator& rhs) const
{
    return !(*this == rhs);
}

template <typename T>
bool BinarySearchTree<T>::const_iterator::operator!=(const_iterator&& rhs) const
{
    return !(*this == rhs);
}
template <typename T>
T& BinarySearchTree<T>::const_iterator::retrieve() const
{
    return m_iterationNodeCurrent->item;
}

template <typename T>
BinarySearchTree<T>::const_preorder_iterator::const_preorder_iterator()
{
}

template <typename T>
BinarySearchTree<T>::const_preorder_iterator::const_preorder_iterator(Node *current)
    : const_iterator(current)
{
    ++(*this);
}

template <typename T>
typename BinarySearchTree<T>::const_preorder_iterator& BinarySearchTree<T>::const_preorder_iterator::operator++()
{
    if (m_traversalTaskStack.empty())
    {
        m_iterationNodeCurrent = nullptr;
        return *this;
    }

    m_iterationNodeCurrent = m_traversalTaskStack.top().first;
    m_traversalTaskStack.pop();

    if (m_iterationNodeCurrent->right != nullptr)
    {
        m_traversalTaskStack.emplace(m_iterationNodeCurrent->right, 0);
    }

    if (m_iterationNodeCurrent->left != nullptr)
    {
        m_traversalTaskStack.emplace(m_iterationNodeCurrent->left, 0);
    }

    return *this;
}

template <typename T>
typename BinarySearchTree<T>::const_preorder_iterator BinarySearchTree<T>::const_preorder_iterator::operator++(int)
{
    auto old = *this;
    ++(*this);
    return old;
}

template <typename T>
BinarySearchTree<T>::const_inorder_iterator::const_inorder_iterator()
{
}

template <typename T>
BinarySearchTree<T>::const_inorder_iterator::const_inorder_iterator(Node *current)
    : const_iterator(current)
{
    // Allow the m_iterationNodeCurrent become ready to use after initialization
    if (current != nullptr)
    {
        ++(*this);
    }
}

template <typename T>
typename BinarySearchTree<T>::const_inorder_iterator& BinarySearchTree<T>::const_inorder_iterator::operator++()
{
    if (m_traversalTaskStack.empty())
    {
        m_iterationNodeCurrent = nullptr;
        return *this;
    }

    auto traversalNodeUpdated = false;
    while(!traversalNodeUpdated)
    {
        auto traversalTaskCurrent = m_traversalTaskStack.top();
        m_traversalTaskStack.pop();
        auto traversalNodeCurrent = traversalTaskCurrent.first;
        auto& traversalTaskVisit = traversalTaskCurrent.second;

        if (++traversalTaskVisit == 1)
        {
            m_traversalTaskStack.push(traversalTaskCurrent);

            if (traversalNodeCurrent->left != nullptr)
            {
                m_traversalTaskStack.emplace(traversalNodeCurrent->left, 0);
            }
        }
        else if (traversalTaskVisit == 2)
        {
            m_iterationNodeCurrent = traversalNodeCurrent;
            traversalNodeUpdated = true;

            if (traversalNodeCurrent->right != nullptr)
            {
                m_traversalTaskStack.emplace(traversalNodeCurrent->right, 0);
            }
        }
    }

    return *this;
}

template <typename T>
typename BinarySearchTree<T>::const_inorder_iterator BinarySearchTree<T>::const_inorder_iterator::operator++(int)
{
    auto old = *this;
    ++(*this);
    return old;
}

template <typename T>
BinarySearchTree<T>::const_postorder_iterator::const_postorder_iterator()
{
}

template <typename T>
BinarySearchTree<T>::const_postorder_iterator::const_postorder_iterator(Node *current)
    : const_iterator(current)
{
    // Allow the m_iterationNodeCurrent become ready to use after initialization
    if (current != nullptr)
    {
        ++(*this);
    }
}

template <typename T>
typename BinarySearchTree<T>::const_postorder_iterator& BinarySearchTree<T>::const_postorder_iterator::operator++()
{
    if (m_traversalTaskStack.empty())
    {
        m_iterationNodeCurrent = nullptr;
        return *this;
    }

    auto traversalNodeUpdated = false;
    while(!traversalNodeUpdated)
    {
        auto traversalTaskCurrent = m_traversalTaskStack.top();
        m_traversalTaskStack.pop();
        auto traversalNodeCurrent = traversalTaskCurrent.first;
        auto& traversalTaskVisit = traversalTaskCurrent.second;

        if (++traversalTaskVisit == 1)
        {
            m_traversalTaskStack.push(traversalTaskCurrent);

            if (traversalNodeCurrent->left != nullptr)
            {
                m_traversalTaskStack.emplace(traversalNodeCurrent->left, 0);
            }
        }
        else if (traversalTaskVisit == 2)
        {
            m_traversalTaskStack.push(traversalTaskCurrent);

            if (traversalNodeCurrent->right != nullptr)
            {
                m_traversalTaskStack.emplace(traversalNodeCurrent->right, 0);
            }
        }
        else
        {
            m_iterationNodeCurrent = traversalNodeCurrent;
            traversalNodeUpdated = true;
        }
    }

    return *this;
}

template <typename T>
typename BinarySearchTree<T>::const_postorder_iterator BinarySearchTree<T>::const_postorder_iterator::operator++(int)
{
    auto old = *this;
    ++(*this);
    return old;
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
    m_root(nullptr)
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
    m_root = clone(rhs.m_root);
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
    m_root(rhs.m_root)
{
    rhs.m_root = nullptr;
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree&& rhs) noexcept
{
    using std::swap;

    swap(m_root, rhs.m_root);
    return *this;
}

template <typename T>
typename BinarySearchTree<T>::const_preorder_iterator BinarySearchTree<T>::cbegin_preorder() const
{
    return m_root;
}

template <typename T>
typename BinarySearchTree<T>::const_preorder_iterator BinarySearchTree<T>::cend_preorder() const
{
    return nullptr;
}

template <typename T>
typename BinarySearchTree<T>::const_inorder_iterator BinarySearchTree<T>::cbegin_inorder() const
{
    return m_root;
}

template <typename T>
typename BinarySearchTree<T>::const_inorder_iterator BinarySearchTree<T>::cend_inorder() const
{
    return nullptr;
}

template <typename T>
typename BinarySearchTree<T>::const_postorder_iterator BinarySearchTree<T>::cbegin_postorder() const
{
    return m_root;
}

template <typename T>
typename BinarySearchTree<T>::const_postorder_iterator BinarySearchTree<T>::cend_postorder() const
{
    return nullptr;
}

template <typename T>
bool BinarySearchTree<T>::empty() const
{
    return m_root == nullptr;
}

template <typename T>
void BinarySearchTree<T>::clear()
{
    clear(m_root);
}

template <typename T>
const T& BinarySearchTree<T>::max() const
{
    auto *node = find_max();
    return node->item;
}

template <typename T>
const T& BinarySearchTree<T>::min() const
{
    auto *node = find_min();
    return node->item;
}

template <typename T>
const typename BinarySearchTree<T>::Node *BinarySearchTree<T>::find_max() const
{
    if (empty())
    {
        throw std::underflow_error("Binary search tree is empty.");
    }

    return find_max(m_root);
}

template <typename T>
const typename BinarySearchTree<T>::Node *BinarySearchTree<T>::find_min() const
{
    if (empty())
    {
        throw std::underflow_error("Binary search tree is empty.");
    }

    return find_min(m_root);
}

template <typename T>
const typename BinarySearchTree<T>::Node *BinarySearchTree<T>::root() const
{
    return m_root;
}

template <typename T>
bool BinarySearchTree<T>::contains(const T& item) const
{
    return contains(m_root, item);
}

template <typename T>
const typename BinarySearchTree<T>::Node *BinarySearchTree<T>::find(const T& item) const
{
    return find(m_root, item);
}

template <typename T>
void BinarySearchTree<T>::insert(const T& item)
{
    insert(m_root, item);
}

template <typename T>
void BinarySearchTree<T>::insert(T&& item)
{
    insert(m_root, std::move(item));
}

template <typename T>
void BinarySearchTree<T>::remove(const T& item)
{
    remove(m_root, item);
}

template <typename T>
bool BinarySearchTree<T>::contains(const Node *node, const T& item) const
{
    if (node == nullptr)
    {
        return false;
    }
    else if (node->item > item)
    {
        return contains(node->left, item);
    }
    else if (node->item < item)
    {
        return contains(node->right, item);
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
void BinarySearchTree<T>::clear(Node *&node)
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
const typename BinarySearchTree<T>::Node *BinarySearchTree<T>::find(const Node *node, const T& item) const
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
            return node;
        }
    }

    return nullptr;
}

template <typename T>
const typename BinarySearchTree<T>::Node *BinarySearchTree<T>::find_max(const Node *node) const
{
    while (node != nullptr && node->right != nullptr)
    {
        node = node->right;
    }

    return node;
}

template <typename T>
const typename BinarySearchTree<T>::Node *BinarySearchTree<T>::find_min(const Node *node) const
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

template <typename T>
void BinarySearchTree<T>::remove(Node *&node, const T& item)
{
    if (node == nullptr)
    {
        return;
    }

    if (item < node->item)
    {
        remove(node->left, item);
    }
    else if (item > node->item)
    {
        remove(node->right, item);
    }

    // When node has two children
    else if (node->left != nullptr && node->right != nullptr)
    {
        node->item = find_min(node->right)->item;
        remove(node->right, node->item);
    }

    // When node has only one child
    else
    {
        Node *nodeFound = node;
        node = (node->left != nullptr)
               ? node->left
               : node->right;
        delete nodeFound;
    }

}
