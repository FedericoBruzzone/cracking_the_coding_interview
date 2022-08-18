#include "../../ALL_H_FILES.h"

#include "tree.cpp"

// =============================================================

TNode* leftmostChild(TNode* node)
{
    if (node == NULL) return NULL;

    while (node->left != NULL) { node = node->left; }

    return node;
}

TNode* inOrderSuccessor(TNode* node)
{
    if (node == NULL) return NULL;

    if (node->right != NULL) 
    { 
        return leftmostChild(node->right); 
    }
    else 
    {  
        TNode* current = node;
        TNode* parent = node->parent;

        while (parent != NULL && parent->left != current)
        {
            current = parent;
            parent = parent->parent;
        }
        
        return current;
    }
}

// =============================================================

// int main()
// {
//     //TNode* btree = createBinaryTree(10);
//     TNode* bst = createBinarySearchTreeWithParent({1,2,3,4,5,6,7,8,9,10,11});

//     LOG(inOrderSuccessor(bst)->data)
// }

