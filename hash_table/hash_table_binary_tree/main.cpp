#include <iostream>
#include "HashTableBinaryTree.h"
#include "HashTableBinaryTree.cpp"

int main()
{
    BSTHashtable table(10);
    std::string str;
    int choice;
    while (1)
    {
        std::cout<<"\n----------------------"<<std::endl;
        std::cout<<"Operations on BST Hash Table"<<std::endl;
        std::cout<<"\n----------------------"<<std::endl;
        std::cout<<"1.Insert element into the table"<<std::endl;
        std::cout<<"2.Find element in the table"<<std::endl;
        std::cout<<"3.Display Table Chained with Binary Tree"<<std::endl;
        std::cout<<"4.Exit"<<std::endl;
        std::cout<<"Enter your choice: ";
        std::cin>>choice;
        switch(choice)
        {
        case 1:
            std::cout<<"Enter String to be inserted: ";
            std::cin>>str;
            table.add(str);
            break;
        case 2:
            std::cout<<"Enter String to search: ";
            std::cin>>str;
            if (table.contains(str) == 0)
            {
	        std::cout<<"String \""<<str<<"\" not found in the table"<<std::endl;
		continue;
	    }
            break;
        case 3:
            std::cout<<"Displaying Table Chained with Binary Tree: "<<std::endl;
            table.display();
            break;
        case 4:
            exit(1);
        default:
            std::cout<<"\nEnter correct option\n";
        }
    }
    return 0;
}