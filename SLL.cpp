#include "SLL.h"

int& SLL::insertAtBeginning(const std::pair<std::string, int>& pair) {
    SLLNode* newNode = new SLLNode(pair.first, pair.second);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return head->data.second;
}

bool SLL::exists(const std::string& key) const {
    SLLNode* t_head = head;
    while (t_head != nullptr) {
        if (t_head->data.first == key) {
            return true;
        }
        t_head = t_head->next;
    }
    return false;
}
SLL_Iterator SLL::begin() const {
    return SLL_Iterator(head);
}
SLL_Iterator SLL::end() const {
    return SLL_Iterator(nullptr);
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
void SLL::remove(const std::string& key) {
    SLLNode* t_head = head;
    if (t_head == nullptr) {
        throw std::out_of_range("KeyError. Key: " + key + " not found in the list");
    }
    if (t_head->data.first == key) {
        head = head->next;
        delete t_head;
        return;
    }
    while (t_head->next != nullptr) {
        if (t_head->next->data.first == key) {
            SLLNode* nodeToDelete = t_head->next;
            t_head->next = nodeToDelete->next;
            delete nodeToDelete;
            return;
        }
        t_head = t_head->next;
    }
    throw std::out_of_range("KeyError. Key: " + key + " not found in the list");
}
bool SLL::isEmpty() const {
    return head == nullptr ? true : false;
}
int& SLL::update(const std::string& key, const int& new_value) {
    SLLNode* t_head = head;
    while (t_head != nullptr) {
        if (t_head->data.first == key) {
            t_head->data.second = new_value;
            return t_head->data.second;
        }
        t_head = t_head->next;
    }
    throw std::out_of_range("KeyError. Key: " + key + " not found in the list");
}
int SLL::find(const std::string& key) const {
    SLLNode* t_head = head;
    while (t_head != nullptr) {
        if (t_head->data.first == key) {
            return t_head->data.second;
        }
        t_head = t_head->next;
    }
    throw std::out_of_range("KeyError. Key: " + key + " not found in the list");
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