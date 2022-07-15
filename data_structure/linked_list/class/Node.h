#pragma once

#include "../../../ALL_H_FILES.h"

template <typename T>
class Node
{
public:
    T data;
    Node* next;

    Node();
    Node(T value);
    //virtual ~Node();  

};