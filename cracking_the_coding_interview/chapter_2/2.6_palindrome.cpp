#include "../../ALL_H_FILES.h"

#include "linked_list.cpp"

// =============================================================

// First implementation
// Node* reverseAndClone(Node* node)
// {
//     Node* head = NULL;

//     // 1 -> 2 -> 3
//     // 3 -> 2 -> 1
//     while (node != NULL)
//     {
//         Node* n = new Node(node->data);
//         n->next = head;
//         head = n;
//         node = node->next;
//     }

//     return head;
// }

// bool isEqual(Node* n1, Node* n2)
// {
//     while (n1 != NULL && n2 != NULL)
//     {
//         if (!(n1->data == n2->data)) 
//             return false;

//         n1 = n1->next;
//         n2 = n2->next;
//     }

//     return n1 == NULL && n2 == NULL;
// }

// bool isPalindrome(Node* head)
// {
//     Node* reverse = reverseAndClone(head);
//     return isEqual(head, reverse);
// }

// =============================================================

// Second implementation
// bool isPalindrome(Node* head)
// {
//     Node* fast = head;
//     Node* slow = head;

//     std::stack<int> stack;
//     while (fast != NULL && fast->next != NULL)
//     {
//         stack.push(slow->data);
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     if (fast != NULL)
//     {
//         slow = slow->next;
//     }

//     while (slow != NULL)
//     {
//         int top = stack.top();

//         if (top != slow->data)
//             return false;
        
        
//         stack.pop();
//         slow = slow->next;
//     }
//     return true;
// }

// =============================================================

// Third implementation (recursive)
// class Result
// {
// public:
//     Node* node;
//     bool result;

//     Result(Node* node, bool result) 
//         : result(result), node(node) {}

// };

// Result isPalindromeRecurse(Node* head, int length)
// {
//     if (head == NULL || length <= 0)
//     {
//         return Result(head, true);
//     }
//     else if (length == 1)
//     {
//         return Result(head->next, true);
//     }

//     Result res = isPalindromeRecurse(head->next, length - 2);

//     if (!res.result || res.node == NULL)
//     {
//         return res;
//     }

//     res.result = (head->data == res.node->data);
//     res.node = res.node->next;

//     return res;
// }

// bool isPalindrome(Node* head)
// {
//     int length = head->length(head);
//     Result p = isPalindromeRecurse(head, length);
//     return p.result;
// }

// =============================================================

// My implementation
bool isPalindrome(Node* head)
{
    std::stack<int> stack;
    Node* node = head;
    
    while (node != NULL)
    {
        stack.push(node->data);
        node = node->next;
    }

    while (head != NULL)
    {
        if (!(stack.top() == head->data))
        {
            return false;
        }
        stack.pop();
        head = head->next;
    }

    return true;
}

// =============================================================

int main()
{
    Node* n1 = new Node(6);
    n1->appendToTail(7);
    n1->appendToTail(1);
    n1->appendToTail(7);
    n1->appendToTail(6);

    LOG(isPalindrome(n1));
}