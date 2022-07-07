#pragma once

#include <list>

class HashTableList
{
private:
    int buket;
    std::list<int> *table; 
    
public:
    HashTableList(int buket);
    ~HashTableList();
    void insertItem(int item);
    void deleteItem(int key);
    int hashFunction(int item);
    bool isItem(int item);
    void displayHashTable();
};