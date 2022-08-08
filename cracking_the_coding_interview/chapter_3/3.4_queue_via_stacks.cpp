#include "../../ALL_H_FILES.h"

#include "stack.cpp"

// =============================================================

template <class T>
class MyQueue
{
public:
    Stack<T>* stackNewest; 
    Stack<T>* stackOldest;

    MyQueue()
    {
        stackNewest = new Stack<T>();
        stackOldest = new Stack<T>();
    }

    void shiftStacks()
    {
        if (stackOldest->isEmpty())
        {
            while (!stackNewest->isEmpty())
            {
                stackOldest->push(stackOldest->pop());
            }
        }
    }

    void add(T data)
    {
        stackOldest->push(data);
    }

    T remove()
    {
        shiftStacks();
        return stackOldest->pop();
    }
    
    T peek()
    {
        shiftStacks();
        return stackOldest->peek();
    }
};

// =============================================================

int main()
{

}
