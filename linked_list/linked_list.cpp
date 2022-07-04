#include <iostream>

/*typedef struct 
{
    int value;
    Node* next;
} Node; 


struct Node
{
    int value;
    Node* next;
}; */

template <typename T>
struct Node
{
    T value;
    Node* next;
};
typedef Node<int> iNode;

int main()
{
    return 0;
}