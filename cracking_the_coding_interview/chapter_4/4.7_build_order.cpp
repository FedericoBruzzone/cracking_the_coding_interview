#include "../../ALL_H_FILES.h"

#include "graph.cpp"
#include "graphtestutils.cpp"

// =============================================================

std::list<Node<int>> buildOrder(const Graph<int> &graph)
{
    std::list<Node<int>> order;
    auto &projects = graph.getNodes();

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

int main()
{
    test(TestUtils::createGraph<int>({"a", "b", "c", "d", "e", "f"},
        {{"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}}));

    test(TestUtils::createGraph<int>({"a", "b", "c", "d", "e", "f", "g"},
        {{"a", "e"}, {"b", "a"}, {"b", "e"}, {"c", "a"}, {"d", "g"}, {"f", "a"}, {"f", "b"}, {"f", "c"}}));
}