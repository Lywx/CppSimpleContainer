#include "Bst.h"

/************************************************************************/
/* Inner Class Implementation                                           */
/************************************************************************/
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
    Node *node = root;
    while (node != nullptr)
    {
        // TODO
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
            // Duplication
        }
    }
}

template <typename T>
void Bst<T>::insert(T&& item)
{
    // TODO
}

template <typename T>
void Bst<T>::remove(const T& item)
{
    // TODO
}

template <typename T>
bool Bst<T>::contains(const Node *node, const T& item)
{
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
    new Node()
    return
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
