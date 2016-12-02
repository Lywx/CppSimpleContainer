#pragma once

#include "BinarySearchTree.h"

// Implementation: TODO
template <typename T>
class AvlTree : public BinarySearchTree<T>
{
    /************************************************************************/
    /* Inner Class Declaration                                              */
    /************************************************************************/
public:
    struct Node : BinarySearchTree<T>::Node
    {
        int height;

        Node(const T& item, Node *left, Node *right, int height = 0);
        Node(T&& item, Node *left, Node *right, int height = 0);
    };

    class const_iterator : public BinarySearchTree<T>::const_iterator
    {
    protected:
        const_iterator();
        const_iterator(Node *current);

        friend class AvlTree;
    };

    class const_preorder_iterator :
        public BinarySearchTree<T>::const_preorder_iterator
    {
    protected:
        const_preorder_iterator();
        const_preorder_iterator(Node *current);

        friend class AvlTree;
    };

    class const_inorder_iterator :
        public BinarySearchTree<T>::const_inorder_iterator
    {
    protected:
        const_inorder_iterator();
        const_inorder_iterator(Node *current);

        friend class AvlTree;
    };

    class const_postorder_iterator :
        public BinarySearchTree<T>::const_postorder_iterator
    {
    protected:
        const_postorder_iterator();
        const_postorder_iterator(Node *current);

        friend class AvlTree;
    };

    /************************************************************************/
    /* Class Declaration                                                    */
    /************************************************************************/
    AvlTree();

    const_preorder_iterator  cbegin_preorder() const;
    const_preorder_iterator  cend_preorder() const;
    const_inorder_iterator   cbegin_inorder() const;
    const_inorder_iterator   cend_inorder() const;
    const_postorder_iterator cbegin_postorder() const;
    const_postorder_iterator cend_postorder() const;

    virtual void insert(const T& item) override;
    virtual void insert(T&& item) override;
    virtual void remove(const T& item) override;

protected:
    int height(Node *node) const;

    void LL(Node *&t);
    void LR(Node *&t);
    void RL(Node *&t);
    void RR(Node *&t);
};

