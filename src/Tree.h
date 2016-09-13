#pragma once

template <typename T>
class Tree
{
public:
    /************************************************************************/
    /* Internal Class Implementation                                        */
    /************************************************************************/
    struct TreeNode
    {
        T item;

        TreeNode *childFirst;
        TreeNode *siblingNext;
    };

    Tree();
    ~Tree();

    // Copy Semantics
    Tree(const Tree& t);
    Tree& operator=(const Tree& rhs);

    // Move Semantics
    Tree(Tree&& t) noexcept;
    Tree& operator=(Tree&& rhs) noexcept;

private:
    TreeNode root;
};
