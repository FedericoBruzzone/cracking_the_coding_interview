#pragma once

#include "../../../ALL_H_FILES.h"

template <typename T>
class BSTNode
{
private:
    T value;
    BSTNode *left, *right;

public:
    BSTNode(T value);
    ~BSTNode();
    
    void add(T& value);
    bool contains(T& value);

    friend class BSTHashtable;
};

class BSTHashtable
{
    private:
        int size;
        std::vector<BSTNode<std::string>*>* bucket;
        int hash(std::string& s);

    public:
        BSTHashtable(int vectorSize);
        
        void add(std::string& s);
        
        bool contains(std::string& s);
        
        void display();
        
        void display_bst(BSTNode<std::string> *node);
};