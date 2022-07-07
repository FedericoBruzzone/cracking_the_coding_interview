#include "StackArray.h"

template <typename T>
Stack<T>::Stack() 
    : stack(MAX_LENGTH)
{
    //stack.resize(MAX_LENGTH);
    //top = -1;
}

template <typename T>
Stack<T>::Stack(size_t length)
    : stack(length)
{
    //stack.resize(length);
    //top = -1;
}

template <typename T>
Stack<T>::~Stack() {}

template <typename T>
bool Stack<T>::push(T value)
{
    
    if (top >= static_cast<int>(stack.size()) - 1)
    {
        std::cout << "Stack overflow" << std::endl;
        return false;
    }

    std::cout << value << " pushed into stack" << std::endl;
    stack[++top] = value;
    return true;
}

template <typename T>
T Stack<T>::pop()
{
    if (top < 0)
    {
        std::cout << "Stack underflow" << std::endl;
        return 0;
    }

    //delete stack[top];
    T aus = stack[top--];
    return aus;
}

template <typename T>
T Stack<T>::peek()
{
    if (top < 0)
    {
        std::cout << "Stack is empty" << std::endl;
        return 0;
    }

    T aus = stack[top];
    return aus;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return (top < 0);
}

template <typename T>
int Stack<T>::length()
{
    return stack.size();
    //return sizeof stack / sizeof stack[0];
}

template class Stack<int>;
