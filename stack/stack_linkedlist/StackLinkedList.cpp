#include "StackLinkedList.h"

template <typename T>
StackLinkedList<T>::StackLinkedList() 
{
    stack = NULL;
}

template <typename T>
StackLinkedList<T>::~StackLinkedList() {}

template <typename T>
void StackLinkedList<T>::push(T data)
{
    Node<T>* temp = new Node<T>(data);
    temp->next = stack;
    stack = temp;
}

template <typename T>
T StackLinkedList<T>::pop()
{
    if (isEmpty()) 
    {
        return 0;
    }
    
    T popped = stack->data;
    stack = stack->next;

    return popped;
}

template <typename T>
T StackLinkedList<T>::peek()
{
    if (isEmpty()) 
    {
        return 0;
    }
    return stack->data;
}

template <typename T>
bool StackLinkedList<T>::isEmpty()
{
    return (stack == NULL);
}

template <typename T>
void StackLinkedList<T>::print()
{
    if (stack == NULL)
    {
        std::cout << "List empty" << std::endl;
        return;
    }

    Node<T>* temp;

    for (temp = stack; temp != NULL; temp = temp->next)
        std::cout << temp->data << "-->";
    if(temp == NULL)
        std::cout<<"NULL"<<std::endl;
}