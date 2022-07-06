#include <iostream>

/* They're not a good methods

typedef struct 
{
    int value;
    Node* next;
} Node; 


struct Node
{
    int value;
    Node* next;
}; 
*/

template <typename T>
struct Node
{
    T value;
    Node* next;
};
//typedef Node<int> int_Node;

// Create linked list by adding nodes at head
template <typename T>
void push(Node<T>** head, int value)
{
    Node<T>* aus = new Node<T>;
    aus->value = value;
    aus->next = (*head);
    (*head) = aus;
}

// Delete first node in the linked list
template <typename T>
Node<T>* deleteFirstNode(Node<T>* head)
{
    if (head == NULL) return NULL;

    Node<T>* aus = head;
    head = head->next;
    delete aus;

    return head;

}

// Delete last node from linked list
template <typename T>
Node<T>* deleteLastNode(Node<T>* head)
{
    if (head == NULL) return NULL;

    if (head->next == NULL) 
    {
        delete (head);
        return NULL;
    }

    Node<T>* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    
    delete (second_last->next);

    second_last->next = NULL;

    return head;
}

int main()
{
    Node<int>* head = NULL;
    
    // Create linked list
    push(&head, 2);
    push(&head, 4);
    push(&head, 6);
    push(&head, 8);
    push(&head, 10);
    std::cout<< std::endl;

    Node<int>* aus;
 
    std::cout<<"Linked list created "<<std::endl; 
    for (aus = head; aus != NULL; aus = aus->next)
        std::cout << aus->value << "-->";
    if(aus == NULL)
        std::cout<<"NULL"<<std::endl;
    std::cout<< std::endl;

    // Delete first node
    head = deleteFirstNode(head);
    std::cout<<"Linked list after deleting head node"<<std::endl; 
    for (aus = head; aus != NULL; aus = aus->next)
        std::cout << aus->value << "-->";
    if(aus == NULL)
        std::cout<<"NULL"<<std::endl;
    std::cout<< std::endl;

    // Delete last node
    head = deleteLastNode(head);
    std::cout<<"Linked list after deleting last node"<<std::endl; 
    for (aus = head; aus != NULL; aus = aus->next)
        std::cout << aus->value << "-->";
    if(aus == NULL)
        std::cout<<"NULL";
    std::cout<< std::endl;
    
    return 0;
}