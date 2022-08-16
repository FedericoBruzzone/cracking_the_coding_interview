#include "../../ALL_H_FILES.h"

#include "graph.cpp"

// =============================================================

// Depth-First Search
bool searchDFS(GNode* start, GNode* end)
{
    if (start == end) return true;
    
    start->_state = Visited;

    for (auto child = std::begin(start->_children); child != std::end(start->_children); ++child)
    {   
        if ((*child)->_state == Unvisited)
            if (searchDFS((*child), end))
                return true;
    }
    
    return false;
}

// =============================================================

// Breadth-First Search
bool searchBFS(GNode* start, GNode* end)
{
    if (start == end) return true;

    start->setUnvisited();
    start->_state = Visited;
    std::list<GNode*> queue;
    queue.push_back(start);

    while (!queue.empty())
    {
        start = queue.front();
        queue.pop_front();
 
        for (std::vector<GNode*>::iterator child = std::begin(start->_children); child != std::end(start->_children); ++child)
        {
            if ((*child) == end) return true;

            if ((*child)->_state == Unvisited)
            {
                (*child)->_state == Visited;
                queue.push_back((*child));
            }
        }
    }  
    
    return false;
} 

// =============================================================

// int main()
// {
//     GNode* n1 = new GNode(1);
//     GNode* n2 = new GNode(2);
//     GNode* n3 = new GNode(3);
//     GNode* n4 = new GNode(4);
//     GNode* n5 = new GNode(5);
//     GNode* n6 = new GNode(6);
//     GNode* n7 = new GNode(7);
//     GNode* n8 = new GNode(8);
//     GNode* n9 = new GNode(9);
//     GNode* n10 = new GNode(10);

//     n1->addChildren({n2, n3, n4}); //std::vector<Node*> children = std::vector<Node*>({n1, n2, n3});
//     n2->addChildren({n5, n6, n7});
//     n3->addChildren({n8, n9});
//     n1->print();

//     LOG(searchDFS(n1, n9))
//     LOG(searchDFS(n1, n10))

//     LOG(searchBFS(n1, n9))
//     LOG(searchBFS(n1, n10))

// }