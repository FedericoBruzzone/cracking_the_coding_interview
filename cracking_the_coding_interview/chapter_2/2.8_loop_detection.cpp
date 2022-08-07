#include "../../ALL_H_FILES.h"

#include "linked_list.cpp"

// =============================================================

// A -> B -> C* -> D -> E -> F -> C* 
// ^
//      S    F
//           S          F
//                 S              F
//                      SF

// First implementation
// Node* findBeginning(Node* head)
// {
//     if (head == NULL) return NULL;

//     Node* slow = head;
//     Node* fast = head;

//     while (fast != NULL && fast->next != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//         if (slow == fast) 
//         {
//             break;
//         }
//     }

//     if (fast == NULL || fast->next == NULL)
//     {
//         return NULL;
//     }

//     slow = head;

//     while (slow != fast)
//     {
//         slow = slow->next;
//         fast = fast->next;
//     }

//     return slow;
// }

// =============================================================

// My implementatation
Node* findBeginning(Node* head)
{
    if (head == NULL) return NULL;
    
    std::map<Node*, int> map;
    Node* node = head;

    while (node != NULL)
    {
        map[node]++;
        if (map[node] > 1) return node;
        node = node->next;
    }
    return NULL;

}

// =============================================================

int main()
{
    // Loop
    Node* common = new Node(10);
    common->appendToTail(11);
    common->appendToTail(12);
    common->appendToTail(common);

    // List
    Node* n1 = new Node(7);
    n1->appendToTail(1);
    n1->appendToTail(6);
    n1->appendToTail(common);

    Node* output = new Node();
    output = findBeginning(n1);
    LOG(output->data);

}
