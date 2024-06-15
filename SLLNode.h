#include <string>

#ifndef SLLNODE_H
#define SLLNODE_H

class SLLNode {
    public:
        SLLNode* next;
        std::pair<std::string, int> data;
        SLLNode (const std::string& key, const int& value);
        SLLNode (const std::pair<std::string, int>& pair);
};

#endif // SLLNODE_H