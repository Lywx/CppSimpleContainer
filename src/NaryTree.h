#pragma once

template <typename T>
class NaryTree
{
public:
    /************************************************************************/
    /* Internal Class Implementation                                        */
    /************************************************************************/
    struct Node
    {
        T item;

        Node *childFirst;
        Node *siblingNext;
    };

    NaryTree();
    ~NaryTree();

    // Copy Semantics
    NaryTree(const NaryTree& t);
    NaryTree& operator=(const NaryTree& rhs);

    // Move Semantics
    NaryTree(NaryTree&& t) noexcept;
    NaryTree& operator=(NaryTree&& rhs) noexcept;

private:
    Node root;
};
