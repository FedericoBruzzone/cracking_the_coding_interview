#include "../../ALL_H_FILES.h"

#include "tree.cpp"

#include "4.2_minimal_tree.cpp"

// =============================================================

// First implementation
int getHeight(TNode* root)
{
    if (root == NULL) return -1;
    return std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

bool isBalanced(TNode* root)
{
    if (root == NULL) return true;

    if (std::abs(getHeight(root->left) - getHeight(root->right)) > 1)
    {
        return false;
    }
    else
    {
        return isBalanced(root->left) && isBalanced(root->right);
    }

    return true;
}

// =============================================================

// Second implementation
int checkHeight(TNode* root)
{
    if (root == NULL) return -1;
    
    int leftHeight = checkHeight(root->left);
    if(leftHeight == INT_MIN) return INT_MIN;

    int rightHeight = checkHeight(root->right);
    if(rightHeight == INT_MIN) return INT_MIN;

    if (std::abs(leftHeight - rightHeight) > 1)
    {
        return INT_MIN;
    }
    else
    {
        return std::max(leftHeight, rightHeight) + 1;
    }
}

bool isBalanced(TNode* root)
{
    return checkHeight(root) != INT_MIN;
}
// =============================================================

// int main()
// {
//     TNode* btree = createMinimalBST({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
//     TNode* btree_not_balanced = createBinaryTree(4);

//     LOG(getHeight(btree))
//     LOG(isBalanced(btree))
//     LOG(isBalanced(btree_not_balanced))
// }