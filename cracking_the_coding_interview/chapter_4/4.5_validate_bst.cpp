#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "treetestutils.cpp"

// =============================================================

// First implementation
template <typename T>
bool isBinarySearchTree(const NodePtr<T> &node, const T* lastVisited)
{
    if (node == nullptr) { return true; }

    if (!isBinarySearchTree(node->getLeft(), lastVisited)) { return false; }

    if (lastVisited != nullptr && node->getValue() <= *lastVisited) { return false; }

    lastVisited = &(node->getValue()); 

    if (!isBinarySearchTree(node->getRight(), lastVisited)) { return false; }

    return true;
}

template <typename T>
bool isBinarySearchTree(const Tree<T> &tree)
{
    return isBinarySearchTree<T>(tree.getRoot(), nullptr);
}

// =============================================================

int main()
{
    auto tree = TestUtils::getSampleTree<int>(20);
    TestUtils::printTree(tree);
    std::cout << "The tree is " << (isBinarySearchTree<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;

    tree.getRoot()->getRight()->getRight()->getRight()->setLeftChild(std::make_shared<Node<int>>(19));
    TestUtils::printTree(tree);
    std::cout << "The tree is " << (isBinarySearchTree<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;

    tree.getRoot()->getRight()->getRight()->getRight()->setLeftChild(std::make_shared<Node<int>>(15));
    TestUtils::printTree(tree);
    std::cout << "The tree is " << (isBinarySearchTree<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;
}