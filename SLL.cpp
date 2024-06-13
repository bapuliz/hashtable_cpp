#include "SLL.h"

void SLL::insertAtBeginning(const std::string& data) {
    SLLNode* newNode = new SLLNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void SLL::insertAtEnd(const std::string& data) {
    SLLNode* newNode = new SLLNode(data);
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
        std::cout << t_head->data << std::endl;
        t_head = t_head->next;
    }
}
SLL::~SLL() {
    clear();
}