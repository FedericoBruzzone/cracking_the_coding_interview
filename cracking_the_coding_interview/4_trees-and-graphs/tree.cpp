#pragma once

#include "../../ALL_H_FILES.h"

#include "treenode.cpp"

// =============================================================

template <typename T, bool WithParent = false, template <typename, bool> class N = Node>
class Tree
{
public:
    class TreeIsEmptyException : public std::exception
    {
        virtual const char* what() const throw()
        {
            return "TreeIsEmptyException";
        }
    };

    using NodePtr = typename N <T, WithParent>::NodePtr;

    const NodePtr &getRoot() const
    {
        if (isEmpty()) throw TreeIsEmptyException();
        return root;
    }

    template <typename U>
    void setRoot(U &&node) { root = std::forward<U>(node); }

    bool isEmpty() const { return !root; }

    
protected:
    NodePtr root;
};

template <typename T, bool WithParent = false>
using NodePtr = typename Tree<T, WithParent>::NodePtr;