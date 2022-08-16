#include "../../ALL_H_FILES.h"

#include "linked_list.cpp"

// =============================================================

// Intersecting linked list
// 8 -> 2 -> 5
//            \ 
//             \     
//              -> 4 -> 7 -> 1
//             /
//            /
//      3 -> 9  

// Not-intersecting linked list
// 8 -> 2 -> 5 -> 4 -> 7 -> 1            
// 4 -> 1 -> 6

class Result
{
public:
    Node* tail;
    int size;

    Result(Node* node, int size)
        : tail(node), size(size) {}
};

Result getTailAndSize(Node* node)
{
    if (node == NULL) return Result(NULL, 0);

    Node* current = node;
    int size = 1;

    while (current->next != NULL)
    {
        size++;
        current = current->next;
    }
    
    return Result(current, size);
}

Node* getKthNode(Node* node, int k)
{
    Node* current = node;

    while (k > 0 && !(current == NULL))
    {
        current = current->next;
        k--;
    }

    return current;
}

Node* findIntersection(Node* n1, Node* n2)
{
    if (n1 == NULL || n2 == NULL) return NULL;

    Result res1 = getTailAndSize(n1);
    Result res2 = getTailAndSize(n2);

    if (!(res1.tail == res2.tail)) return NULL;

    Node* shorter = res1.size < res2.size ? n1 : n2;
    Node* longer = res1.size < res2.size ? n2 : n1;

    longer = getKthNode(longer, std::abs(res1.size - res2.size)); 
    
    while (!(shorter == longer))
    {
        shorter = shorter->next;
        longer = longer->next;
    }

    return longer;

}

// =============================================================

// int main()
// {
//     Node* common = new Node(10);
//     common->appendToTail(11);
//     common->appendToTail(12);

//     Node* n1 = new Node(7);
//     n1->appendToTail(1);
//     n1->appendToTail(6);
//     n1->appendToTail(common);

//     Node* n2 = new Node(5);
//     n2->appendToTail(9);
//     n2->appendToTail(2);
//     n2->appendToTail(common);

//     n1->print(n1);
//     n2->print(n2);

//     Node* output = findIntersection(n1, n2);
//     output->print(output);
// }