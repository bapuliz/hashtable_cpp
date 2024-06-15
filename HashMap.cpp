#include <iostream>
#include <cmath>
#include "SLL.h"

using namespace std::string_literals;

#ifndef HASHMAP_H
#define HASHMAP_H

#define HASHMAP_INITIAL_BUCKETS 8
#define HASHMAP_LOAD_FACTOR (2.0/3.0)

char generateRandomChar() {
    int randomNumber = rand() % 26;
    char randomChar = 'a' + randomNumber;
    return randomChar;
}

constexpr bool initialBucketsValid(int x){
    return x >= 2 && (x & (x - 1)) == 0;
}

constexpr bool initialLoadFactorValid(double x){
    return x > 0.0;
}

class HashMap {
        size_t n_loaded;
        double load_factor;
        std::vector<SLL> buckets;
        // HashTable() = delete;
        // HashTable(HashTable&) = delete;
        public:
        void rehash() {
            // round up to the nearest power of 2
            size_t power = floor(log2(ceil(n_loaded / load_factor)))+1;
            size_t default_power = log2(HASHMAP_INITIAL_BUCKETS);
            if (power < default_power) {
                power = default_power;
            }
            size_t new_size = pow(2, power);
            std::vector<SLL> new_buckets(new_size);
            std::cout << "Rehash. New size: " << new_buckets.size() << std::endl;
            size_t index (0);
            for (const SLL& l : buckets) {
                for (const std::pair<std::string, int> element : l) {
                    std::string key = element.first;
                    int value = element.second;
                    insert(new_buckets, key, value);
                }
            }
            buckets.swap(new_buckets);
        }
        void insert(std::vector<SLL>& table, const std::string& key, const int& value) {
            size_t buckets_size = table.size();
            size_t index = hash(key) % buckets_size;
            table[index].insertAtBeginning({key, value});
            std::cout << "Inserted -> \tKey:" << key << "\tValue:" << value << "\tIndex: " << index << "\tCurrent buckets: " << buckets_size << std::endl;
        }
        void insert(const std::string& key, const int& value)  {
            n_loaded++;
            size_t buckets_size = buckets.size();
            if ( n_loaded / load_factor >= buckets_size ) {
                rehash();
            }
            insert(buckets, key, value);
        }
        std::vector<int> hash(const std::vector<std::string>&);
        int hash(const std::string&);
        // HashTable(std::initializer_list<std::string> entries)
        // HashTable(std::vector<std::string>& entries)
        HashMap() :
                       buckets(HASHMAP_INITIAL_BUCKETS),
                       load_factor(HASHMAP_LOAD_FACTOR),
                       n_loaded(0)
                        {
                            static_assert(initialBucketsValid(HASHMAP_INITIAL_BUCKETS),
                             "HASHMAP_INITIAL_BUCKETS must be a power of 2, >=2");
                            static_assert(initialLoadFactorValid(HASHMAP_LOAD_FACTOR),
                             "HASHMAP_LOAD_FACTOR must be > 0");
                        }
        ~HashMap(){std::cout << "Destructor's called" << std::endl;};
};

#endif // HASHMAP_H

int HashMap::hash(const std::string& t) {
    constexpr long int mod = 16777619;
    constexpr const int prime = 12207031;
    unsigned long long int hash = 2166136261;
    for (std::string::const_iterator it = t.begin(); it != t.end(); ++it) {
        hash *= mod;
        hash += *it;
        hash %= prime;
    }
    return hash;
}

int main() {
    //  std::srand(std::time(0));

    // size_t size = 169;
    // std::vector<std::string> t;
    // for (int i=1; i < size+1; ++i) {
    //     t.push_back("word" + std::to_string(i) + "_" + generateRandomChar());
    // }
    HashMap h;
    h.insert("hello", 10);
    h.insert("world", 99);
    h.insert("cpppp", 50);
    h.insert("node", 100);
    h.insert("roof", 199);
    h.insert("something", 200);
    h.insert("word", 2000);
    
    // SLL s;
    // s.insertAtBeginning({"hello", 10});
    // s.insertAtBeginning({"lo", 5});
    // s.insertAtBeginning({"how", 199});
    // s.print();

    return 0;
}