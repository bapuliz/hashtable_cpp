#include "SLLNode.h"

SLLNode::SLLNode (const std::string& key, const int& value) : data(key, value), next(nullptr) {};
SLLNode::SLLNode (const std::pair<std::string, int>& pair) : data(pair), next(nullptr) {};