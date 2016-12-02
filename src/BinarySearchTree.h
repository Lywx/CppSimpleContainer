#pragma once

#include <stack>

// Reference: Weiss M.A. Data Structures and Algorithm Analysis in C++, 4th, 2014
// Implementation: Finished.
template <typename T>
class BinarySearchTree
{
    /************************************************************************/
    /* Inner Class Declaration                                              */
    /************************************************************************/
public:
    struct Node;

    class const_iterator
    {
    protected:
        const_iterator();

        // Allow implicit conversion from Node*
        const_iterator(Node *current);
    public:
        virtual ~const_iterator();

        const T& operator*() const;

        bool operator==(const_iterator& rhs) const;
        bool operator==(const_iterator&& rhs) const;
        bool operator!=(const_iterator& rhs) const;
        bool operator!=(const_iterator&& rhs) const;

    protected:
        T& retrieve() const;

        std::stack<std::pair<Node *, int>> m_traversalTaskStack;
        Node                              *m_iterationNodeCurrent;

    protected:
        friend class BinarySearchTree;
    };

    class const_preorder_iterator : public const_iterator
    {
    protected:
        const_preorder_iterator();
        const_preorder_iterator(Node *current);

    public:
        const_preorder_iterator& operator++();
        const_preorder_iterator operator++(int);

    protected:
        friend class BinarySearchTree;
    };

    class const_inorder_iterator : public const_iterator
    {
    protected:
        const_inorder_iterator();
        const_inorder_iterator(Node *current);

    public:
        const_inorder_iterator& operator++();
        const_inorder_iterator operator++(int);

    protected:
        friend class BinarySearchTree;
    };

    class const_postorder_iterator : public const_iterator
    {
    protected:
        const_postorder_iterator();
        const_postorder_iterator(Node *current);

    public:
        const_postorder_iterator& operator++();
        const_postorder_iterator operator++(int);

    protected:
        friend class BinarySearchTree;
    };

    struct Node
    {
        T     item;
        Node *left;
        Node *right;

        Node(const T& item, Node *left, Node *right);
        Node(T&& item, Node *left, Node *right);

        // Make this class a "polymorphic" type
        virtual ~Node();
    };

    /************************************************************************/
    /* Class Declaration                                                    */
    /************************************************************************/
    BinarySearchTree();
    virtual ~BinarySearchTree();

    // Copy Semantics
    BinarySearchTree(const BinarySearchTree& rhs);
    BinarySearchTree& operator=(const BinarySearchTree& rhs);

    // Move Semantics
    BinarySearchTree(BinarySearchTree&& rhs) noexcept;
    BinarySearchTree& operator=(BinarySearchTree&& rhs) noexcept;

    const_preorder_iterator  cbegin_preorder() const;
    const_preorder_iterator  cend_preorder() const;
    const_inorder_iterator   cbegin_inorder() const;
    const_inorder_iterator   cend_inorder() const;
    const_postorder_iterator cbegin_postorder() const;
    const_postorder_iterator cend_postorder() const;

    void        clear();
    bool        empty() const;

    bool        contains(const T& item) const;
    const Node *find(const T& item) const;
    const Node *find_max() const;
    const Node *find_min() const;
    const Node *root() const;

    virtual void insert(const T& item);
    virtual void insert(T&& item);
    virtual void remove(const T& item);

    const T&    max() const;
    const T&    min() const;

protected:
    bool        contains(const Node *node, const T& item) const;
    void        clear(Node *&node);
    Node       *clone(Node *node) const;

    const Node *find(const Node *node, const T& item) const;
    const Node *find_max(const Node *node) const;
    const Node *find_min(const Node *node) const;

    virtual void insert(Node *&node, const T& item);
    virtual void insert(Node *&node, T&& item);
    virtual void remove(Node *&node, const T& item);

    Node *m_root;
};
