#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "treetestutils.cpp"

// =============================================================

template <typename T>
NodePtr<T> createMinimalBSTNode(const T* array, int start, int end)
{
    if (end < start) return nullptr;

    int offset = (start + end) / 2;
    auto node = std::make_shared<Node<T>>(array[offset]);
    node->setLeftChild(createMinimalBSTNode(array, start, offset - 1));
    node->setRightChild(createMinimalBSTNode(array, offset + 1, end));

    return node;
}

template <typename T>
NodePtr<T> createMinimalBSTNode(const T* array, size_t size)
{
    return createMinimalBSTNode(array, 0, size - 1);
}

template <typename T>
Tree<T> createMinimalBST(const T* array, size_t size)
{
    Tree<T> tree;
    tree.setRoot(createMinimalBSTNode(array, size));
    return tree;
}

// template <typename T>
// std::function<Tree<T> (const T*, size_t)> createMinimalBST = [](const T* array, size_t size) -> Tree<T>
// {
//     Tree<T> tree;
//     tree.setRoot(createMinimalBSTF(array, 0, size - 1));
//     return tree;
// };

// =============================================================

int main()
{
    std::array<int, size_t(63)> array;
    std::iota(array.begin(), array.end(), 0); 

    for (auto &i : {1, 2, 3, 6, 7, 8, 14, 15, 16, 29, 30, 31})
    {
        auto tree = createMinimalBST(&array[0], i);
        // auto tree = createMinimalBST<std::remove_reference<decltype(array)>::type>(&array, i);
        TestUtils::printTree(tree);
    }
}