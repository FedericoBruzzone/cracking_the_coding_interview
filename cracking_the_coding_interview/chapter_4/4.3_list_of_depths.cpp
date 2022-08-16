#include "../../ALL_H_FILES.h"

#include "tree.cpp"

#include "4.2_minimal_tree.cpp"
#include "../chapter_2/linked_list.cpp"

// =============================================================

std::vector<std::list<TNode*>> createLevelLinkedList(TNode* root)
{
    if (root == NULL) return;

    std::vector<std::list<TNode*>> lists = std::vector<std::list<TNode*>>();
}

// =============================================================

int main()
{
    TNode* btree = createMinimalBST({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});


}