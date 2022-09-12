#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "treenodeiterator.cpp"
#include "treetestutils.cpp"

// =============================================================

// First implementation
template <typename T>
int countPathsWithSum(const NodePtr<T> root, int targetSum);

template <typename T>
int countPathWithSumFromNode(const NodePtr<T> node, int targetSum, int currentSum);

template <typename T>
int countPathsWithSum(const Tree<T> tree, int targetSum)
{
    return countPathsWithSum<T>(tree.getRoot(), targetSum);
}

template <typename T>
int countPathsWithSum(const NodePtr<T> root, int targetSum)
{
    if (!root) { return 0; }

    int pathsFromRoot = countPathWithSumFromNode<T>(root, targetSum, 0);

    int pathsOnLeft = countPathsWithSum<T>(root->getLeft(), targetSum);
    int pathsOnRight = countPathsWithSum<T>(root->getRight(), targetSum);
    
    return pathsFromRoot + pathsOnLeft + pathsOnRight;
}

template <typename T>
int countPathWithSumFromNode(const NodePtr<T> node, int targetSum, int currentSum)
{
    if (!node) { return 0; }
    
    int totalPaths = 0;
    currentSum += node->getValue();
    if (currentSum == targetSum) { ++totalPaths; }

    totalPaths += countPathWithSumFromNode<T>(node->getLeft(), targetSum, currentSum);
    totalPaths += countPathWithSumFromNode<T>(node->getRight(), targetSum, currentSum);
    return totalPaths;
}

// =============================================================

// First implementation
// int main()
// {
//     auto tree = TestUtils::treeFromArray({1, -2, 3, -5, 7, -11, 13, -1, 2, -3, 5, -7, 11, -1, 2, -3, 1, -2, 3, -7});
//     TestUtils::printTree(tree);

//     for (int i = -42; i <= 48; ++i) 
//     {  
//         std::cout << "Sum " << i << " can be reached in " << countPathsWithSum(tree, i) << " paths\n";
//     } 
// }