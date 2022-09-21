#include "HashTableBinaryTree.h"

template <typename T>
BSTNode<T>::BSTNode(T value)
{
    this->value = value;
    left = NULL;
    right = NULL;
}

template <typename T>
BSTNode<T>::~BSTNode() {}

template <typename T>
void BSTNode<T>::add(T& value)
{
    if (value < this->value)
    {
        if (left)
            left->add(value);
        else
            left = new BSTNode(value);
    }

    if (value > this->value)
    {
        if (right)
            right->add(value);
        else
            right = new BSTNode(value);
    }
}

template <typename T>
bool BSTNode<T>::contains(T& value)
{
    if (value < this->value)
    {
        if (left)
            return left->contains(value);
        else    
            return false;
    }
    else if (value > this->value)
    {
        if (right)
            return right->contains(value);
        else    
            return false;
    }
    else
    {
        return true;
    }
}

int BSTHashtable::hash(std::string& s)
{
    unsigned int hashVal = 0;
    for (unsigned int i = 0; i < s.length(); i++)
        hashVal ^= (hashVal << 5) + (hashVal >> 2) + s[i];
    return hashVal % size;
}

BSTHashtable::BSTHashtable(int vectorSize)
{
    size = vectorSize;
    bucket = new std::vector<BSTNode<std::string>*>(size);
}

void BSTHashtable::add(std::string& s)
{
    int index = hash(s);
    if (bucket->at(index) == NULL)
        bucket->at(index) = new BSTNode<std::string>(s);
    else
        bucket->at(index)->add(s);
}

bool BSTHashtable::contains(std::string& s)
{
    int index = hash(s);
    if (bucket->at(index) == NULL)
        return false;
    std::cout<<"String \""<<s<<"\" found at index: "<<index<<std::endl;
    return bucket->at(index)->contains(s);
}

void BSTHashtable::display()
{
    for (unsigned int i = 0; i < bucket->size(); i++)
    {
        std::cout <<"[" << i << "] ";
        if (bucket->at(i) != NULL)
        {
            BSTNode<std::string> *node = bucket->at(i);
            display_bst(node);
        }
        std::cout << std::endl;
    }
}

void BSTHashtable::display_bst(BSTNode<std::string> *node)
{
    if (node!=NULL)
    {
        display_bst(node->left);
        std::cout << node->value << " ";
        display_bst(node->right);
    }
}