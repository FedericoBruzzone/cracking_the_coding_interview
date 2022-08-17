#include "../../ALL_H_FILES.h"

#include "tree.cpp"

// =============================================================

// First implementation
bool isBinarySearchTree(TNode* root, int* lastVisited)
{
    if (root == NULL) return true; // base case

    if (!isBinarySearchTree(root->left, lastVisited)) return false;

    if (lastVisited != NULL && root->data <= *lastVisited) return false;
    lastVisited = &(root->data);

    if (!isBinarySearchTree(root->right, lastVisited)) return false;
    
    return true;
}

bool isBinarySearchTree(TNode* root)
{
    return isBinarySearchTree(root, NULL);
}

// =============================================================

// Second implementation
bool isBinarySearchTree(TNode* root, int* min, int* max)
{
    if (root == NULL) return true;

    if ((min != NULL && root->data <= *min) || (max != NULL && root->data > *max)) 
        return false;

    if ((!isBinarySearchTree(root->left, min, &(root->data))) || (!isBinarySearchTree(root->right, &(root->data), max)))
        return false;

    return true; 

}

bool isBinarySearchTree(TNode* root)
{
    return isBinarySearchTree(root, NULL, NULL);
}

// =============================================================

// int main()
// {
//     TNode* btree = createBinaryTree(10);
//     TNode* bst = createBinarySearchTree({1,2,3,4,5,6,7,8,9,10,11});

//     LOG(isBinarySearchTree(btree))
//     LOG(isBinarySearchTree(bst))
// }