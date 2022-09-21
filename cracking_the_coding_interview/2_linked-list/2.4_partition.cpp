#include "../../ALL_H_FILES.h"

#include "linked_list.cpp"

// =============================================================

// First implementation
Node* partition(Node* node, int pivot)
{
    Node* beforeStart = NULL;
    Node* beforeEnd = NULL;
    Node* afterStart = NULL;
    Node* afterEnd = NULL;

    while (node != NULL)
    {
        Node* next = node->next;
        node->next = NULL;

        if (node->data < pivot)
        {
            if (beforeStart == NULL)
            {
                beforeStart = node;
                beforeEnd = beforeStart;
            }
            else
            {
                beforeEnd->next = node;
                beforeEnd = node;
            }
        }
        else
        {
            if (afterStart == NULL)
            {
                afterStart = node;
                afterEnd = afterStart;
            }
            else
            {
                afterEnd->next = node;
                afterEnd = node;
            }
        }
        node = next;
    }

    if (beforeStart == NULL) return afterStart;

    beforeEnd->next = afterStart;
    
    return beforeStart;
}

// =============================================================

// Second implementation
Node* partition(Node* node, int pivot)
{
    Node* head = node;
    Node* tail = node;

    while (node != NULL)
    {
        Node* next = node->next;

        if (node->data < pivot)  
        {
            node->next = head;
            head = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }

        node = next;
    }
    tail->next = NULL;

    return head;
}

// =============================================================

// int main()
// {
//     Node* n = new Node(1);
//     n->appendToTail(2);
//     n->appendToTail(3);
//     n->appendToTail(4);
//     n->appendToTail(8);
//     n->appendToTail(6);
//     n->appendToTail(7);
//     n->appendToTail(4);
//     n->appendToTail(9);


//     n->print(n);
//     Node* output = partition(n, 4);
//     output->print(output);
// }