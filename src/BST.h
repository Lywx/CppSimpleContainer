#pragma once

#include <stdexcept>
#include <algorithm>

template <typename T>
class Bst
{
    /************************************************************************/
    /* Inner Class Declaration                                              */
    /************************************************************************/
public:
    struct Node
    {
        T item;
        Node *left;
        Node *right;

        Node(const T& item, Node *left, Node *right);
        Node(T&& item, Node *left, Node *right);
    };

    /************************************************************************/
    /* Class Declaration                                                    */
    /************************************************************************/
    Bst();
    ~Bst();

    // Copy Semantics
    Bst(const Bst& rhs);
    Bst& operator=(const Bst& rhs);

    // Move Semantics
    Bst(Bst&& rhs) noexcept;
    Bst& operator=(Bst&& rhs) noexcept;

    bool empty() const;
    void clear();

    const T& findMax() const;
    const T& findMin() const;

    bool contains(const T& item) const;
    void insert(const T& item);
    void insert(T&& item);
    void remove(const T& item);

private:
    Node *root;

    bool contains(const Node *node, const T& item);
    void clear(Node *node);
    Node *clone(Node *node) const;

    const Node *findMax(Node *node) const;
    const Node *findMin(Node *node) const;
};
