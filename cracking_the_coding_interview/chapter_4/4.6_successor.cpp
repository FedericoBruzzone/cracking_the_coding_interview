#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "treetestutils.cpp"

// =============================================================

template <typename T>
NodePtr<T, true> leftMostChild(NodePtr<T, true> node)
{
    if (!node) { return nullptr; }

    while (node->getLeft())
        node = node->getLeft();

    return node;
}

template <typename T>
NodePtr<T, true> inorderSucc(NodePtr<T, true> node)
{
    if (!node) { return nullptr; }
    if (node->getRight()) { return leftMostChild<T>(node->getRight()); }

    auto parent = node->getParent();

    while (parent && node == parent->getRight())
    {
        node = parent;
        parent = parent->getParent();
    }

    return parent;
}

// =============================================================

int main()
{
    auto tree = TestUtils::getSampleTree<int, true>(20);
    TestUtils::printTree(tree);
    auto node = leftMostChild<int>(tree.getRoot());
    node = inorderSucc<int>(node);
    std::cout << " --> " << node->getValue();
    
    // if (node)
    // {
    //     std::cout << node->getValue();
    //     for (node = inorderSucc<int>(node); node; node = inorderSucc<int>(node))
    //         std::cout << " --> " << node->getValue();
    //     std::cout << std::endl;
    // }
}