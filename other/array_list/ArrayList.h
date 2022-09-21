#pragma once

#include "../../../ALL_H_FILES.h"

template <typename T> 
class ArrayList 
{
private:

    int arraySize;
    int size; 
    T *data = nullptr;

    bool needsExpansion();
    void expandArray();
    bool isValidIndex(int index);

public:
    ArrayList();
    ~ArrayList();

    T get(int index);
    int indexOf(T &d);
    void add(T &d);
    void add(T &d, int index);
    bool remove(int index);
    bool contains(T &d);
    void clear();
    bool isEmpty();
    inline int listSize();
};