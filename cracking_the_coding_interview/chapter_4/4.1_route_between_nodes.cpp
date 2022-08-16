#include "../../ALL_H_FILES.h"

#include "graph.cpp"

// =============================================================

// Depth-First Search
bool searchDFS(Node* start, Node* end)
{
    if (start == end) return true;
    
    start->_state = Visited;

    for (auto child = std::begin(start->_children); child != std::end(start->_children); ++child)
    {   
        if ((*child)->_state == Unvisited)
            if (searchDFS((*child), end))
                return true;
    }
    start->setUnvisited();
    return false;
}

// // =============================================================

// Breadth-First Search
bool searchBFS(Node* start, Node* end)
{
    if (start == end) return true;

    start->setUnvisited();
    start->_state = Visited;
    std::list<Node*> queue;
    queue.push_back(start);

    while (!queue.empty())
    {
        start = queue.front();
        queue.pop_front();
 
        for (std::vector<Node*>::iterator child = std::begin(start->_children); child != std::end(start->_children); ++child)
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

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);

    n1->addChildren({n2, n3, n4}); //std::vector<Node*> children = std::vector<Node*>({n1, n2, n3});
    n2->addChildren({n5, n6, n7});
    n3->addChildren({n8, n9});
    n1->print();

    LOG(searchDFS(n1, n9))
    LOG(searchDFS(n1, n10))

    LOG(searchBFS(n1, n9))
    LOG(searchBFS(n1, n10))

}