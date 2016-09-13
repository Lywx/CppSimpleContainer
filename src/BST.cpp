#include "Bst.h"

/************************************************************************/
/* Inner Class Implementation                                           */
/************************************************************************/
template <typename T>
Bst<T>::const_iterator::const_iterator()
    : m_current(nullptr)
{
}

template <typename T>
Bst<T>::const_iterator::const_iterator(Node *current)
    : m_current(current)
{
}

template <typename T>
Bst<T>::const_iterator::~const_iterator()
{
}

template <typename T>
const T& Bst<T>::const_iterator::operator*() const
{
    return m_current->item;
}

template <typename T>
typename Bst<T>::const_iterator& Bst<T>::const_iterator::operator++()
{
    return m_current->left != nullptr ? m_current->left : m_current->right;
}

template <typename T>
typename Bst<T>::const_iterator& Bst<T>::const_iterator::operator++(int)
{
    // TOOD
}

template <typename T>
typename Bst<T>::const_iterator& Bst<T>::const_iterator::operator--()
{
    // TOOD
}

template <typename T>
typename Bst<T>::const_iterator& Bst<T>::const_iterator::operator--(int)
{
    // TOOD
}

template <typename T>
bool Bst<T>::const_iterator::operator==(const_iterator& rhs) const
{
    // TOOD
}

template <typename T>
bool Bst<T>::const_iterator::operator==(const_iterator&& rhs) const
{
    // TOOD
}

template <typename T>
bool Bst<T>::const_iterator::operator!=(const_iterator& rhs) const
{
    // TOOD
}

template <typename T>
bool Bst<T>::const_iterator::operator!=(const_iterator&& rhs) const
{
    // TOOD
}

template <typename T>
T& Bst<T>::const_iterator::retrieve() const
{
    // TOOD
}

template <typename T>
Bst<T>::Node::Node(const T& item, Node *left, Node *right) :
    item(item),
    left(left),
    right(right)
{
}

template <typename T>
Bst<T>::Node::Node(T&& item, Node *left, Node *right) :
    item(std::move(item)),
    left(left),
    right(right)
{
}

/************************************************************************/
/* Class Implementation                                                 */
/************************************************************************/
template <typename T>
Bst<T>::Bst() :
    root(nullptr)
{
}

template <typename T>
Bst<T>::~Bst()
{
    clear();
}

template <typename T>
Bst<T>::Bst(const Bst& rhs)
{
    root = clone(rhs.root);
}

template <typename T>
Bst<T>& Bst<T>::operator=(const Bst& rhs)
{
    using std::swap;

    Bst copy = rhs;
    swap(*this, copy);
    return *this;
}

template <typename T>
Bst<T>::Bst(Bst&& rhs) noexcept :
    root(rhs.root)
{
    rhs.root = nullptr;
}

template <typename T>
Bst<T>& Bst<T>::operator=(Bst&& rhs) noexcept
{
    using std::swap;

    swap(root, rhs.root);
    return *this;
}

template <typename T>
bool Bst<T>::empty() const
{
    return root == nullptr;
}

template <typename T>
void Bst<T>::clear()
{
    clear(root);
}

template <typename T>
const T& Bst<T>::findMax() const
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
const T& Bst<T>::findMin() const
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
bool Bst<T>::contains(const T& item) const
{
    return contains(root, item);
}

template <typename T>
void Bst<T>::insert(const T& item)
{
    insert(root, item);
}

template <typename T>
void Bst<T>::insert(T&& item)
{
    insert(root, std::move(item));
}

template <typename T>
void Bst<T>::remove(const T& item)
{
    if (find(item))
    {
        // TODO
    }
}

template <typename T>
bool Bst<T>::contains(const Node *node, const T& item)
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
void Bst<T>::clear(Node *node)
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
typename Bst<T>::Node *Bst<T>::clone(Node *node) const
{
    // TODO
}

template <typename T>
const typename Bst<T>::Node *Bst<T>::findMax(Node *node) const
{
    while (node != nullptr && node->right != nullptr)
    {
        node = node->right;
    }

    return node;
}

template <typename T>
const typename Bst<T>::Node *Bst<T>::findMin(Node *node) const
{
    while (node != nullptr && node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}

template <typename T>
void Bst<T>::insert(Node *&node, const T& item)
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
void Bst<T>::insert(Node *&node, T&& item)
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
