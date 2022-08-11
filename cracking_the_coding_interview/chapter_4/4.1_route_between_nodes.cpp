#include "../../ALL_H_FILES.h"

#include "graph.cpp"

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