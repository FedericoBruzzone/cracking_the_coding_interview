#include "../../ALL_H_FILES.h"

#include "graph.cpp"
#include "graphtestutils.cpp"

// =============================================================

// First implementation
std::list<Node<int>> buildOrder(const Graph<int> &graph)
{
    std::list<Node<int>> order;
    auto &projects = graph.getNodes();

    for (auto &n : projects)
    {
        for (auto &c : n->getAdjacent())
        {
            c.lock()->state++;
        }
    }

    for (auto &n : projects)
    {
        if (n->state == 0)
        {
            order.push_back(n);
        }
    }

    for (auto &p : order)
    {
        for (auto &c : p->getAdjacent())
        {
            auto n = c.lock();
            if (n && (--n->state) == 0) { order.push_back(n); }
        }
    }

    if (order.size() != projects.size()) { order.clear(); }

    return order; 
}

void test(const Graph<int> &graph)
{
    auto order = buildOrder(graph);

    const char *sep = "";
    for (auto &n : order)
    {
        std::cout << sep << n->Name();
        sep = ", ";
    }
    std::cout << std::endl;
}

// =============================================================

// Second implementation
enum class States
{
    NotVisited,
    Visiting,
    Visited
};

bool buildProject(const Node<States> &node, std::list<Node<States>> &order)
{
    if (node->state == States::Visited) { return true; }

    if (node->state == States::Visiting)
    {
        order.empty();
        return false;
    }

    node->state = States::Visiting;
    for (auto &a : node->getAdjacent())
    {
        auto prj = a.lock();
        if (prj)
            if (!buildProject(prj, order))
                return false;
    }
    node->state = States::Visited;
    order.push_front(node);
    return true;
}

std::list<Node<States>> buildOrder(const Graph<States> &graph)
{
    std::list<Node<States>> order;
    auto &projects = graph.getNodes();
    for (auto &p : projects)
        if (!buildProject(p, order))
            break;
    return order;
}

void test(const Graph<States> &graph)
{
    auto order = buildOrder(graph);

    const char *sep = "";
    for (auto &n : order)
    {
        std::cout << sep << n->Name();
        sep = ", ";
    }
    std::cout << std::endl;
}

// =============================================================

// // First implementation
// int main()
// {
//     test(TestUtils::createGraph<int>({"a", "b", "c", "d", "e", "f"},
//         {{"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}}));

//     test(TestUtils::createGraph<int>({"a", "b", "c", "d", "e", "f", "g"},
//         {{"a", "e"}, {"b", "a"}, {"b", "e"}, {"c", "a"}, {"d", "g"}, {"f", "a"}, {"f", "b"}, {"f", "c"}}));
// }

// // Second implementation
// int main()
// {
//     test(TestUtils::createGraph<States>({"a", "b", "c", "d", "e", "f"},
//         {{"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}}));
    
//     test(TestUtils::createGraph<States>({"a", "b", "c", "d", "e", "f", "g"},
//         {{"a", "e"}, {"b", "a"}, {"b", "e"}, {"c", "a"}, {"d", "g"}, {"f", "a"}, {"f", "b"}, {"f", "c"}}));
// }