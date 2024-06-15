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
        void insertAtBeginning(const std::pair<std::string, int>&);
        void insertAtEnd(const std::pair<std::string, int>&);
        void clear();
        void print() const;
        size_t size() const;
        SLL_Iterator begin() const {
            return SLL_Iterator(head);
        }
        SLL_Iterator end() const {
            return SLL_Iterator(nullptr);
        }
        SLL(const SLL& other);
        ~SLL();
};


#endif // SLL_H