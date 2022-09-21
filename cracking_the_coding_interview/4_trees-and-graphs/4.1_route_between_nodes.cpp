#include "../../ALL_H_FILES.h"

#include "graph.cpp"
#include "graphtestutils.cpp"

enum State {Unvisited, Visiting, Visited};

// =============================================================

// Breath-First Search
bool searchBFS(const Graph<State> &graph, const Node<State> &from, const Node<State> &to)
{
    if (from == to) { return true; }

    for (auto &n : graph.getNodes()) { n->state = Unvisited; }

    std::queue<Node<State>> queue;

    from->state = Visiting;
    queue.push(from);

    while (!queue.empty())
    {
        Node<State> n = queue.front();
        queue.pop();

        for (auto &c : n->getAdjacent())
        {
            auto v = c.lock();
            if (v && v->state == Unvisited)
            {
                if (v == to) 
                    return true;
                else
                {
                    v->state = Visiting;
                    queue.push(v);
                }
            }
        }
        n->state = Visited;
    }
    return false;
}

// =============================================================

// Depth-First Search
bool searchDFS(const Graph<State> &graph, const Node<State> &from, const Node<State> &to)
{
    if (from == to)
        return true;

    from->state = Visited;

    for (auto &c : from->getAdjacent())
    {
        auto node = c.lock();
        if (node && node->state != Visited)
        {
            if (searchDFS(graph, node, to))
                return true;
        }
    }
    return false;
}

bool searchDFSR(const Graph<State> &graph, const Node<State> &from, const Node<State> &to)
{
    for (auto &n : graph.getNodes())
        n->state = Unvisited;

    return searchDFS(graph, from, to);
}

// =============================================================

bool test(const Graph<State> &graph, size_t from, size_t to)
{
    auto &fromNode = graph[from];
    auto &toNode = graph[to];

    bool result = searchBFS(graph, fromNode, toNode);
    bool resultR = searchDFSR(graph, fromNode, toNode);

    assert(result == resultR);
    std::cout << "BFS: " << toNode->Name() << " is " << (result ? "" : "NOT ") << "reachable from " << fromNode->Name() << std::endl;
    std::cout << "DFS: " <<toNode->Name() << " is " << (resultR ? "" : "NOT ") << "reachable from " << fromNode->Name() << std::endl;
    return result;
}

void testGraph(const Graph<State> &graph)
{
    auto size = graph.getNodes().size();
    for (decltype(size) i = 0; i < size; ++i)
    {
        for (decltype(size) j = 0; j < size; ++j)
        {
            test(graph, i, j);
        }
        std::cout << std::endl;
    }   
}
// =============================================================

// int main()
// {
//     testGraph(TestUtils::getExampleGraph<State>());
//     std::cout << "============================================================="; printf("\n");printf("\n");
//     testGraph(TestUtils::getExampleGraph2<State>());
//     std::cout << "============================================================="; printf("\n");printf("\n");
//     testGraph(TestUtils::getExampleGraph3<State>());
//     std::cout << "============================================================="; printf("\n");printf("\n");
// }