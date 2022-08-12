#include "../../ALL_H_FILES.h"

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


// Depth-First Search
bool searchDFS(Graph g, Node start, Node end)
{
    if (start._data == end._data) return true;

    start._state = State::Visited;

    for (auto child : g._adjLists[start._data])
    {
        if (child._data == end._data) 
        {
            return true;
        }
        else if (child._state == State::Unvisited)
        {
            return searchDFS(g, child, end);
        }
    }

    return false;
}

// =============================================================

// Breadth-First Search
bool searchBFS(Graph g, Node start, Node end)
{
    if (start._data == end._data) return true;


    g.setUnvisited();

    std::queue<Node> queue = std::queue<Node>();
    
    start._state = State::Visited;
    queue.push(start);
    Node temp;

    while (!queue.empty())
    {
        temp = queue.front();
        queue.pop();

        for (std::list<Node>::iterator i = g._adjLists[temp._data].begin();
             i != g._adjLists[temp._data].end(); ++i)
        {
            if ((*i)._data == end._data)
                return true;
 
            if ((*i)._state == State::Unvisited)
            {
                (*i)._state = State::Visited;
                queue.push((*i));
            }
        }
    }
    return false;
}

// =============================================================

int main()
{
    Graph g(3);
    Node n1 = Node(1);
    Node n2 = Node(2);
    Node n3 = Node(3);
    Node n4 = Node(4);

    g.addEdge(n1, n2, false);

    g.addEdge(n2, n3, false);

    g.addEdge(n2, n4, false);

    g.printGraph();

    LOG("RESULT:")
    LOG(searchDFS(g, n1, n3))

    LOG("RESULT:")
    LOG(searchBFS(g, n1, n3))
}