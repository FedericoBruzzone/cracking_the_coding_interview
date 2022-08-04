#include "../../ALL_H_FILES.h"

class EmptyStackException 
    : public std::exception
{
    virtual const char* what() const throw()
    {
        return "EmptyStackException";
    }
};

template <class T>
class StackNode
{
public:
    StackNode(T data) 
    { 
        this->data = data; 
    }

    T data;
    StackNode<T>* next = NULL;
};

template <class T>
class Stack
{
public:
    T pop()
    {
        if (top == NULL) throw EmptyStackException();

        T item = top->data;
        top = top->next;
        return item;
    }

    void push(T item)
    {
        StackNode<T>* t = new StackNode<T>(item);
        t->next = top;
        top = t;
    }

    T peek()
    {
        if (top == NULL) throw EmptyStackException();
        return top->data;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
    
    void print()
    {
        StackNode<T>* print = this->top;

        if (this == NULL) throw EmptyStackException();

        while (print != NULL)
        {
            std::cout << print->data << "<--";
            print = print->next;
        }

        if(print == NULL)
            LOG("NULL");
        
    }

private:
    StackNode<T>* top = NULL;

};

int main()
{
    Stack<int>* stack = new Stack<int>();
    
    LOG(stack->isEmpty())
    stack->push(10);
    LOG(stack->peek())
    stack->push(20);
    stack->push(30);
    stack->push(40);
    LOG(stack->peek())
    LOG(stack->pop())
    LOG(stack->peek())

    //stack.print();


}  