#include "../../ALL_H_FILES.h"

#include "stack.cpp"
#include "queue.cpp"

// =============================================================

// First implementation
// class NodeWithMin
// {
// public:
//     int value;
//     int min;

//     NodeWithMin(int value, int min)
//     {
//         value = value;
//         this->min = min;
//     }
// };

// class StackWithMin : public Stack<NodeWithMin>
// {
// public:
//     void push(int data) 
//     {
//         int newMin = std::min(data, min());
//         Stack::push(NodeWithMin(data, newMin));
//     }

//     int min() 
//     {
//         if (isEmpty()) 
//         {
//             return NULL; // Error
//         }
//         else
//         {
//             return peek().min;
//         }
//     }
// };

// =============================================================

//Second implementation
class StackWithMin2 : public Stack<int>
{
public:
    Stack<int>* minV;

    StackWithMin2() { minV = new Stack<int>(); }

    int min()
    {
        if (this->isEmpty()) { throw EmptyStackException(); }
        else                 { return minV->peek(); }
    }

    void push(int data)
    {
        if (data <= min()) minV->push(data);
        Stack::push(data);
    }

    int pop()
    {
        int value = Stack::pop();

        if (value == min()) minV->pop();

        return value;
    }
};