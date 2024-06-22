#include <string>

#ifndef SLLNODE_H
#define SLLNODE_H

template <typename K, typename V>
class SLLNode {
    public:
        SLLNode* next;
        std::pair<K, V> data;
        SLLNode (const K& key, const V& value);
        SLLNode (const std::pair<K, V>& pair);
};

#include "SLLNode.tpp"
#endif // SLLNODE_H