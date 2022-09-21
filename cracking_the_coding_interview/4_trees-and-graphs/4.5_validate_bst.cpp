#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "treetestutils.cpp"

// =============================================================

// First implementation
template <typename T> 
const T *lastVisited = nullptr;

template <typename T>
bool checkBSTInOrder(const NodePtr<T> &node)
{
    if (node == nullptr) { return true; }

    if (!checkBSTInOrder<T>(node->getLeft())) { return false; }

    if (lastVisited<T> != nullptr && node->getValue() <= *lastVisited<T>) { return false; }

    lastVisited<T> = &(node->getValue()); 

    if (!checkBSTInOrder<T>(node->getRight())) { return false; }

    return true;
}

template <typename T>
bool checkBSTInOrder(const Tree<T> &tree)
{
    return checkBSTInOrder<T>(tree.getRoot());
}

// =============================================================

// Second implementation
template <typename T>
bool checkBST(const NodePtr<T> &node, const T *min, const T *max)
{
    if (!node) { return true; }
    if (min && node->getValue() <= *min) { return false; }
    if (max && node->getValue() > *max) { return false; }

    return checkBST<T>(node->getLeft(), min, &node->getValue()) &&
           checkBST<T>(node->getRight(), &node->getValue(), max);
}

template <typename T>
bool checkBST(const Tree<T> &tree)
{
    return checkBST<T>(tree.getRoot(), nullptr, nullptr);
}

// =============================================================

int main()
{
    auto tree = TestUtils::getSampleTree<int>(20);
    TestUtils::printTree(tree);
    std::cout << "First implementation: The tree is " << (checkBSTInOrder<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;
    std::cout << "Second implementation: The tree is " << (checkBST<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;

    tree.getRoot()->getRight()->getRight()->getRight()->setLeftChild(std::make_shared<Node<int>>(19));
    TestUtils::printTree(tree);
    std::cout << "First implementation: The tree is " << (checkBSTInOrder<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;
    std::cout << "Second implementation: The tree is " << (checkBST<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;

    tree.getRoot()->getRight()->getRight()->getRight()->setLeftChild(std::make_shared<Node<int>>(15));
    TestUtils::printTree(tree);
    std::cout << "First implementation: The tree is " << (checkBSTInOrder<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;
    std::cout << "Second implementation: The tree is " << (checkBST<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;
}