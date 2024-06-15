#include "HashMap.h"

char generateRandomChar() {
    int randomNumber = rand() % 26;
    char randomChar = 'a' + randomNumber;
    return randomChar;
}

constexpr bool HashMap::initialBucketsValid(int x){
    return x >= 2 && (x & (x - 1)) == 0;
}

constexpr bool HashMap::initialLoadFactorValid(double x){
    return x > 0.0;
}

int HashMap::get(const std::string& key) const {
    size_t index = hash(key) % buckets.size();
    
}

void HashMap::rehash() {
    // round up the size to the nearest power of 2
    size_t power = floor(log2(ceil(n_loaded / load_factor)))+1;
    size_t default_power = log2(INITIAL_BUCKETS);
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
void HashMap::insert(std::vector<SLL>& table, const std::string& key, const int& value) {
    size_t buckets_size = table.size();
    size_t index = hash(key) % buckets_size;
    table[index].insertAtBeginning({key, value});
    std::cout << "Inserted -> \tKey:" << key << "\tValue:" << value << "\tIndex: " << index << "\tCurrent buckets: " << buckets_size << std::endl;
}
void HashMap::insert(const std::string& key, const int& value)  {
    n_loaded++;
    size_t buckets_size = buckets.size();
    if ( n_loaded / load_factor >= buckets_size ) {
        rehash();
    }
    insert(buckets, key, value);
}
HashMap::HashMap() :
                buckets(INITIAL_BUCKETS),
                load_factor(LOAD_FACTOR),
                n_loaded(0)
                {
                    static_assert(initialBucketsValid(INITIAL_BUCKETS),
                        "HASHMAP_INITIAL_BUCKETS must be a power of 2, >=2");
                    static_assert(initialLoadFactorValid(LOAD_FACTOR),
                        "HASHMAP_LOAD_FACTOR must be > 0");
                }

int HashMap::hash(const std::string& t) const {
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