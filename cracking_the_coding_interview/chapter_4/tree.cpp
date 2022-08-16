#include "../../ALL_H_FILES.h"

// =============================================================

// struct Node
// {
//     std::string data;
//     struct Node* left;
//     struct Node* right;
// };
// typedef struct Node Node;

// =============================================================

class TNode
{
public:
    //std::string data;
    int data;
    TNode* left;
    TNode* right;

    TNode() {}

    TNode (int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    void inOrder()
    {
        if (this == NULL)
            return;
        this->left->inOrder();
        std::cout << this->data << " ";
        this->right->inOrder();
    }

    void preOrder()
    {
        if (this == NULL)
            return;
        std::cout << this->data << " ";
        this->left->preOrder();
        this->right->preOrder();
    }

    void postOrder()
    {
        if (this == NULL)
            return;
        this->left->postOrder();
        this->right->postOrder();
        std::cout << this->data << " ";
    }
};

// =============================================================

// class Tree
// {
// public:
//     Node* root;
// };

// =============================================================

// int main()
// {
//     Node* node;
// }