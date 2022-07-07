#pragma once

#include <list>

class HashTable
{
private:
    int buket;
    std::list<int> *table; 
    
public:
    HashTable(int buket);
    ~HashTable();
    void insertItem(int item);
    void deleteItem(int key);
    int hashFunction(int item);
    bool isItem(int item);
    void displayHashTable();
};