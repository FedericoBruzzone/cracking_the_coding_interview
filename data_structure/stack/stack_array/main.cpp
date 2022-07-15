#include <iostream> 
#include "StackArray.h"  
#include "StackArray.cpp"

int main()
{
    StackArray<int> stack = StackArray<int>();
    StackArray<int> stack2 = StackArray<int>(100);

    std::cout << stack.length() << std::endl;
    std::cout << stack2.length() << std::endl;

    std::cout << "Empty: " << stack.isEmpty() << std::endl;
    std::cout << "Push: " << stack.push(1) << std::endl;
    std::cout << "Push: " << stack.push(2) << std::endl;
    std::cout << "Empty: " << stack.isEmpty() << std::endl;
    std::cout << "Peek: " << stack.peek() << std::endl;
    std::cout << "Pop: " <<stack.pop() << std::endl;
    std::cout << "Peek: " << stack.peek() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "Empty: " << stack.isEmpty() << std::endl;
    
}
