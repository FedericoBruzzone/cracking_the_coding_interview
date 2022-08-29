#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "treetestutils.cpp"


// =============================================================

template <typename T>
using ListOfDepths = std::list<std::list<NodePtr<T>>>;

template <typename T>
ListOfDepths<T> createLevelLinkedListBFS(const Tree<T> &tree)
{
    ListOfDepths<T> result;
    result.emplace_back();
    auto list = &result.back(); // std::list<NodePtr<T>>*
    list->push_back(tree.getRoot());
    
    do
    {
        result.emplace_back();
        auto &childs = result.back(); // std::list<NodePtr<T>>

        for (const auto &n : *list) // NodePtr<T>
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
    auto listOfDepths = createLevelLinkedListBFS(tree);
    printDepths<int>(listOfDepths);

    tree = TestUtils::getSampleTree<int>(20);
    TestUtils::printTree(tree);
    listOfDepths = createLevelLinkedListBFS(tree);
    printDepths<int>(listOfDepths);

    return 0;
}