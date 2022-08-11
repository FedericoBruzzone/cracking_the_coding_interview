#include "../../ALL_H_FILES.h"

// =============================================================

class Graph{
public:
    int _numVertices;
     std::list<int>* _adjLists;

    Graph(int numVertices) 
    {
        this->_numVertices = numVertices;
        _adjLists = new std::list<int> [_numVertices];
    }

    void addEdge(int src, int dest, bool bi)
    {
        _adjLists[src].push_back(dest);
        if (bi)
        {
            _adjLists[dest].push_back(src);
        }
    }

    void printGraph()
    {
        for (int d = 0; d < _numVertices; ++d)
        {
            std::cout << "\n Vertex " << d << ": ";
            for (int x : _adjLists[d])
            {
                std::cout << "-> " << x;
            }
            printf("\n");
        }
    }
};

// =============================================================

// struct Node
// {
//     std::string data;
//     std::vector<struct Node*> children;
// };
// typedef struct Node Node;

// =============================================================

// class Node
// {
// public:
//     std::string name;
//     std::vector<Node*> children;
// };

// class Graph
// {
// public:
//     Node* root;
// };

// =============================================================

int main()
{
    Graph g(10);

    g.addEdge(1, 2, false);
    g.addEdge(2, 3, false);

    g.printGraph();
}