#include "../../ALL_H_FILES.h"

// =============================================================

enum State { Unvisited, Visited, Visiting };

class Node
{
public:
    int _data;
    State _state;
    //std::vector<Node*> childern;

    Node() {}

    Node(int data)
    {
        this->_data = data;
        _state = Unvisited;
    }
};

// =============================================================

class Graph{
public:
    int _numVertices;
     std::list<Node>* _adjLists;

    Graph(int numVertices) 
    {
        this->_numVertices = numVertices;
        _adjLists = new std::list<Node> [_numVertices];
    }

    void addEdge(Node src, Node dest, bool bi)
    {
        _adjLists[src._data].push_back(dest);
        if (bi)
        {
            _adjLists[dest._data].push_back(src);
        }
    }

    void printGraph()
    {
        for (int d = 0; d < _numVertices; ++d)
        {
            std::cout << "\n Vertex " << d << ":";
            for (auto x : _adjLists[d])
            {
                std::cout << " -> " << x._data;
            }
            printf("\n");
        }
    }

    void setUnvisited()
    {
        for (int d = 0; d < _numVertices; ++d)
        {
            for (auto x : _adjLists[d])
            {
                x._state = Unvisited;
            }
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

// int main()
// {
//     Graph g(10);

//     g.addEdge(1, 2, false);
//     g.addEdge(2, 3, false);

//     g.printGraph();
// }