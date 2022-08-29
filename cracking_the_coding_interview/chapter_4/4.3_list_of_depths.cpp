#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "treetestutils.cpp"


// =============================================================

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

template <typename T>
void printDepths(const ListOfDepths<T> &depths)
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

int main()
{
    auto tree = TestUtils::getSampleTree<int>(15);
    TestUtils::printTree(tree);
    auto listOfDepths = createLevelLinkedListBFS1(tree);
    printDepths<int>(listOfDepths);

    tree = TestUtils::getSampleTree<int>(20);
    TestUtils::printTree(tree);
    listOfDepths = createLevelLinkedListBFS2(tree);
    printDepths<int>(listOfDepths);

    return 0;
}