#include "../../ALL_H_FILES.h"

#include "queue.cpp"
#include "stack.cpp"

// SOLUTION

// Like many problems, this one somewhat depends on how well we would like to support there stacks.
// If we are okay with simply allocating a fixed amount of space for each stack, we can do that. 
// This may mean though that one stack runs out of space, while the others are nearly empty.

// Alternatively, we can be flexible in our space allocation, but this significanly increases the complexity of the problem.



// Approach 1: Fixed Division
// We can divide the array in threee etual parts and allow the individual stack to grow in that limited space.
// Note: I will use the notation "[" to mean inclusive of an end point and "(" to mean exlusive of end point.

// - For stack 1, I will use [   0,  n/3).
// - For stack 1, I will use [ n/3, 2n/3).
// - For stack 1, I will use [2n/3,  n  ).

// The code for this solution is below
class FullStackException 
    : public std::exception
{
    virtual const char* what() const throw()
    {
        return "FullStackException";
    }
};
class FixedMultiStack
{
private: 
    int numberOfStack = 3;
    int stackCapacity;
    std::vector<int> values;
    std::vector<int> sizes;

public:
    FixedMultiStack(int stackSize)
    {
        stackCapacity = stackSize;
        values.resize(stackSize * numberOfStack);
        sizes.resize(numberOfStack);
    }

    bool isFull(int stackNum) 
    { 
        return sizes[stackNum] == stackCapacity; 
    }

    void push(int stackNum, int value) throw (FullStackException)
    {
        if (isFull(stackNum))
            throw FullStackException();
        
        sizes[stackNum]++;
        values[sizes[stackNum]] = value;
    }

};