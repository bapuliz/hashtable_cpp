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

int& HashMap::operator[](const std::string& key){
    int value = 0;
    size_t index = hash(key) % buckets.size();
    if ((exists(key, index))) {
        return get(key);
        // return update(key, value);
    }
    size_t buckets_size = buckets.size();
    if ((n_loaded + 1) / load_factor >= buckets_size) {
        return rehashTable({key, value});
    } else {
        return insert(buckets, key, value);
    }
}


int& HashMap::get(const std::string& key) const {
    size_t index = hash(key) % buckets.size();
    return buckets[index].find(key);
}

void HashMap::print() const {
    size_t index (0);
    std::cout
        << std::endl
        << "SIZE: " << buckets.size()
        << "\t\tLOADED: " << n_loaded
        << std::endl << std::endl;
    for (const auto& bucket : buckets) {
        if (!bucket.isEmpty()) {
            std::cout 
                << "Bucket: " << index
                << "\tSize: " << bucket.size()
                << std::endl;
            for (const auto& node : bucket) {
                std::cout
                    << "KEY: " << node.first
                    << "\tVALUE: " << node.second
                    << std::endl;
            }
            std::cout << std::endl;
        }
        index++;
    }
    
}
int& HashMap::rehashTable(const std::pair<std::string,int>& top_elem) {
    // round up the size to the nearest power of 2
    size_t power = floor(log2(ceil(n_loaded / load_factor)))+1;
    size_t default_power = log2(INITIAL_BUCKETS);
    if (power < default_power) {
        power = default_power;
    }
    size_t new_size = pow(2, power);
    std::vector<SLL> new_buckets(new_size);
    n_loaded = 0;
    size_t index (0);
    for (const SLL& l : buckets) {
        for (const std::pair<std::string, int> element : l) {
            std::string key = element.first;
            int value = element.second;
            insert(new_buckets, key, value);
        }
    }
    buckets.swap(new_buckets);
    // inserting top element
    return insert(buckets, top_elem.first, top_elem.second);
}
int& HashMap::insert(std::vector<SLL>& table, const std::string& key, const int& value) {
    n_loaded += 1;
    size_t buckets_size = table.size();
    size_t index = hash(key) % buckets_size;
    return table[index].insertAtBeginning({key, value});
}
// void HashMap::insert(const std::string& key, const int& value)  {
//     size_t index = hash(key) % buckets.size();
//     if ((exists(key, index))) {
//         update(key, value);
//         return;
//     }
//     size_t buckets_size = buckets.size();
//     if ((n_loaded + 1) / load_factor >= buckets_size) {
//         rehashTable({key, value});
//     } else {
//         insert(buckets, key, value);
//     }
// }

// int& HashMap::update(const std::string& key, const int& new_value) {
//     size_t index = hash(key) % buckets.size();
//     return buckets[index].update(key, new_value);
// }
void HashMap::remove(const std::string& key) { 
    size_t index = hash(key) % buckets.size();
    buckets[index].remove(key);
    n_loaded--;
}

bool HashMap::exists(const std::string& key, size_t& index) const {
    return buckets[index].exists(key);
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