#include <iostream>
#include <cmath>
#include "SLL.h"

using namespace std::string_literals;

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HASHTABLE_INITIAL_BUCKETS 8
#define HASHTABLE_LOAD_FACTOR (2.0/3.0)

char generateRandomChar() {
    int randomNumber = rand() % 26;
    char randomChar = 'a' + randomNumber;
    return randomChar;
}

class HashTable {
    private:
        size_t n_buckets;
        double load_factor;
        std::vector<SLL> buckets;
        HashTable() = delete;
        HashTable(HashTable&) = delete;
        bool resize(const size_t& entries_size) {
            bool resized = false;
            size_t target_bucket_count = ceil(entries_size / load_factor);
            if (target_bucket_count >= n_buckets) {
                size_t power = floor(log2(target_bucket_count) + 1);
                n_buckets = pow(2, power);
                resized = true;
            }
            return resized;
        }
        void populateBuckets(std::vector<std::string>& entries) {
            std::cout << "n_buckets:" << n_buckets << std::endl;
            size_t max_bucket_size = 0;
            for (const std::string& entry : entries) {
                size_t index = hash(entry) % n_buckets;
                buckets[index].insertAtBeginning(entry);
                size_t bucket_size = buckets[index].size();
                if (bucket_size > max_bucket_size) {
                    max_bucket_size = bucket_size;
                }
            }
            size_t collisions = max_bucket_size - 1;
            double collisions_ratio_p = ((collisions+0.0) / n_buckets) * 100;
            std::cout << "max_bucket_size: " << max_bucket_size << std::endl;
            std::cout << "collisions: " << collisions << std::endl;
            std::cout << "collisions_ratio_p: " << collisions_ratio_p << "%" << std::endl;
        }
        void insert(const std::string const * entry)  {

        }

    
    public:
        std::vector<int> hash(const std::vector<std::string>&);
        int hash(const std::string&);
        // HashTable(std::initializer_list<std::string> entries)
        HashTable(std::vector<std::string>& entries)
                     : n_buckets(HASHTABLE_INITIAL_BUCKETS),
                       load_factor(HASHTABLE_LOAD_FACTOR),
                       buckets(n_buckets)
                {
                    if (resize(size(entries)) == true) {
                        std::cout << "Buckets resized. " << std::endl;
                        buckets.resize(n_buckets);
                    }
                    populateBuckets(entries);
                }

};

#endif // HASHTABLE_H

int HashTable::hash(const std::string& t) {
    long int mod = 16777619;
    unsigned long long int hash = 2166136261;
    const int prime = 12207031;
    for (std::string::const_iterator it = t.begin(); it != t.end(); ++it) {
        hash *= mod;
        hash += *it;
        hash %= prime;
    }
    return hash;
}
// std::vector<int> HashTable::hash(const std::vector<std::string>& v){
//     std::vector<int> hashes(v.size());
//     for (std::vector<std::string>::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
//         hashes.push_back(hash(*it));
//     }
//     return hashes;
// }

int main() {
     std::srand(std::time(0));

    size_t size = 171;
    std::vector<std::string> t;
    for (int i=1; i < size+1; ++i) {
        t.push_back("word" + std::to_string(i) + "_" + generateRandomChar());
    }
    HashTable h(t);
    


    return 0;
}