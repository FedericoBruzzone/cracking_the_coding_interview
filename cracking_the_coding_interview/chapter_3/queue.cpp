#include "../../ALL_H_FILES.h"

// =============================================================

class EmptyQueueException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "EmptyQueueException";
    }
};

template <class T>
class QueueNode
{
public:
    QueueNode(T data) 
    { 
        this->data = data; 
    }

    T data;
    QueueNode<T>* next = NULL;
};

template <class T>
class Queue
{
public:
    void add(T item)
    {
        QueueNode<T>* t = new QueueNode<T>(item);

        if (last != NULL) 
            last->next = t;
        
        last = t;

        if (first == NULL)
            first = last;
    }

    T remove()
    {
        if (first == NULL) throw EmptyQueueException();
        T data = first->data;
        first = first->next;

        if (first == NULL)
        {
            last = NULL;
        }

        return data;
    }

    T peek()
    {
        if (first == NULL) throw EmptyQueueException();
        return first->data;
    }

    bool isEmpty()
    {
        return first == NULL;
    }

    void print()
    {
        QueueNode<T>* print = this->first;

        if (this == NULL) throw EmptyQueueException();

        while (print != NULL)
        {
            std::cout << print->data << "-->";
            print = print->next;
        }

        if(print == NULL)
            LOG("NULL");
        
    }

private:
    QueueNode<T>* first = NULL;
    QueueNode<T>* last = NULL;
};

// =============================================================

// int main()
// {
//     Queue<int>* queue = new Queue<int>();
    
//     queue->add(10);
//     queue->print();

//     queue->add(20);
//     queue->print();

//     queue->add(30);
//     queue->print();
    
// }  