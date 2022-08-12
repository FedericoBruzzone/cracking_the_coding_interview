#include "../../ALL_H_FILES.h"

// =============================================================

// struct Node
// {
//     std::string data;
//     std::vector<struct Node*> children;
// };
// typedef struct Node Node;

// =============================================================

class Node
{
public:
    int data;
    std::vector<Node*> children;

    Node (int data)
    {
        children = std::vector<Node*>();
        this->data = data;
    }

    void addChildren(std::vector<Node*> children)
    {
        if (children.empty()) return;

        for (auto child : children)
        {
            children.push_back(child);
        }
    }

    void print()
    {
        std::cout << "\n Vertex " << this->data << ":";
        for (auto child : children)
        {
            std::cout << " -> " << child->data;
        }
            printf("\n");
    }
};

class Graph
{
public:
    Node* root;

    Graph() {}

    Graph(Node* root) 
    {
        this->root = root;
    }
};

// =============================================================

// int main()
// {
//     Graph g(10);

//     g.addEdge(1, 2, false);
//     g.addEdge(2, 3, false);

//     g.printGraph();
// }