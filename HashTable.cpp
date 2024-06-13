#include <iostream>
#include <cmath>
#include "SLL.h"

using namespace std::string_literals;

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HASHTABLE_BUCKET_SIZE 256
#define HASHTABLE_LOAD_FACTOR (2.0/3.0)

class HashTable {
    private:
        size_t n_buckets;
        double load_factor;
        std::vector<SLL> buckets;
        HashTable() = delete;
        HashTable(HashTable&) = delete;
        bool resize(const size_t& entries_size) {
            bool resized = false;
            if (ceil(entries_size / load_factor) > n_buckets) {
                size_t power = ceil(
                                    log2(
                                        (entries_size / (load_factor + n_buckets)) 
                                        )
                                );
                if (floor(n_buckets * pow(2, power) * load_factor) <= entries_size) {
                    power++;
                }
                size_t c_buckets = n_buckets;
                n_buckets = n_buckets * pow(2, power);
                resized = true;
            }
            return resized;
        }
        void rehash() {

        }
    

    public:
        std::vector<int> hash(const std::vector<std::string>&);
        int hash(const std::string&);
        // HashTable(std::initializer_list<std::string> entries)
        HashTable(std::vector<std::string>& entries)
                     : n_buckets(HASHTABLE_BUCKET_SIZE),
                       load_factor(HASHTABLE_LOAD_FACTOR),
                       buckets(n_buckets)
                {
                    resize(size(entries));
                }

};

#endif // HASHTABLE_H

int HashTable::hash(const std::string& t) {
    int hash = 0;
    for (std::string::const_iterator it = t.begin(); it != t.end(); ++it) {
        hash += *it;
    }
    std::cout << hash << std::endl;
    return hash;
}
std::vector<int> HashTable::hash(const std::vector<std::string>& v){
    std::vector<int> hashes(v.size());
    for (std::vector<std::string>::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
        hashes.push_back(hash(*it));
    }
    return hashes;
}

int main() {

    std::vector<std::string> t(171, "hello");
    HashTable h(t);
    // HashTable h ({"hi"s, "abc"s, "aa"s, "qs"s, "pl"s});
    


    return 0;
}