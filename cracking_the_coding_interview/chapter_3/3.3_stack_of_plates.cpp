#include "../../ALL_H_FILES.h"

// #include "stack.cpp"

class EmptyStackException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "EmptyStackException";
    }
};

class StackNode
{
public:
    StackNode(int data) 
    { 
        this->data = data; 
    }

    int data;
    StackNode* above = NULL;
    StackNode* below = NULL;
};


class Stack
{
public:
    int size = 0;
    StackNode* top = NULL;
    StackNode* bottom = NULL;

    Stack(int capacity) { this->capacity = capacity; }
    bool isEmpty() { size == 0; }
    bool isFull()  { size == capacity; }

    void join(StackNode* above, StackNode* below) 
    {
        if (above != NULL) { above->below = below; } 
        if (below != NULL) { below->above = above; }
    }

    bool push(int data) 
    {
        if (size >= capacity) return false;
        size++;

        StackNode* newNode = new StackNode(data);

        if (size == 1) bottom = newNode;
        
        join(newNode, top);
        top = newNode;
        return true;
    }

    int pop() 
    {
        StackNode* node = top;
        top = top->below;
        size--;
        return node->data;
    }

    int removeBottom()
    {
        StackNode* node = bottom;
        bottom = bottom->above;
        if (bottom != NULL) bottom->below = NULL;
        size--;
        return node->data;
    }

private:
    int capacity = 0;
};

class SetOfStack
{
public:
    std::vector<Stack*> stacks = std::vector<Stack*>();
    int capacity;
    
    SetOfStack(int capacity) { this->capacity = capacity; }
    
    bool isEmpty() 
    {
        Stack* last = getLastStack();
        return last->isEmpty();
    }

    Stack* getLastStack()
    {
        if (stacks.size() == 0) return NULL;
        stacks.at(stacks.size() - 1);
    }

    void push(int data)
    {
        Stack* last = getLastStack();
        if (!(last->isFull()) && last != NULL)
        {
            last->push(data);
        }
        else
        {
            Stack* newStack = new Stack(capacity);
            newStack->push(data);
            stacks.push_back(newStack);
        }
    }

    int pop()
    {
        Stack* last = getLastStack();
        if (last == NULL) throw EmptyStackException();

        int value = last->pop();

        if (last->size == 0) stacks.erase(stacks.begin() + stacks.size() - 1);
        
        return value;
    }

    int leftShift(int index, bool removeTop)
    {
        Stack* stack = stacks.at(index);
        int removedItem;

        if (removeTop) removedItem = stack->pop();
        else removedItem = stack->removeBottom();

        if (stack->isEmpty())
        {
            stacks.erase(stacks.begin() + index);
        }
        else if (stacks.size() > index + 1)
        {
            int v = leftShift(index + 1, false);
            stack->push(v);
        }
        return removedItem;
    }

    int popAt(int index)
    {
        return leftShift(index, true);
    }
};

// =============================================================

int main()
{

}