#include <string>
#include <iostream>

#include "SLLNode.h"
#include "SLLIterator.h"

#ifndef SLL_H
#define SLL_H

template <typename K, typename V>
class SLL {
    SLLNode<K,V>* head;
    public:
        SLL () : head(nullptr) {};
        V& insertAtBeginning(const std::pair<K, V>&);
        void insertAtEnd(const std::pair<K, V>&);
        void clear();
        bool isEmpty() const;
        // V& update(const K& key, const V& new_value);
        void remove(const K& key);
        bool exists(const K& key) const;
        V& find(const K& key) const;
        void print() const;
        size_t size() const;
        SLL_Iterator<K,V> begin() const;
        SLL_Iterator<K,V> end() const;
        SLL(const SLL& other);
        ~SLL();
};
#include "SLL.tpp"
#endif // SLL_H