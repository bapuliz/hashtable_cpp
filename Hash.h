#include <string>

#ifndef HASH_H
#define HASH_H

namespace hash_constants {
    constexpr unsigned long long int base_hash = 2166136261;
    constexpr long int mod = 16777619;
    constexpr int prime = 12207031;
}

template <typename K>
class Hash;

template <>
class Hash<std::string> {
    public:
        size_t operator() (const std::string& t) const {
            unsigned long long int hash = hash_constants::base_hash;
            for (const auto& c : t) {
                hash *= hash_constants::mod;
                hash += static_cast<unsigned long long int>(c);
                hash %= hash_constants::prime;
            }
            return hash;
        }
};

template <>
class Hash<int> {
    public:
        size_t operator() (const int& t) const {
            unsigned long long int hash = hash_constants::base_hash;
            hash += static_cast<unsigned long long int>(t);
            hash *= hash_constants::mod;
            hash %= hash_constants::prime;
            return hash;
        }
};


#endif // HASH_H