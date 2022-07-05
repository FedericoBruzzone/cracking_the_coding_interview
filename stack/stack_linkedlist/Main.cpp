#include <iostream> 
#include "StackLinkedList.h"  
#include "StackLinkedList.cpp"

int main()
{
    StackLinkedList<int> stack;

    std::cout << "Empty: " << stack.isEmpty() << std::endl;
    std::cout << "Peek: " << stack.peek() << std::endl;
    stack.print();
    stack.push(10);
    stack.print();
    stack.push(20);
    stack.print();
    std::cout << "Empty: " << stack.isEmpty() << std::endl;
    std::cout << "Peek: " << stack.peek() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;
    stack.print();
    std::cout << "Peek: " << stack.peek() << std::endl;
    
}
