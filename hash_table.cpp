#include <iostream>

using namespace std::string_literals;

int hash(const std::string& t) {
    int hash = 0;
    for (std::string::const_iterator it = t.begin(); it != t.end(); ++it) {
        hash += *it;
    }
    std::cout << hash << std::endl;
    return hash;
}
std::vector<int> hash(const std::vector<std::string>& v){
    std::vector<int> hashes(v.size());
    for (std::vector<std::string>::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
        hashes.push_back(hash(*it));
    }
    return hashes;
}

int main() {
    std::vector a = {"hi"s, "abc"s, "aa"s, "qs"s, "pl"s};
    hash(a);
    return 0;
}