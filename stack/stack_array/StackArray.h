#pragma once
#include <vector>

#define MAX_LENGTH 1000

//template <typename T, size_t N>
template <typename T>
class StackArray
{
private:
    int top = -1;
    std::vector<T> stack;
    //T stack[N];
    //T stack[MAX_LENGTH];

public:
    StackArray();
    StackArray(size_t length);
    ~StackArray();

    bool push(T value);
    T pop();
    T peek();
    bool isEmpty();
    int length();
};