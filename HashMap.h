#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <cmath>
#include "Hash.h"
#include "SLL.h"
using namespace std::string_literals;

template <typename K, typename V>
class HashMap {
        private:
            static constexpr bool initialBucketsValid(int x);
            static constexpr bool initialLoadFactorValid(double x);
            static constexpr size_t INITIAL_BUCKETS = 8;
            static constexpr double LOAD_FACTOR = (2.0/3.0);
            size_t n_loaded;
            double load_factor;
            std::vector<SLL<K,V> > buckets;
            V& rehashTable(const std::pair<K,V>& top_elem);
            V& insert(std::vector<SLL<K,V> >& table, const K& key, const V& value);
            Hash<K> hash;
        public:
            void print() const;
            bool exists(const K& key, size_t& index) const;
            void remove(const K& key);
            V& get(const K& key) const;
            V& operator[](const K& key);
            HashMap();
            ~HashMap() {};
};


#include "HashMap.tpp"
#endif // HASHMAP_H