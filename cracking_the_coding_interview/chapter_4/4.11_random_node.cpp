#include "../../ALL_H_FILES.h"

#include "tree.cpp"
#include "treetestutils.cpp"

// =============================================================

// // First implementation
template <typename T>
class Tree
{
public:
    class RandomNode;
    using NodePtr = std::shared_ptr<RandomNode>;

    class RandomNode
    {
    public:
        template <typename U>
        explicit RandomNode(U &&value) : v(std::forward<U>(value)) {}

        const NodePtr &left() const { return childs[0]; }
        const NodePtr &right() const { return childs[1]; }
        const T &value() const {return v;}

    private:
        std::array<NodePtr, 2> childs;
        T v;
        size_t idx;
        friend class Tree;
    };

    Tree() 
    {
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        randomEngine = std::default_random_engine(seed);
    }

    template <typename U>
    const NodePtr insert(const NodePtr &parent, U &&value, bool insertRight) 
    {
        NodePtr newNode;

        if (!parent) 
        {
            rootNode = newNode = std::make_shared<RandomNode>(std::forward<U>(value));
        }
        else
        {
            parent->childs[insertRight ? 1 : 0] = newNode = std::make_shared<RandomNode>(std::forward<U>(value));
        }
        
        newNode->idx = nodes.size();
        nodes.push_back(newNode);
        return newNode;
    }

    const NodePtr getRandomNode() const
    {
        if (nodes.size() == 0) { return nullptr; }
        if (nodes.size() == 1) { return rootNode; }
        if (randomDistribution.max() != nodes.size() - 1)
        {
            randomDistribution = std::uniform_int_distribution<size_t>(0, nodes.size() - 1);
        }
        return nodes.at(randomDistribution(randomEngine));
    }   

    const NodePtr &root() const
    {
        return this->rootNode;
    }
    
private:
    NodePtr rootNode;
    std::deque<NodePtr> nodes;
    mutable std::default_random_engine randomEngine;
    mutable std::uniform_int_distribution<size_t> randomDistribution;
};

// Second implementation
template <typename T, bool>
class RandomNode;

template <typename T, bool NotUsed = false>
class RandomNode
{
public:
    using NodePtr = std::shared_ptr<RandomNode<T>>;

    RandomNode(const T &v): size(1)
    {
        value = v;
    }

    const NodePtr &getLeft() const
    {
        return childs[0];
    }

    const NodePtr &getRight() const
    {
        return childs[1];
    }

    const T &getValue() const
    {
        return value;
    }

private:
    void add(const T &v)
    {
        if (!childs[v > value])
            childs[v > value] = std::make_shared<RandomNode<T>>(v);
        else
            childs[v > value]->add(v);
        ++size;
    }

    const T &getRandom() const
    {
        return get(std::rand() % size + 1);
    }

    const T &get(size_t n) const
    {
        if (n == size)
            return value;
        else if (childs[0] && n <= childs[0]->size)
            return childs[0]->get(n);
        else
            return childs[1]->get(n - (childs[0] ? childs[0]->size : 0));
    }

    T value;
    size_t size;
    std::array<NodePtr, 2> childs;

    template <typename U>
    friend class RandomTree;
};

template <typename T>
class RandomTree : public Tree<T, false, RandomNode>
{
    using Base = Tree<T, false, RandomNode>;

public:
    const T &getRandom() const
    {
        if (!Base::root)
            throw typename Base::TreeIsEmptyException();
        return Base::root->getRandom();
    }

    void add(const T &value)
    {
        if (Base::root)
            Base::root->add(value);
        else
            Base::root = std::make_shared<RandomNode<T, false>>(value);
    }
};

// =============================================================

// First implementation
// int main()
// {
//     Tree<int> tree;
//     auto node = tree.insert(nullptr, 3, false); //      3
//     auto left = tree.insert(node, 1, false);    //    /   \       .
//     tree.insert(left, 0, false);                //   1     5
//     tree.insert(left, 2, true);                 //  / \   / \     .
//     auto right = tree.insert(node, 5, true);    // 0   2 4   6
//     tree.insert(right, 4, false);
//     tree.insert(right, 6, true);

//     std::string coma;
//     for (int i = 0; i < 100; ++i)
//     {
//         std::cout << coma << tree.getRandomNode()->value();
//         if (coma.empty())
//             coma = ", ";
//     }
//     std::cout << std::endl;
// }

// Second implementation
// int main()
// {
//     std::srand (unsigned(std::time(0)));
//     std::vector<int> v(7) ;
//     std::iota(std::begin(v), std::end(v), 0); // Fill with 0, 1, ..., nodeCount - 1.
//     std::random_shuffle(std::begin(v), std::end(v), [](int i){return std::rand() % i;});

//     RandomTree<int> tree;
//     tree.add(v.back());
//     v.pop_back();
//     for (auto i : v)
//         tree.add(i);

//     TestUtils::printTree(tree);
//     std::cout << std::endl;

//     // Check distribution of rundom tree nodes
//     v = std::vector<int>(v.size() + 1, 0);
//     for (auto i = 0U; i < v.size() * 1000; ++i)
//         ++v[tree.getRandom()];

//     size_t cnt = std::accumulate(v.begin(), v.end(), 0);
//     std::cout << "Total: " << cnt << " times\n";
//     std::cout << std::fixed << std::setprecision(2);
//     for (auto i = 0U; i < v.size(); ++i)
//         std::cout << i << ": " << 100.0 * v[i] / cnt << "%\n";
// }