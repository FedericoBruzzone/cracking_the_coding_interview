#include "../../ALL_H_FILES.h"

#include "linked_list.cpp"

bool palindrome(Node* head)
{
    std::stack<int> stack;
    Node* node = head;
    
    while (node != NULL)
    {
        stack.push(node->data);
        node = node->next;
    }

    while (head->next != NULL)
    {
        
        if (!(stack.top() != head->data))
        {
            return false;
        }
        stack.pop();
    }

    return true;
}

int main()
{
    Node* n1 = new Node(6);
    n1->appendToTail(7);
    n1->appendToTail(1);
    n1->appendToTail(7);
    n1->appendToTail(6);

    LOG(palindrome(n1));
}