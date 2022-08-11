#include "../../ALL_H_FILES.h"

#include "graph.cpp"

// =============================================================

// Depth-First Search
bool searchDFS(Graph g, int start, int end)
{
    if (start == end) return true;

    for (auto child : g._adjLists[start])
    {
        if (child == end) 
            return true;
        return searchDFS(g, child, end);
    }

    return false;
}

// =============================================================

// Breadth-First Search
bool searchBFS(Graph g, int start, int end)
{
    if (start == end) return true;

    std::queue<int> queue = std::queue<int>();
    
}

// =============================================================

int main()
{
    Graph g(3);

    g.addEdge(1, 2, false);

    g.addEdge(2, 3, false);

    g.addEdge(2, 4, false);

    g.printGraph();

    LOG("RESULT:")
    LOG(searchDFS(g, 1, 4))
}