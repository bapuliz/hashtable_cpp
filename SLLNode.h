#include <string>

#ifndef SLLNODE_H
#define SLLNODE_H

template <typename T, typename V>
class SLLNode {
    public:
        SLLNode* next;
        std::pair<T, V> data;
        SLLNode (const T& key, const V& value);
        SLLNode (const std::pair<T, V>& pair);
};

#include "SLLNode.tpp"
#endif // SLLNODE_H