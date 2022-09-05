#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "treetestutils.cpp"
#include "treenodeiterator.cpp"

// =============================================================

// Without Links to Parent
enum FindResult
{
    NotFound,
    FoundLeft,
    FoundRight,
    FoundEqual
};

template <typename T>
FindResult commonAncestorHelper(const NodePtr<T, false> &startNode, const NodePtr<T, false> &node)
{
    if (!startNode) { return NotFound; }
    if (startNode == node) { return FoundEqual; }
    if (commonAncestorHelper<T>(startNode->getLeft(), node) != NotFound) { return FoundLeft; }
    if (commonAncestorHelper<T>(startNode->getRight(), node) != NotFound) { return FoundRight; }
    return NotFound;
}

template <typename T>
NodePtr<T> commonAncestor(const Tree<T, false> &tree, const NodePtr<T, false> &one, const NodePtr<T, false> &two)
{
    if (one == two) { return one; }

    auto startNode = tree.getRoot();

    auto firstResult = commonAncestorHelper<T>(startNode, one);
    if (firstResult == NotFound) { return nullptr; }
    auto secondResult = commonAncestorHelper<T>(startNode, two);
    if (secondResult == NotFound) { return nullptr; }

    while (firstResult == secondResult)
    {
        startNode = (firstResult == FoundLeft) ? startNode->getLeft() : startNode->getRight();
        firstResult = commonAncestorHelper<T>(startNode, one);
        secondResult = commonAncestorHelper<T>(startNode, two);
    }

    return startNode;
}

// =============================================================

// int main()
// {
//     auto tree = TestUtils::treeFromArray({10, 1, 12, 3, 14, 25, 16, 27, 18, 29, 10, 13, 2, 15, 4, 5, 17, 7, 19, 9});
//     TestUtils::printTree(tree);

//     for (auto one : tree)
//     {
//         if (one == tree.getRoot())
//             continue; 
//         for (auto two : tree)
//         {
//             if (two == tree.getRoot() || two == one)
//                 continue; 
//             auto ancestor = commonAncestor<int>(tree, one, two);
//             std::cout << one->getValue() << ", " << two->getValue() << " <-- ";
//             std::cout << (ancestor ? std::to_string(ancestor->getValue()) : "NOT FOUND") << std::endl;
//         }
//     }

//     // Test nodes of different trees
//     auto tree2 = TestUtils::getSampleTree<int>(7);
//     auto node1 = tree.getRoot()->getLeft()->getRight();
//     auto node2 = tree2.getRoot()->getRight()->getLeft();
//     auto ancestor = commonAncestor<int>(tree, node1, node2);
//     std::cout << "Nodes below are of diffent trees:\n";
//     std::cout << node1->getValue() << ", " << node2->getValue() << " <-- ";
//     std::cout << (ancestor ? std::to_string(ancestor->getValue()) : "NOT FOUND") << std::endl;
// }