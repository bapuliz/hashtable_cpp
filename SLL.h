#include <string>
#include <iostream>

#include "SLLNode.h"

#ifndef SLL_H
#define SLL_H

class SLL {
    SLLNode* head;
    public:
        SLL () : head(nullptr) {};
        void insertAtBeginning(const std::string&);
        void insertAtEnd(const std::string&);
        void clear();
        void print() const;
        ~SLL();
};

#endif // SLL_H