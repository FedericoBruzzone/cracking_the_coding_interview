#pragma once
#include "../../linked_list/class/Node.h"
#include "../../linked_list/class/Node.cpp"

template <typename T>
class StackLinkedList
{
private:
    Node<T>* stack;

public:
    StackLinkedList();
    ~StackLinkedList();

    void push(T data);
    T pop();
    T peek();
    bool isEmpty();
    void print();

};
