#pragma once

#include "../../../ALL_H_FILES.h"

// =============================================================

// struct Node
// {
//     std::string data;
//     std::vector<struct Node*> children;
// };
// typedef struct Node Node;

// =============================================================

enum State { Unvisited, Visited, Visiting };

class GNode
{
public:
    int _data;
    State _state;
    std::vector<GNode*> _children;

    GNode() 
    {
        _children = std::vector<GNode*>();
        this->_data = NULL;
        _state = Unvisited;
    }

    GNode (int data)
    {
        _children = std::vector<GNode*>();
        this->_data = data;
        _state = Unvisited;
    }

    void addChildren(std::vector<GNode*> children)
    {
        if (children.empty()) return;

        for (std::vector<GNode*>::iterator child = std::begin(children); child != std::end(children); ++child)
        {
            _children.push_back(*child);
        }
    }

    void setUnvisited()
    {
        this->_state = Unvisited;

        for (std::vector<GNode*>::iterator child = std::begin(_children); child != std::end(_children); ++child)
        {
            (*child)->setUnvisited();
        }
    }

    void print()
    {
        std::cout << "Root: ";
        print(6);
        setUnvisited();
    }

private:
    // DFS
    void print(int n) 
    {
        std::cout << this->_data;
        printf("\n");
        
        this->_state = Visited;

        for (std::vector<GNode*>::iterator child = std::begin(_children); child != std::end(_children); ++child)
        {
            for (int s = 0; s < n; ++s) { std::cout << " "; }
            if ((*child)->_state == Unvisited)
                (*child)->print(n+1);
        }
    }

};

// class Graph
// {
// public:
//     Node* _root;

//     Graph() {}

//     Graph(Node* root) 
//     {
//         this->_root = root;
//     }
// };

// =============================================================

// int main()
// {
//     Graph g(10);

//     g.addEdge(1, 2, false);
//     g.addEdge(2, 3, false);

//     g.printGraph();
// }