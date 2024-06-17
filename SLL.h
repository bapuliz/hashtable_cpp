#include <string>
#include <iostream>

#include "SLLNode.h"
#include "SLLIterator.h"

#ifndef SLL_H
#define SLL_H

template <typename T, typename V>
class SLL {
    SLLNode<T,V>* head;
    public:
        SLL () : head(nullptr) {};
        V& insertAtBeginning(const std::pair<T, V>&);
        void insertAtEnd(const std::pair<T, V>&);
        void clear();
        bool isEmpty() const;
        // V& update(const T& key, const V& new_value);
        void remove(const T& key);
        bool exists(const T& key) const;
        V& find(const T& key) const;
        void print() const;
        size_t size() const;
        SLL_Iterator<T,V> begin() const;
        SLL_Iterator<T,V> end() const;
        SLL(const SLL& other);
        ~SLL();
};
#include "SLL.tpp"
#endif // SLL_H