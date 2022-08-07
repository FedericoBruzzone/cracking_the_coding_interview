#include "../../ALL_H_FILES.h"

#include "stack.cpp"

class SetOfStack
{
public:
    SetOfStack(int threshold)
    {
        this->threshold = threshold;
    }

private:
    int threshold = 0;
    int elements = 0;
    std::vector<Stack<int>> stacks;
};