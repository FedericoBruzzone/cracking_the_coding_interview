#include "../../ALL_H_FILES.h"

class Node
{
public:
    Node* next = NULL;
    int data;

    Node() 
    {
        data = 0;
    }


    Node(int d)
    {
        data = d;
    }
    
    void appendToTail(Node* next)
    {
        Node* temp = this;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = next;
    }

    // Overloading
    void appendToTail(int d)
    {
        Node* end = new Node(d);
    
        Node* temp = this;
    
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = end;
    }

    Node* deleteNode(Node* head, int d)
    {
        if (head == NULL) 
        { 
            return NULL; 
        }

        Node* n = head;

        if (n->data == d)
        {
            return head->next;
        } 

        while (n->next != NULL)
        {
            if (n->next->data == d)
            {
                n->next = n->next->next;
                return head;
            }
            n = n->next;
        }
        return head;
        
    }

    void print(Node* head)
    {
        if (head == NULL)
        {
            LOG("List empty");
            return;
        }

        Node* temp;

        for (temp = head; temp != NULL; temp = temp->next)
            std::cout << temp->data << "-->";

        if(temp == NULL)
            LOG("NULL");
    }

    // int length(Node* head) 
    // { 
    //     int count = 0; 
    //     Node* current = head;  
    //     while (current != NULL) 
    //     { 
    //         count++; 
    //         current = current->next; 
    //     } 
    //     return count; 
    // } 
    
    int length(Node* head)
    {
        if (head == NULL) 
        {
            return 0;
        }
        else 
        {
            return 1 + length(head->next);
        }
    }

};

// int main()
// {
//     Node* n = new Node(10);

//     LOG(n);
//     LOG(n->data);

//     LOG("Append");
//     n->appendToTail(20);
//     LOG(n->next);
//     LOG(n->next->data);
//     LOG("");    

//     LOG("Delete");
//     n->deleteNode(n, 20);
//     LOG(n);
//     LOG(n->data);
//     //LOG(n->next);
//     //LOG(n->next->data);
//     LOG("");  

//     LOG("Append");
//     n->appendToTail(20);
//     LOG(n);
//     LOG(n->data);
//     LOG(n->next);
//     LOG(n->next->data);
//     LOG("");
// }