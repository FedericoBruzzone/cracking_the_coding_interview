#include "../../ALL_H_FILES.h"

//#include "stack.cpp"

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

int main()
{
    std::stack<int>* stack = new std::stack<int>(); 

    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(1);
    stack->push(5);

    // input:  2 -> 3 -> 4 -> 1 -> 5 
    //         i.peek() = 2
    //         o.push(i.pop())
    // output: 2 
    
    // input:  3 -> 4 -> 1 -> 5 
    //         i.peek() = 3
    //         o.push(i.pop())
    // output: 2 
}