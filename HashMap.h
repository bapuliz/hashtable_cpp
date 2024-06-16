#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <cmath>
#include "SLL.h"
using namespace std::string_literals;

class HashMap {
        static constexpr size_t INITIAL_BUCKETS = 8;
        static constexpr double LOAD_FACTOR = (2.0/3.0);
        size_t n_loaded;
        double load_factor;
        std::vector<SLL> buckets;
        public:
            static constexpr bool initialBucketsValid(int x);
            static constexpr bool initialLoadFactorValid(double x);
            void print() const;
            void rehashTable(const std::pair<std::string,int>& top_elem);
            bool exists(const std::string& key, size_t& index) const;
            void remove(const std::string& key);
            void update(const std::string& key, const int& new_value);
            int get(const std::string& key) const;
            void insert(std::vector<SLL>& table, const std::string& key, const int& value);
            void insert(const std::string& key, const int& value);
            int hash(const std::string&) const;
            HashMap();
            ~HashMap() {};
};
#endif // HASHMAP_H