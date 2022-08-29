#pragma once

#include "../../ALL_H_FILES.h"

// =============================================================

template<typename T>
struct WeakPtrHash // : public std::unary_function<std::weak_ptr<T>, std::size_t>
{
    typedef T argument_type;
    typedef std::size_t result_type;

    std::size_t operator()(const std::weak_ptr<T>& wp) const
    {
        auto sp = wp.lock();
        return std::hash<decltype(sp)>()(sp);
    }
};

template<typename T>
struct WeakPtrEqual // : public std::unary_function<std::weak_ptr<T>, bool>
{
    typedef T argument_type;
    typedef bool result_type;

    bool operator()(const std::weak_ptr<T>& left, const std::weak_ptr<T>& right) const
    {
        return !left.owner_before(right) && !right.owner_before(left);
    }
};

template <typename State>
class Graph
{
public:
    class Node
    {
    public:
        Node(const std::string &n) : name(n) {}
        virtual ~Node() {}

        bool isAdjacentFor(const std::shared_ptr<Node> &other) const
        {
            return childs.find(other) != childs.end();
        }

        void addChild(const std::shared_ptr<Node> &other)
        {
            childs.insert(other);
        }

        const std::unordered_set<std::weak_ptr<Node>, WeakPtrHash<Node>, WeakPtrEqual<Node>> &getAdjacent() const
        {
            return childs;
        }

        const std::string &Name() const
        {
            return name;
        }

        mutable State state;
        std::string name;

    private:
        std::unordered_set<std::weak_ptr<Node>, WeakPtrHash<Node>, WeakPtrEqual<Node>> childs;
    };

    bool matrix(std::size_t i, std::size_t j) const
    {
        if (i == j)
            return false;

        const auto &s = nodes[i];
        const auto &d = nodes[j];
        return s->isAdjacentFor(d);
    }

    std::shared_ptr<Node> &addNode(const std::string &name = std::string())
    {
        nodes.emplace_back(std::make_shared<Node>(name));
        if (!name.empty())
            namedNodes[name] = nodes.back();
        return nodes.back();
    }

    const std::shared_ptr<Node> &operator[] (std::size_t i) const
    {
        return nodes[i];
    }

    const std::shared_ptr<Node> &operator[] (const std::string &name) const
    {
        return namedNodes.at(name);
    }

    const std::deque<std::shared_ptr<Node>> &getNodes() const
    {
        return nodes;
    }

private:
    std::deque<std::shared_ptr<Node>> nodes;
    std::unordered_map<std::string, std::shared_ptr<Node>> namedNodes;
};

template <typename State>
using Node = std::shared_ptr<typename Graph<State>::Node>;