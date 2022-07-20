#include "../../ALL_H_FILES.h"

#include "linked_list.cpp"

// If the size of the linklist is known, the kth to last element is the (length - k)th element.

// First implementation (recursive)
// Node* kthToLast(Node* head, int k, int& i)
// {
//     if (head == NULL) return NULL;

//     Node* node = kthToLast(head->next, k, i);

//     i = i + 1;
//     if (i == k)
//     {
//         return head;
//     }
//     return node;
// }

// Node* kthToLast(Node* head, int k)
// {
//     int i = 0;
//     return kthToLast(head, k, i);
// }

// Second implementation (iterative)
Node* kthToLast(Node* head, int k)
{
    // if k = 1 reutrn the last element in the list
    if (head == NULL) return NULL;

    Node* p1 = head;
    Node* p2 = head;
    for (int i = 0; i < k; i++)
    {
        if (p1 == NULL) return NULL;
        p1 = p1->next;
    } 

    while (p1 != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p2;
}

int main()
{
    Node* n = new Node(10);
    n->appendToTail(20);
    n->appendToTail(30);
    n->appendToTail(40);

    LOG(n->next->next->next);
    n->print(n);
    LOG(kthToLast(n, 1));
    n->print(n);
}