#pragma once

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