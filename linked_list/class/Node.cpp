#include "Node.h"

template <typename T>
Node<T>::Node()
{
    next = NULL;
}

template <typename T> 
Node<T>::Node(T data)
{
    this->data = data;
    this->next = NULL;
}

//template <typename T> 
//Node<T>::~Node() {}

template class Node<int>;