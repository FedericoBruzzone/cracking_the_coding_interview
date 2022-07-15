#pragma once

#include "../../../ALL_H_FILES.h"

#define MAX_LENGTH 1000

//template <typename T, size_t N>
template <typename T>
class Stack
{
private:
    int top = -1;
    std::vector<T> stack;
    //T stack[N];
    //T stack[MAX_LENGTH];

public:
    Stack();
    Stack(size_t length);
    ~Stack();

    bool push(T value);
    T pop();
    T peek();
    bool isEmpty();
    int length();
};