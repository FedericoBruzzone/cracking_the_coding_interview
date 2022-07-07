#include "hash_table_templated.h"

template<class K, class V, class HashGenerator>
HashTable<K, V, HashGenerator>::HashTable(int size)
{
    for(int i = 0; i < size; i++) 
    {
        std::vector<Bucket<K, V> > v;
        table.push_back(v);
    } 
}

template<class K, class V, class HashGenerator>
HashTable<K, V, HashGenerator>::~HashTable() {}

template<class K, class V, class HashGenerator>
void HashTable<K, V, HashGenerator>::set(const K &k, const V &v) 
{
    Bucket<K, V> b(k, v);
    for(int i = 0; i < table[hash(k)].size(); i++)
      if(table[hash(k)][i].key == k) {
        table[hash(k)][i] = b;
        return;
      }
    table[hash(k)].push_back(b);
}

template<class K, class V, class HashGenerator>
V HashTable<K, V, HashGenerator>::get(const K &k) 
{
    for(int i = 0; i < table[hash(k)].size(); i++)
        if(table[hash(k)][i].key == k)
            return table[hash(k)][i].val;
}

template<class K, class V, class HashGenerator>
bool HashTable<K, V, HashGenerator>::exist(const K &k) 
{
    for(int i = 0; i < table[hash(k)].size(); i++)
        if(table[hash(k)][i].key == k)
            return true;
    return false;
}

template<class K, class V, class HashGenerator>
size_t HashTable<K, V, HashGenerator>::hash(const K &k) 
{
    return HashGenerator::hashFunction(k) % table.size();
}