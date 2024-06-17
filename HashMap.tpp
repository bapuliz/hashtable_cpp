char generateRandomChar() {
    int randomNumber = rand() % 26;
    char randomChar = 'a' + randomNumber;
    return randomChar;
}

template<typename T, typename V>
V& HashMap<T,V>::operator[](const T& key){
    V value = 0;
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

template<typename T, typename V>
V& HashMap<T,V>::get(const T& key) const {
    size_t index = hash(key) % buckets.size();
    return buckets[index].find(key);
}

template<typename T, typename V>
void HashMap<T,V>::print() const {
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
template<typename T, typename V>
V& HashMap<T,V>::rehashTable(const std::pair<T,V>& top_elem) {
    // round up the size to the nearest power of 2
    size_t power = floor(log2(ceil(n_loaded / load_factor)))+1;
    size_t default_power = log2(INITIAL_BUCKETS);
    if (power < default_power) {
        power = default_power;
    }
    size_t new_size = pow(2, power);
    std::vector<SLL<T,V> > new_buckets(new_size);
    n_loaded = 0;
    size_t index (0);
    for (const SLL<T,V> & l : buckets) {
        for (const std::pair<T, V> element : l) {
            T key = element.first;
            V value = element.second;
            insert(new_buckets, key, value);
        }
    }
    buckets.swap(new_buckets);
    // inserting top element
    return insert(buckets, top_elem.first, top_elem.second);
}
template<typename T, typename V>
V& HashMap<T,V>::insert(std::vector<SLL<T,V> >& table, const T& key, const V& value) {
    n_loaded += 1;
    size_t buckets_size = table.size();
    size_t index = hash(key) % buckets_size;
    return table[index].insertAtBeginning({key, value});
}
// void HashMap<T,V>::insert(const T& key, const V& value)  {
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

// V& HashMap<T,V>::update(const T& key, const V& new_value) {
//     size_t index = hash(key) % buckets.size();
//     return buckets[index].update(key, new_value);
// }
template<typename T, typename V>
void HashMap<T,V>::remove(const T& key) { 
    size_t index = hash(key) % buckets.size();
    buckets[index].remove(key);
    n_loaded--;
}

template<typename T, typename V>
bool HashMap<T,V>::exists(const T& key, size_t& index) const {
    return buckets[index].exists(key);
}
template<typename T, typename V>
HashMap<T,V>::HashMap() :
                buckets(INITIAL_BUCKETS),
                load_factor(LOAD_FACTOR),
                n_loaded(0)
                {
                    static_assert(initialBucketsValid(INITIAL_BUCKETS),
                        "HASHMAP_INITIAL_BUCKETS must be a power of 2, >=2");
                    static_assert(initialLoadFactorValid(LOAD_FACTOR),
                        "HASHMAP_LOAD_FACTOR must be > 0");
                }

template<typename T, typename V>
int HashMap<T,V>::hash(const std::string& t) const {
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