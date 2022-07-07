#pragma once
#include "../../linked_list/class/Node.h"
#include "../../linked_list/class/Node.cpp"

template <typename T>
class Stack
{
private:
    Node<T>* stack;

public:
    Stack();
    ~Stack();

    void push(T data);
    T pop();
    T peek();
    bool isEmpty();
    void print();

};
