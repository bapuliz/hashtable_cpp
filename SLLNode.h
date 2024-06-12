#include <string>

#ifndef SLLNODE_H
#define SLLNODE_H

class SLLNode {
    public:
        SLLNode* next;
        std::string data;
        SLLNode (const std::string& s) : data(s), next(nullptr) {};
    
};

#endif