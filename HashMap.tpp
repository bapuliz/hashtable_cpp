template <typename K, typename V>
constexpr bool HashMap<K,V>::initialBucketsValid(int x){
    return x >= 2 && (x & (x - 1)) == 0;
}
template <typename K, typename V>
constexpr bool HashMap<K,V>::initialLoadFactorValid(double x){
    return x > 0.0;
}
template<typename K, typename V>
V& HashMap<K,V>::operator[](const K& key){
    V value = 0;
    size_t index = hash(key) % buckets.size();
    if ((exists(key, index))) {
        return get(key);
    }
    size_t buckets_size = buckets.size();
    if ((n_loaded + 1) / load_factor >= buckets_size) {
        return rehashTable({key, value});
    } else {
        return insert(buckets, key, value);
    }
}
template<typename K, typename V>
V& HashMap<K,V>::get(const K& key) const {
    size_t index = hash(key) % buckets.size();
    return buckets[index].find(key);
}
template<typename K, typename V>
void HashMap<K,V>::print() const {
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
template<typename K, typename V>
V& HashMap<K,V>::rehashTable(const std::pair<K,V>& top_elem) {
    // round up the size to the nearest power of 2
    size_t power = floor(log2(ceil(n_loaded / load_factor)))+1;
    size_t default_power = log2(INITIAL_BUCKETS);
    if (power < default_power) {
        // buckets size cannot shrink back to avoid resizing
        power = default_power;
    }
    size_t new_size = pow(2, power);
    std::vector<SLL<K,V> > new_buckets(new_size);
    n_loaded = 0;
    size_t index (0);
    for (const SLL<K,V> & l : buckets) {
        for (const std::pair<K, V> element : l) {
            K key = element.first;
            V value = element.second;
            insert(new_buckets, key, value);
        }
    }
    buckets.swap(new_buckets);
    // inserting top element
    return insert(buckets, top_elem.first, top_elem.second);
}
template<typename K, typename V>
V& HashMap<K,V>::insert(std::vector<SLL<K,V> >& table, const K& key, const V& value) {
    n_loaded += 1;
    size_t buckets_size = table.size();
    size_t index = hash(key) % buckets_size;
    return table[index].insertAtBeginning({key, value});
}
template<typename K, typename V>
void HashMap<K,V>::remove(const K& key) { 
    size_t index = hash(key) % buckets.size();
    buckets[index].remove(key);
    n_loaded--;
}
template<typename K, typename V>
bool HashMap<K,V>::exists(const K& key, size_t& index) const {
    return buckets[index].exists(key);
}
template<typename K, typename V>
HashMap<K,V>::HashMap() :
                buckets(INITIAL_BUCKETS),
                load_factor(LOAD_FACTOR),
                n_loaded(0)
                {
                    static_assert(initialBucketsValid(INITIAL_BUCKETS),
                        "HASHMAP_INITIAL_BUCKETS must be a power of 2, >=2");
                    static_assert(initialLoadFactorValid(LOAD_FACTOR),
                        "HASHMAP_LOAD_FACTOR must be > 0");
                }

template<>
int HashMap<std::string, int>::hash(const std::string& t) const {
    unsigned long long int hash = base_hash;
    for (std::string::const_iterator it = t.begin(); it != t.end(); ++it) {
        hash *= mod;
        hash += *it;
        hash %= prime;
    }
    return hash;
}
// template<K,V>
// int HashMap<int, V>::hash(const int& t) const {
//     return t;
// }