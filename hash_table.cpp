#include <iostream>
#include <cmath>

using namespace std::string_literals;

#define HASHTABLE_BUCKET_SIZE 8
#define HASHTABLE_LOAD_FACTOR (2.0/3.0)

class HashTable {
    private:
        size_t n_buckets;
        double load_factor;
        HashTable() = delete;
        HashTable(HashTable&) = delete;
    public:
        std::vector<int> HashTable::hash(const std::vector<std::string>&);
        int HashTable::hash(const std::string&);
        // HashTable(std::initializer_list<std::string> entries)
        HashTable(std::vector<std::string>& entries)
                     : n_buckets(HASHTABLE_BUCKET_SIZE),
                       load_factor(HASHTABLE_LOAD_FACTOR)
                {
                    if (size(entries) >= static_cast<size_t>(load_factor * n_buckets)) {
                        // To find the power of HASHTABLE_GROWTH_FACTOR:
                        // ceil(2^x * HASHTABLE_BUCKET_SIZE * HASHTABLE_LOAD_FACTOR) > size(entries)
                        // simplified:
                        // size_t power = ceil((log2(size(entries) / (n_buckets) * (load_factor))));
                        // n_buckets *= pow(2, power);
                    }
                }

};
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
    std::vector<std::string> t(170, "hello");
    // HashTable h ({"hi"s, "abc"s, "aa"s, "qs"s, "pl"s});
    // HashTable h(t);

    return 0;
}