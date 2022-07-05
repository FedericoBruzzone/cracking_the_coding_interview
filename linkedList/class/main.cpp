#include <iostream>
#include "linkedList.h"
#include "linkedList.cpp"


int main()
{
    LinkedList<int> linkedList;

    //std::cout << linkedList.length() << std::endl;

    linkedList.push(1);
    linkedList.print();
    linkedList.push(2);
    linkedList.print();
    linkedList.push(3);
    linkedList.print();
    linkedList.push(4);
    linkedList.print();
    linkedList.push(5);
    linkedList.print();
    
    
    //std::cout << linkedList.length() << std::endl;

    

    
}
