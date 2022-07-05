#include "linkedList.h"

template <typename T>
LinkedList<T>::LinkedList()
{
    head = NULL;
} 

//template <typename T>
//LinkedList<T>::~LinkedList() {}

template <typename T>
void LinkedList<T>::push(T data)
{
    Node<T>* newNode = new Node<T>(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node<T>* temp = head;
    
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

}

template <typename T>
int LinkedList<T>::length()
{
    int length = 0;
    Node<T>* temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }

    return length;
}

template <typename T>
void LinkedList<T>::deleteElement(int index)
{
    if (head == NULL) {
        std::cout << "List empty" << std::endl;
        return;
    }
    
    int length = this->length();

    Node<T>* temp = head;

    if (length < index)
    {
        std::cout << "Index out of range" << std::endl;
        return;
    }

    temp = head;
    if (length == 1)
    {
        head = head->next;
        delete temp;
        return;
    }

    Node<T>* temp2;
    while (index-- > 1)
    {
        temp2 = temp;
        temp = temp->next;
    }

    temp2->next = temp->next;

    delete temp;
}

template <typename T>
void LinkedList<T>::deleteFirstElement()
{
    deleteElement(1);
}

template <typename T>
void LinkedList<T>::deleteLastElement()
{
    if (head == NULL) {
        std::cout << "List empty" << std::endl;
        return;
    }

    if (head->next == NULL) 
    {
        delete (head);
        return;
    }

    Node<T>* temp = head;

    while (temp->next->next == NULL)
        temp = temp->next;
    
    delete (temp->next);
    temp->next = NULL;
}

template <typename T>
void LinkedList<T>::print()
{
    if (head == NULL)
    {
        std::cout << "List empty" << std::endl;
        return;
    }

    Node<T>* temp;

    for (temp = head; temp != NULL; temp = temp->next)
        std::cout << temp->data << "-->";
    if(temp == NULL)
        std::cout<<"NULL"<<std::endl;
}

template class LinkedList<int>;