#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <cmath>
#include "SLL.h"
using namespace std::string_literals;

template <typename T, typename V>
class HashMap {
        static constexpr size_t INITIAL_BUCKETS = 8;
        static constexpr double LOAD_FACTOR = (2.0/3.0);
        size_t n_loaded;
        double load_factor;
        std::vector<SLL<T,V> > buckets;
        public:
            static constexpr bool initialBucketsValid(int x){
                return x >= 2 && (x & (x - 1)) == 0;
            }
            static constexpr bool initialLoadFactorValid(double x){
                return x > 0.0;
            }
            void print() const;
            V& rehashTable(const std::pair<T,V>& top_elem);
            bool exists(const T& key, size_t& index) const;
            void remove(const T& key);
            // V& update(const T& key, const V& new_value);
            V& insert(std::vector<SLL<T,V> >& table, const T& key, const V& value);
            // void insert(const T& key, const V& value);
            V& get(const T& key) const;
            V& operator[](const T& key);
            int hash(const std::string&) const;
            HashMap();
            ~HashMap() {};
};

#include "HashMap.tpp"
#endif // HASHMAP_H