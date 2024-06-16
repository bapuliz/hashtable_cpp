#include <string>
#include <iostream>

#include "SLLNode.h"
#include "SLLIterator.h"

#ifndef SLL_H
#define SLL_H

class SLL {
    SLLNode* head;
    public:
        SLL () : head(nullptr) {};
        int& insertAtBeginning(const std::pair<std::string, int>&);
        void insertAtEnd(const std::pair<std::string, int>&);
        void clear();
        bool isEmpty() const;
        int& update(const std::string& key, const int& new_value);
        void remove(const std::string& key);
        bool exists(const std::string& key) const;
        int find(const std::string& key) const;
        void print() const;
        size_t size() const;
        SLL_Iterator begin() const;
        SLL_Iterator end() const;
        SLL(const SLL& other);
        ~SLL();
};


#endif // SLL_H