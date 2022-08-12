#include "../../ALL_H_FILES.h"

#include "graph.cpp"

// =============================================================


// Depth-First Search
bool searchDFS(Graph g, Node start, Node end)
{
    
}

// =============================================================

// Breadth-First Search
bool searchBFS(Graph g, Node start, Node end)
{
    
}

// =============================================================

int main()
{
    Graph g;
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->addChildren({n2, n3, n4});

    g.printGraph();

    LOG("RESULT:")
    LOG(searchDFS(g, n1, n3))

    LOG("RESULT:")
    LOG(searchBFS(g, n1, n3))
}