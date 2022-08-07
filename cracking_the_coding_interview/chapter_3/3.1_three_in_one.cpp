#include "../../ALL_H_FILES.h"

#include "stack.cpp"

// =============================================================

// SOLUTION

// Like many problems, this one somewhat depends on how well we would like to support there stacks.
// If we are okay with simply allocating a fixed amount of space for each stack, we can do that. 
// This may mean though that one stack runs out of space, while the others are nearly empty.

// Alternatively, we can be flexible in our space allocation, but this significanly increases the complexity of the problem.

// =============================================================

// Approach 1: Fixed Division
// We can divide the array in threee etual parts and allow the individual stack to grow in that limited space.
// Note: I will use the notation "[" to mean inclusive of an end point and "(" to mean exlusive of end point.

// - For stack 1, I will use [   0,  n/3).
// - For stack 1, I will use [ n/3, 2n/3).
// - For stack 1, I will use [2n/3,  n  ).

// The code for this solution is below

// class FullStackException : public std::exception
// {
//     virtual const char* what() const throw()
//     {
//         return "FullStackException";
//     }
// };

// class FixedMultiStack
// {
// private: 
//     int numberOfStack = 3;
//     int stackCapacity;
//     std::vector<int> values;
//     std::vector<int> sizes;

//     int indexFOfTop(int stackNum)
//     {
//         int offset = stackNum * stackCapacity;
//         int size = sizes[stackNum];
//         return size + offset - 1;
//     }

// public:
//     FixedMultiStack(int stackSize)
//     {
//         stackCapacity = stackSize;
//         values = std::vector<int>(stackSize * numberOfStack);
//         sizes = std::vector<int>(numberOfStack);
//     }

//     bool isFull (int stackNum) { return sizes[stackNum] == stackCapacity; }
//     bool isEmpty(int stackNum) { return sizes[stackNum] == 0; }

//     void push(int stackNum, int value)
//     {
//         if (isFull(stackNum)) throw FullStackException();
        
//         sizes[stackNum]++;
//         values[indexFOfTop(stackNum)] = value;
//     }

//     int pop(int stackNum)
//     {
//         if (isEmpty(stackNum)) throw FullStackException();
        
//         int top_index = indexFOfTop(stackNum);
//         int value = values[top_index];
//         values[top_index] = 0;
//         sizes[stackNum]--;
//         return value;
//     }

//     int peek(int stackNum)
//     {
//         if (isEmpty(stackNum)) throw FullStackException();
        
//         return values[indexFOfTop(stackNum)];
//     }
// };

// =============================================================

// Approach 2: Flexible Divisions
// A second approach is to allow the stack blocks to be flexible in size.
// WHen one stack exceeds its inital capacity, we grow the allowable and shift elements as necessary.

// We will also design our array to be circualar, such that the final stack may start at the end of the array 
// and wrap around to the beginning.

// Please note that the code for this solution is far more complex than would be appropriate for an interview.
// You could be responsible for pseudocode, or perhaps the code of individual componenets, but the entire implementation
// would be far too much work.

// The code for this solution is below

class FullStackException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "FullStackException";
    }
};

class EmptyStackException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "EmptyStackException";
    }
};

class MultiStack
{
private:
    class StackInfo
    {
    public:
        int start, size, capacity;

        StackInfo(int start, int capacity)
        {
            start = start;
            capacity = capacity;
        }

        bool isFull()  { return size == capacity; }
        bool isEmpty() { return size == 0; }
        int lastCapacityIndex(MultiStack* multiStack) { return multiStack->adjustIndex(start + capacity - 1); }
        int lastElementIndex(MultiStack* multiStack)  { return multiStack->adjustIndex(start + size - 1); }
        
        bool isWithinStackCapacity(int index, MultiStack* multiStack)
        {
            if (index < 0 || index >= multiStack->values.size())
                return false;
            
            int contiguosIndex = index < start ? index + multiStack->values.size() : index;
            int end = start + capacity;
            return start <= contiguosIndex && contiguosIndex < end;
        }

    };

    std::vector<StackInfo> info;
    std::vector<int> values;

    int adjustIndex(int index) 
    { 
        int max = values.size();
        return ((index % max) + max) % max; 
    }

    int nextIndex(int index)    { return adjustIndex(index + 1); }
    int previusIndex(int index) { return adjustIndex(index - 1); }

    void shift(int stackNum)
    {
        std::cout << "/// Shifting " + stackNum << std::endl;
        StackInfo stack = info[stackNum];

        if (stack.size >= stack.capacity)
        {
            int nextStack = (stackNum + 1) % info.size();
            shift(nextStack);
            stack.capacity++;
        }

        int index = stack.lastCapacityIndex(this);
        while (stack.isWithinStackCapacity(index, this))
        {
            values[index] = values[previusIndex(index)];
            index = previusIndex(index);
        }

        values[stack.start] = 0;
        stack.start = nextIndex(stack.start);
        stack.capacity--;

    }

    void expand(int stackNum)
    {
        shift((stackNum + 1) % info.size());
        info[stackNum].capacity++;
    }

public:
    MultiStack(int numeberOfStack, int defaultSize)
    {
        info = std::vector<StackInfo>(defaultSize);

        for (int i = 0; i < numeberOfStack; i++)
        {
            info[i] = StackInfo(i * defaultSize, defaultSize);
        }

        values = std::vector<int>(numeberOfStack * defaultSize);
    }

    int numberOfElements()
    {
        int size = 0;
        for (StackInfo sd : info) 
        {
            size += sd.size;
        }
        return size;
    }

    bool allStackAreFull() { return numberOfElements() == values.size(); }

    void push(int stackNum, int value)
    {
        if (allStackAreFull()) throw FullStackException();

        StackInfo stack = info[stackNum];
        if (stack.isFull())
        {
            expand(stackNum);
        }
    }

    int peek(int stackNum)
    {
        StackInfo stack = info[stackNum];
        return values[stack.lastElementIndex(this)];
    }

    int pop(int stackNum)
    {
        StackInfo stack = info[stackNum];
        if (stack.isEmpty()) throw EmptyStackException();

        int value = values[stack.lastElementIndex(this)];
        stack.size--;
        return value;
    }
};

// =============================================================

int main()
{

}