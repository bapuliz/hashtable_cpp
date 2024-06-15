#include "SLL.h"

void SLL::insertAtBeginning(const std::pair<std::string, int>& pair) {
    SLLNode* newNode = new SLLNode(pair.first, pair.second);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void SLL::insertAtEnd(const std::pair<std::string, int>& pair) {
    SLLNode* newNode = new SLLNode(pair.first, pair.second);
    if (head == nullptr) {
        head = newNode;
    } else {
        SLLNode* t_head = head;
        while (t_head->next != nullptr) {
            t_head = t_head->next;
        }
        t_head->next = newNode;
    }
}
void SLL::clear(){
    while (head != nullptr) {
        SLLNode* head_next = head->next;
        delete head;
        head = head_next;
    }
}
void SLL::print() const{
    SLLNode* t_head = head;
    while (t_head != nullptr) {
        std::cout << "Key: " << t_head->data.first << "Value: " << t_head->data.second << std::endl;
        t_head = t_head->next;
    }
}
size_t SLL::size() const {
    size_t size = 0;
    const SLLNode* t_head = head;
    while (t_head != nullptr) {
        ++size;
        t_head = t_head->next;
    }

    return size;
}
SLL::SLL(const SLL& other) {
    SLLNode* t_head_other = other.head;
    if (t_head_other == nullptr) {
        head = nullptr;
        return;
    }
    SLLNode* firstNode = new SLLNode(t_head_other->data);
    head = firstNode;

    t_head_other = t_head_other->next;
    while (t_head_other != nullptr) {
        SLLNode* newNode = new SLLNode(t_head_other->data);
        firstNode->next = newNode;
        firstNode = newNode;
        t_head_other = t_head_other->next;
    }
}
SLL::~SLL() {
    clear();
}