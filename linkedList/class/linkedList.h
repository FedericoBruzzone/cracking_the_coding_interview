#pragma once

#include "node.h"
#include "node.cpp"
#include "iostream"

template <typename T>
class LinkedList
{
private:
    Node<T>* head;

public:
    LinkedList();
    //virtual ~LinkedList();

    void push(T value);

    int length();

    void deleteElement(int index);

    void deleteFirstElement();

    void deleteLastElement();

    void print();
};