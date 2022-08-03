#include "../../ALL_H_FILES.h"

class EmptyQueueException 
    : public std::exception
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
        
    }

private:
    QueueNode<T>* first = NULL;
    QueueNode<T>* last = NULL;
};

int main()
{
    Queue<int> queue;
    


}  