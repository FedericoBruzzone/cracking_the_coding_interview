#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "treetestutils.cpp"
#include "treenodeiterator.cpp"

// =============================================================

template <typename T>
std::list<std::deque<T>> allSequences(const NodePtr<T> &root)
{
    std::list<std::deque<T>> result;
}

template <typename T>
std::list<std::deque<T>> weaveLists(std::deque<T> &prefix, std::deque<T> &left, std::deque<T> &)
{
    std::list<std::deque<T>> result;

    if (left.empty() || right.empty())
    {
        std::deque<T> r(prefix);
        r.insert(r.end, left.begin(), left.end());
        r.insert(r.end, right.begin(), right.end());
        result.pop_back(r);
        return result;
    }

    prefix.push_back(left.front());

    
}
// =============================================================

int main()
{
    auto tree = TestUtils::treeFromArray({5, 10, 15, 20, 25, 50, 60, 65, 70, 80});
    TestUtils::printTree(tree);
    // auto tree = TestUtils::treeFromArray({2, 3, 1});
    auto result = allSequences<int>(tree.getRoot());
}