#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "treetestutils.cpp"

// =============================================================

template <typename T>
int getHeight(const NodePtr<T> &root)
{
    if (root == nullptr) return -1;
    return std::max(getHeight<T>(root->getLeft()),getHeight<T>(root->getLeft())) + 1;
}

template <typename T>
bool isBalanced(const NodePtr<T> &root)
{
    if (root == nullptr) return -1;

    int heightDiff = std::abs(getHeight<T>(root->getLeft()) - getHeight<T>(root->getRight()));
    if (heightDiff > 1) 
    { 
        return false; 
    }
    else 
    { 
        return isBalanced<T>(root->getLeft()) && isBalanced<T>(root->getRight()); 
    }
}

// =============================================================

template <typename T>
int checkHeight(const NodePtr<T> &node) 
{
    if (!node) return 0;

    int leftHeight = checkHeight<T>(node->getLeft());
    if (leftHeight == -1) { return -1; }

    int rightHeight = checkHeight<T>(node->getRight());
    if (rightHeight == -1) { return -1; }

    if (std::abs(leftHeight - rightHeight) > 1) { return -1; }

    return std::max(leftHeight, rightHeight) + 1;
}

template <typename T>
bool isBalanced(const Tree<T> &tree)
{
    return checkHeight<T>(tree.getRoot()) != -1;
}

// =============================================================

// int main()
// {
//     auto tree = TestUtils::getSampleTree<int>(20);
//     std::cout << "Tree is " << (isBalanced<int>(tree.getRoot()) ? "" : "NOT ") << "balanced" << std::endl;

//     auto r = tree.getRoot()->getRight();
//     tree.getRoot()->getRight() = std::make_shared<Node<int>>(100);
//     std::cout << "Tree is " << (isBalanced<int>(tree.getRoot()) ? "" : "NOT ") << "balanced" << std::endl;

//     tree.getRoot()->getRight() = r; 
//     std::cout << "Tree is " << (isBalanced<int>(tree.getRoot()) ? "" : "NOT ") << "balanced" << std::endl;

//     std::cout << "=============================================================" << std::endl;

//     tree = TestUtils::getSampleTree<int>(20);
//     std::cout << "Tree is " << (isBalanced<int>(tree) ? "" : "NOT ") << "balanced" << std::endl;

//     r = tree.getRoot()->getRight();
//     tree.getRoot()->getRight() = std::make_shared<Node<int>>(100);
//     std::cout << "Tree is " << (isBalanced<int>(tree) ? "" : "NOT ") << "balanced" << std::endl;

//     tree.getRoot()->getRight() = r; 
//     std::cout << "Tree is " << (isBalanced<int>(tree) ? "" : "NOT ") << "balanced" << std::endl;
//     return 0;
// }