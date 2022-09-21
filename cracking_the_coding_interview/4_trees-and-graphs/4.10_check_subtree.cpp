#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "treetestutils.cpp"
#include "treenodeiterator.cpp"

// =============================================================

// first implementation
template <typename T>
bool matchTree(const NodePtr<T> &left, const NodePtr<T> &right);

template <typename T>
bool containsTree(const Tree<T> tree, const Tree<T> subtree)
{
    auto subtreeRoot = subtree.getRoot();
    if (!subtreeRoot) { return true; }

    auto subtreeRootValue = subtreeRoot->getValue();
    
    for (const auto &node : tree)
    {
        if (node->getValue() == subtreeRootValue)
            if (matchTree<T>(node, subtreeRoot))
                return true;
    }

    return false;
}

template <typename T>
bool matchTree(const NodePtr<T> &left, const NodePtr<T> &right)
{
    if (!left && !right) { return true; }   
    if (!left || !right) { return false; }

    if (left->getValue() == right->getValue())
        return matchTree<T>(left->getLeft(), right->getLeft()) &&
               matchTree<T>(left->getRight(), right->getRight());
    
    return false;
}

// second implementation
template <typename T>
bool subTree(const NodePtr<T> &root, const NodePtr<T> &subtreeRoot);

template <typename T>
bool compareTrees(const NodePtr<T> &left, const NodePtr<T> &right);


template <typename T>
bool containsTree(const Tree<T> &tree, const Tree<T> &subtree)
{
    if (!subtree.getRoot()) { return true; }
    return subTree<T>(tree.getRoot(), subtree.getRoot());
}

template <typename T>
bool subTree(const NodePtr<T> &root, const NodePtr<T> &subtreeRoot)
{
    if (!root) { return false; }
    if (root->getValue() == subtreeRoot->getValue() && matchTree<T>(root, subtreeRoot)) { return true; }
    return subTree<T>(root->getLeft(), subtreeRoot) || subTree<T>(root->getRight(), subtreeRoot);
}

template <typename T>
bool matchTree(const NodePtr<T> &left, const NodePtr<T> &right)
{
    if (!left && !right) { return true; }
    if (!left || !right) { return false; }
    if (left->getValue() == right->getValue())
        return matchTree<T>(left->getLeft(), right->getLeft()) && matchTree<T>(left->getRight(), right->getRight());
    return false;
}


// =============================================================

// int main()
// {
//     // // First implementation
//     // auto left = TestUtils::getSampleTree<int>(15);
//     // auto right = TestUtils::getSampleTree<int>(7);
//     // TestUtils::printTree(right);
//     // std::cout << (containsTree(left, right) ? "is subtree of\n" : "is not subtree of\n");
//     // TestUtils::printTree(left);

//     // right = TestUtils::getSampleTree<int>(8);
//     // TestUtils::printTree(right);
//     // std::cout << (containsTree(left, right) ? "is subtree of\n" : "is not subtree of\n");
//     // TestUtils::printTree(left);

//     // // Second implementation
//     // auto left = TestUtils::getSampleTree<int>(15);
//     // auto right = TestUtils::getSampleTree<int>(7);
//     // TestUtils::printTree(right);
//     // std::cout << (containsTree<int>(left, right) ? "is subtree of\n" : "is not subtree of\n");
//     // TestUtils::printTree(left);

//     // std::cout << std::endl;
//     // right = TestUtils::getSampleTree<int>(8);
//     // TestUtils::printTree(right);
//     // std::cout << (containsTree<int>(left, right) ? "is subtree of\n" : "is not subtree of\n");
//     // TestUtils::printTree(left);
// }