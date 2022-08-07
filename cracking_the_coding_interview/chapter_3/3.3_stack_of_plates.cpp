#include "../../ALL_H_FILES.h"

#include "stack.cpp"

class SetOfStack
{
public:
    SetOfStack(int threshold)
    {
        this->threshold = threshold;
        stacks = std::vector<Stack<int>>();
    }

private:
    int threshold = 0;
    int elements = 0;
    std::vector<Stack<int>> stacks;
};