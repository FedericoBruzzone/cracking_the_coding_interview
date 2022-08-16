#include "../../ALL_H_FILES.h"

#include "tree.cpp"


// =============================================================

Node* createMinimalBST(std::vector<int> array, int start, int end)
{
    if (end < start) return NULL;

    int mid = (start + end) / 2;

    Node* root = new Node(array[mid]); 

    root->left = createMinimalBST(array, start, mid - 1); 
    root->right = createMinimalBST(array, mid + 1, end);   

    return root;
}

Node* createMinimalBST(std::vector<int> array)
{
    return createMinimalBST(array, 0, array.size() - 1);
}

// =============================================================

int main()
{
    std::vector<int> array = std::vector<int>();
    for (int i = 0; i < 10; ++i) { array.push_back(i); }

    Node* bst = createMinimalBST(array);

    bst->preOrder();

}
