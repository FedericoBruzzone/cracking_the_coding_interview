#include "../../ALL_H_FILES.h"

#include "linked_list.cpp"

// =============================================================

// First implementation 
// bool removeDups(Node* head) //O(N) time - O(N) space
// {
//     if (head == NULL)      return true; 
//     if (head->next == NULL) return true;

//     std::vector<int> memory (1000);
//     std::fill(memory.begin(), memory.end(), 0);
//     Node* node = head;

//     while (node->next != NULL)
//     {
//         if (memory[node->data] >= 1)
//         {
//             node->deleteNode(head, node->data);
//         }
//         else
//         {
//             memory[node->data]++;
//         }
//         node = node->next;
//     }
//     return true;
// }

// =============================================================

// Second implementation
bool removeDups(Node* head) //O(N^2) time - O(1) space
{
    if (head == NULL)       return true; 
    if (head->next == NULL) return true;
    
    Node* node = head;

    while (node->next != NULL)
    {
        Node* runner = node;
        while (runner->next != NULL)
        {
            if (node->data == runner->next->data)
            {
                runner->next = runner->next->next;
            }
            else
            {
                runner = runner->next;
            }
        }
        node = node->next;
    }
    return true; 
}

// =============================================================

int main()
{
    Node* n = new Node(10);
    
    n->appendToTail(20);
    
    n->appendToTail(30); n->appendToTail(30); n->appendToTail(30); 

    n->appendToTail(40); 
    
    n->print(n);

    removeDups(n);
    
    n->print(n);
}