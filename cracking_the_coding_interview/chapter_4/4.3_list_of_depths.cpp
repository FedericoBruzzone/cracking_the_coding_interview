#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "treetestutils.cpp"

// =============================================================

// Breadth-First Search
template <typename T>
using ListOfDepths = std::list<std::list<NodePtr<T>>>;

template <typename T>
ListOfDepths<T> createLevelLinkedListBFS1(const Tree<T> &tree)
{
    ListOfDepths<T> result;
    result.emplace_back();
    std::list<NodePtr<T>>* list = &result.back(); 
    
    list->push_back(tree.getRoot());
    
    do
    {
        result.emplace_back();
        std::list<NodePtr<T>> &childs = result.back(); 
        for (const NodePtr<T> &n : *list) 
        {
            if (n->getLeft()) childs.push_back(n->getLeft());
            if (n->getRight()) childs.push_back(n->getRight());
        }

        if (childs.empty())
        {
            result.pop_back();
            break;
        }
        list = &childs;
    } while (true);

    return result;
}

// Breadth-First Search
template <typename T>
ListOfDepths<T> createLevelLinkedListBFS2(const Tree<T> &tree)
{
    ListOfDepths<T> result;
    std::list<NodePtr<T>> current;

    current.push_back(tree.getRoot());

    while (current.size() > 0)
    {
        result.push_back(current);
        std::list<NodePtr<T>> childs = current;
        current.clear();

        for (const NodePtr<T> child : childs)
        {
            if (child->getLeft()) current.push_back(child->getLeft());
            if (child->getRight()) current.push_back(child->getRight());
        }
    }
    
    return result;
}

// =============================================================

// Depth-First Search
template <typename T>
using VectorOfDepths = std::vector<std::list<NodePtr<T>>>;

template <typename T>
void createLevelLinkedListDFS(NodePtr<T> root, VectorOfDepths<T>* lists, int index)
{
    if (root == nullptr) return;

    std::list<NodePtr<T>> list;

    if (lists->size() == index)
    {
        list = std::list<NodePtr<T>>();
        list.push_back(root);
        lists->push_back(list); 
    }
    else
    {   
        lists->at(index).push_back(root);
    }

    createLevelLinkedListDFS<T>(root->getLeft(), lists, index + 1);
    createLevelLinkedListDFS<T>(root->getRight(), lists, index + 1);
}

template <typename T>
VectorOfDepths<T> createLevelLinkedListDFS(Tree<T> &tree)
{
    VectorOfDepths<T>* lists = new VectorOfDepths<T>();;
    createLevelLinkedListDFS<T>(tree.getRoot(), lists, 0);
    return *lists;
}


// =============================================================

template <typename T>
void printDepths(const T &depths) // T can be ListOfDepths<T> or VectorOfDepths<T>
{
    std::cout << "Nodes:\n";
    int depth = 0;
    for (const auto &line : depths)
    {
        std::cout << depth << ": ";
        auto sep = "";
        for (const auto &n : line)
        {
            std::cout << sep << n->getValue();
            sep = ", ";
        }
        std::cout << std::endl;
        ++depth;
    }
    std::cout << std::endl;
}

// =============================================================

// int main()
// {
//     auto tree = TestUtils::getSampleTree<int>(15);
//     TestUtils::printTree(tree);
//     auto listOfDepths = createLevelLinkedListBFS1(tree);
//     printDepths(listOfDepths);

//     tree = TestUtils::getSampleTree<int>(20);
//     TestUtils::printTree(tree);
//     listOfDepths = createLevelLinkedListBFS2(tree);
//     printDepths(listOfDepths);

//     tree = TestUtils::getSampleTree<int>(20);
//     TestUtils::printTree(tree);
//     auto vectorOfDepths = createLevelLinkedListDFS(tree);
//     printDepths(vectorOfDepths);

//     return 0;
// }