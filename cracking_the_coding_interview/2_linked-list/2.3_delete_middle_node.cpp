#include "../../ALL_H_FILES.h"

#include "linked_list.cpp"

// =============================================================

bool deleteMiddleNode(Node* node)
{
    if (node == NULL) return false;
    if (node->next == NULL) return false;

    Node* current = node->next;

    node->data = current->data;
    node->next = current->next;
    
    delete current;
    
    return true;
}

// =============================================================

// int main()
// {
//     Node* n = new Node(10);
//     n->appendToTail(20);
//     n->appendToTail(30);
//     n->appendToTail(40);

//     n->print(n);
//     deleteMiddleNode(n->next);
//     n->print(n);
// }