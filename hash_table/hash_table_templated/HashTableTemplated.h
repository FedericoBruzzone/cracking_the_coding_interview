#pragma once

#include <iostream>
#include <vector>

template<class K, class V>
struct Bucket {
  K key;
  V val;
  Bucket(const K &k, const V &v) : val(v), key(k) {}
};

template<class T> struct myHash {};

template<> struct myHash<std::string> {
  static size_t hashFunction(const std::string& s) {
    return std::hash<std::string>()(s);
  }
};

template<> struct myHash<int> {
  static size_t hashFunction(const int m) {
    return std::hash<int>()(m);
  }
};

template<class K, class V, class HashGenerator = myHash<K> >
class HashTable 
{
public:
  std::vector<std::vector<Bucket<K, V> > > table;

  HashTable(int size);
  ~HashTable();

  void set(const K &k, const V &v);

  V get(const K &k);

  bool exist(const K &k);

  size_t hash(const K &k);
};