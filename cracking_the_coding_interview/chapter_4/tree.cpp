#pragma once

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

TNode* createBinaryTree(TNode* root, int nNodes)
{
    if (nNodes <= 0) return NULL;

    root = new TNode(std::rand() % 100); 
    switch(std::rand() % 3) {
        case 0:
            root->left = createBinaryTree(root->left, nNodes / 2);
            break;
        case 1:
            root->right = createBinaryTree(root->left, nNodes / 2); 
            break;
        case 2:
            root->left = createBinaryTree(root->left, nNodes / 2);
            root->right = createBinaryTree(root->left, nNodes / 2);
            break;
        default:
            break;
    
    }
    return root;
}

TNode* createBinaryTree(int nNodes)
{
    TNode* root = new TNode();
    root = createBinaryTree(root, nNodes);
    return root;
}

TNode* createBinarySearchTree(std::vector<int> array, int start, int end)
{
    if (end < start) return NULL;

    int mid = (start + end) / 2;

    TNode* root = new TNode(array[mid]); 

    root->left = createBinarySearchTree(array, start, mid - 1); 
    root->right = createBinarySearchTree(array, mid + 1, end);   

    return root;
}

TNode* createBinarySearchTree(std::vector<int> array)
{
    return createBinarySearchTree(array, 0, array.size() - 1);
}

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