#include <iostream>
#include "HashTableList.h"
#include "HashTableList.cpp"

int main()
{
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a)/sizeof(a[0]);

    HashTableList hashTableList(7);

    for (int i=0; i < n; i++)
    {
        hashTableList.insertItem(a[i]);
    }

    hashTableList.deleteItem(12);

    std::cout << hashTableList.isItem(15) << std::endl;
    std::cout << hashTableList.isItem(12) << std::endl;
    std::cout << std::endl;
    hashTableList.displayHashTable();

    return 0;
}