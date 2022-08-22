#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "graph.cpp"

// =============================================================
GNode* buildGraph(std::list<char> projects, std::list<std::pair<char, char>> dependecies)
{
    GNode* graph = new GNode();

    for (auto p : projects) 
    {
        GNode* temp = new GNode(int(p));
        graph->addChildren({temp});
    }
    for (auto d : dependecies) 

    return graph;
}

std::list<char> buildOrder(std::list<char> projects, std::list<std::pair<char, char>> dependecies)
{
    GNode* graph = buildGraph(projects, dependecies);
    

}

// =============================================================

int main()
{

}