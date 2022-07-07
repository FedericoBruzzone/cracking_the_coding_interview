#include "HashTableList.h"

HashTableList::HashTableList(int buket)
{
    this->buket = buket;
    table = new std::list<int>[buket];
}

HashTableList::~HashTableList() {}

void HashTableList::insertItem(int item)
{
    int index = hashFunction(item);
    table[index].push_back(item);
}

void HashTableList::deleteItem(int key)
{
    int index = hashFunction(key);

    std::list<int>::iterator i;
    for (i = table[index].begin();
            i != table[index].end(); i++)
    {
        if (*i == key)
            break;
    }

    if (i != table[index].end())
        table[index].erase(i);
}

void HashTableList::displayHashTable()
{
    for (int i=0; i < buket; i++)
    {
        std::cout << i;
        for (auto x : table[i])
        {
            std::cout << "-->" << x;
        }
        std::cout << std::endl;
    }
}

bool HashTableList::isItem(int item)
{
    int index = hashFunction(item);

    std::list<int>::iterator i;
    for (i = table[index].begin();
            i != table[index].end(); i++)
    {
        if (*i == item)
            return true;
    }

    return false;
}

int HashTableList::hashFunction(int item)
{
    return item % buket;
}