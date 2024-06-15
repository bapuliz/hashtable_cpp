#include <string>

#ifndef SLLNODE_H
#define SLLNODE_H

class SLLNode {
    public:
        SLLNode* next;
        std::pair<std::string, int> data;
        SLLNode (const std::string& k, const int& v) : data(k, v), next(nullptr) {};
};

#endif // SLLNODE_H