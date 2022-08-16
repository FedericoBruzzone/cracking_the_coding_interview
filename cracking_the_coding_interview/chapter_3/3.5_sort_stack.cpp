#include "../../ALL_H_FILES.h"

// =============================================================

void sort(std::stack<int>* stack)
{
    if (stack->empty()) return; // stack is empty

    std::stack<int>* r = new std::stack<int>();

    while (!stack->empty())
    {
        int temp = stack->top();
        stack->pop();
        while (!r->empty() && r->top() > temp)
        {
            int temp2 = r->top();
            r->pop();
            stack->push(temp2);
        }
        r->push(temp); 
    }

    while (!r->empty())
    {
        int temp = r->top();
        r->pop();
        stack->push(temp);
    }
}

// =============================================================

// int main()
// {
    
// }