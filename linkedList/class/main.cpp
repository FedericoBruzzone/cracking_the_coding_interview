#include <iostream>
#include "linkedList.h"
#include "linkedList.cpp"


int main()
{
    LinkedList<int> linkedList;

    std::cout << linkedList.length() << std::endl;

    linkedList.push(1);
    /*
    linkedList.push(2);
    linkedList.push(3);
    linkedList.push(4);
    linkedList.push(5);
    */
    std::cout << linkedList.length() << std::endl;

    linkedList.print();

    
}
