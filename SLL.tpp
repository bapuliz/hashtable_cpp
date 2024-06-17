template <typename T, typename V>
V& SLL<T,V>::insertAtBeginning(const std::pair<T, V>& pair) {
    SLLNode<T,V>* newNode = new SLLNode<T,V>(pair.first, pair.second);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return head->data.second;
}

template <typename T, typename V>
bool SLL<T,V>::exists(const T& key) const {
    SLLNode<T,V>* t_head = head;
    while (t_head != nullptr) {
        if (t_head->data.first == key) {
            return true;
        }
        t_head = t_head->next;
    }
    return false;
}
template <typename T, typename V>
SLL_Iterator<T,V> SLL<T,V>::begin() const {
    return SLL_Iterator(head);
}
template <typename T, typename V>
SLL_Iterator<T,V> SLL<T,V>::end() const {
    return SLL_Iterator<T,V>(nullptr);
}

template <typename T, typename V>
void SLL<T,V>::insertAtEnd(const std::pair<T, V>& pair) {
    SLLNode<T,V>* newNode = new SLLNode<T,V>(pair.first, pair.second);
    if (head == nullptr) {
        head = newNode;
    } else {
        SLLNode<T,V>* t_head = head;
        while (t_head->next != nullptr) {
            t_head = t_head->next;
        }
        t_head->next = newNode;
    }
}
template <typename T, typename V>
void SLL<T,V>::remove(const T& key) {
    SLLNode<T,V>* t_head = head;
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
            SLLNode<T,V>* nodeToDelete = t_head->next;
            t_head->next = nodeToDelete->next;
            delete nodeToDelete;
            return;
        }
        t_head = t_head->next;
    }
    throw std::out_of_range("KeyError. Key: " + key + " not found in the list");
}
template <typename T, typename V>
bool SLL<T,V>::isEmpty() const {
    return head == nullptr ? true : false;
}
// V& SLL::update(const T& key, const V& new_value) {
//     SLLNode<T,V>* t_head = head;
//     while (t_head != nullptr) {
//         if (t_head->data.first == key) {
//             t_head->data.second = new_value;
//             return t_head->data.second;
//         }
//         t_head = t_head->next;
//     }
//     throw std::out_of_range("KeyError. Key: " + key + " not found in the list");
// }
template <typename T, typename V>
V& SLL<T,V>::find(const T& key) const {
    SLLNode<T,V>* t_head = head;
    while (t_head != nullptr) {
        if (t_head->data.first == key) {
            return t_head->data.second;
        }
        t_head = t_head->next;
    }
    throw std::out_of_range("KeyError. Key: " + key + " not found in the list");
}
template <typename T, typename V>
void SLL<T,V>::clear(){
    while (head != nullptr) {
        SLLNode<T,V>* head_next = head->next;
        delete head;
        head = head_next;
    }
}
template <typename T, typename V>
void SLL<T,V>::print() const{
    SLLNode<T,V>* t_head = head;
    while (t_head != nullptr) {
        std::cout << "Key: " << t_head->data.first << "Value: " << t_head->data.second << std::endl;
        t_head = t_head->next;
    }
}
template <typename T, typename V>
size_t SLL<T,V>::size() const {
    size_t size = 0;
    const SLLNode<T,V>* t_head = head;
    while (t_head != nullptr) {
        ++size;
        t_head = t_head->next;
    }

    return size;
}
template <typename T, typename V>
SLL<T,V>::SLL(const SLL& other) {
    SLLNode<T,V>* t_head_other = other.head;
    if (t_head_other == nullptr) {
        head = nullptr;
        return;
    }
    SLLNode<T,V>* firstNode = new SLLNode<T,V>(t_head_other->data);
    head = firstNode;

    t_head_other = t_head_other->next;
    while (t_head_other != nullptr) {
        SLLNode<T,V>* newNode = new SLLNode<T,V>(t_head_other->data);
        firstNode->next = newNode;
        firstNode = newNode;
        t_head_other = t_head_other->next;
    }
}
template <typename T, typename V>
SLL<T,V>::~SLL() {
    clear();
}