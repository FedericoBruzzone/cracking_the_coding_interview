#include "../../ALL_H_FILES.h"

#include "linked_list.cpp"

// =============================================================

// First implementation (recursive)
// Node* addList(Node* n1, Node* n2, int carry)
// {
//     if (n1 == NULL &&
//         n2 == NULL &&
//         carry == 0) 
//         return NULL;
    
//     Node* result = new Node();
//     int value = carry;
    
//     //if (n1 != NULL)
//         value += n1->data;

//     //if (n2 != NULL)
//         value += n2->data;

//     result->data = value % 10;

//     /* Recurse */
//     if (n1 != NULL || n2 != NULL)
//     {
//         Node* more = addList(n1 == NULL ? NULL : n1->next,
//                              n2 == NULL ? NULL : n2->next,
//                              value >= 10 ? 1 : 0);
//         result->next = more;
//         LOG(result->data);
//     }
//     return result;
// }

// Node* addList(Node* n1, Node* n2)
// {
//     return addList(n1, n2, 0);
// }

// =============================================================

// Second implementation
Node* addList(Node* firstNumber, Node* secondNumber)
{
    int sum = 0;
    int carry = 0;
    Node* result = firstNumber;
    
    while (firstNumber != NULL && secondNumber != NULL)
    {
        sum = ((firstNumber->data + secondNumber->data) + carry ) % 10;
        carry = static_cast<int>((firstNumber->data + secondNumber->data) / 10);
        
        firstNumber->data = sum;
        
        firstNumber = firstNumber->next;
        secondNumber = secondNumber->next;
    }

    return result;
}

// =============================================================

// FOLLOW UP
// class PartialSum
// {
// public:
//     Node* sum = NULL;
//     int carry = 0;

//     PartialSum() {}
// };

// Node* insertBefore(Node* list, int data)
// {
//     Node* node = new Node(data);

//     if (list != NULL)
//     {
//         node->next = list;
//     }

//     return node;
// }

// Node* padList(Node* node, int padding)
// {
//     Node* head = node;

//     for (int i = 0; i < padding; i++)
//     {
//         head = insertBefore(head, 0);
//     }
//     return head;
// }

// PartialSum addListHelper(Node* n1, Node* n2)
// {
//     if (n1 == NULL && n2 == NULL) 
//     {
//         PartialSum sum;
//         return sum;
//     } 

//     PartialSum sum = addListHelper(n1->next, n2->next);

//     int val = sum.carry + n1->data + n2->data;

//     Node* full_result = insertBefore(sum.sum, val % 10);

//     sum.sum = full_result;
//     sum.carry = val / 10;
//     return sum;
// }

// Node* addList(Node* n1, Node* n2)
// {
//     int len1 = n1->length(n1);
//     int len2 = n2->length(n2);

//     if (len1 < len2)
//     {
//         n1 = padList(n1, len2 - len1);
//     }
//     else 
//     {
//         n2 = padList(n2, len1 - len2);
//     }

//     PartialSum sum = addListHelper(n1, n2);

//     if (sum.carry == 0)
//     {
//         return sum.sum;
//     }
//     else
//     {
//         Node* result = insertBefore(sum.sum, sum.carry);
//         return result;
//     }
// }

// =============================================================

int main()
{
    Node* n1 = new Node(7);
    n1->appendToTail(1);
    n1->appendToTail(6);
    
    Node* n2 = new Node(5);
    n2->appendToTail(9);
    n2->appendToTail(2);

    n1->print(n1);
    n2->print(n2);

    Node* output = addList(n1, n2);
    output->print(output);

    // FOLLOW UP
    // Node* n1 = new Node(6);
    // n1->appendToTail(1);
    // n1->appendToTail(7);
    
    // Node* n2 = new Node(2);
    // n2->appendToTail(9);
    // n2->appendToTail(5);

    // n1->print(n1);
    // n2->print(n2);

    // Node* output = addList(n1, n2);
    // output->print(output);

}