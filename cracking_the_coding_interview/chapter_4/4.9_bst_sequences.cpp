#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "treetestutils.cpp"
#include "treenodeiterator.cpp"

// =============================================================
template <typename T>
std::list<std::deque<T>> weaveLists(std::deque<T> &prefix, std::deque<T> &left, std::deque<T> &right);

template <typename T>
std::list<std::deque<T>> allSequences(const NodePtr<T> &root)
{
    std::list<std::deque<T>> result;

    if (!root)
    {
        result.emplace_back(); 
        return result;
    }

    auto leftArrays = allSequences<T>(root->getLeft());
    auto rightArrays = allSequences<T>(root->getRight());

    std::deque<T> prefix;
    prefix.push_back(root->getValue());
    for (auto &left : leftArrays)
        for (auto &right : rightArrays)
        {
            auto joins = weaveLists<T>(prefix, left, right);
            result.splice(result.end(), std::move(joins));
            assert(prefix.size() == 1 && prefix[0] == root->getValue());
        }
    return result;
}

template <typename T>
std::list<std::deque<T>> weaveLists(std::deque<T> &prefix, std::deque<T> &left, std::deque<T> &right)
{
    std::list<std::deque<T>> result;

    if (left.empty() || right.empty())
    {
        std::deque<T> r(prefix);
        r.insert(r.end(), left.begin(), left.end());
        r.insert(r.end(), right.begin(), right.end());
        result.push_back(std::move(r));
        return result;
    }

    prefix.push_back(left.front());
    left.pop_front();
    result.splice(result.end(), weaveLists(prefix, left, right));
    left.push_front(prefix.back());
    prefix.pop_back();

    prefix.push_back(right.front());
    right.pop_front();
    result.splice(result.end(), weaveLists(prefix, left, right));
    right.push_front(prefix.back());
    prefix.pop_back();

    return result;
}
// =============================================================

// int main()
// {
//     auto tree = TestUtils::treeFromArray({5, 10, 15, 20, 25, 50, 60, 65, 70, 80});
//     TestUtils::printTree(tree);
//     // auto tree = TestUtils::treeFromArray({2, 3, 1});
//     auto result = allSequences<int>(tree.getRoot());

//     for (auto &array : result)
//     {
//         std::string sep;
//         std::cout << "{";
//         for (auto &n : array)
//         {
//             std::cout << sep << n;
//             if (sep.empty())
//                 sep = ", ";
//         }
//         std::cout << "}" << std::endl;
//     }
// }