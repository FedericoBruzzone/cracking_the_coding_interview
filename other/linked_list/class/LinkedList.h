#pragma once

#include "Node.h"
#include "Node.cpp"
#include "../../../ALL_H_FILES.h"

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