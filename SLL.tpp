template <typename K, typename V>
V& SLL<K,V>::insertAtBeginning(const std::pair<K, V>& pair) {
    SLLNode<K,V>* newNode = new SLLNode<K,V>(pair.first, pair.second);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return head->data.second;
}

template <typename K, typename V>
bool SLL<K,V>::exists(const K& key) const {
    SLLNode<K,V>* t_head = head;
    while (t_head != nullptr) {
        if (t_head->data.first == key) {
            return true;
        }
        t_head = t_head->next;
    }
    return false;
}
template <typename K, typename V>
SLL_Iterator<K,V> SLL<K,V>::begin() const {
    return SLL_Iterator(head);
}
template <typename K, typename V>
SLL_Iterator<K,V> SLL<K,V>::end() const {
    return SLL_Iterator<K,V>(nullptr);
}

template <typename K, typename V>
void SLL<K,V>::insertAtEnd(const std::pair<K, V>& pair) {
    SLLNode<K,V>* newNode = new SLLNode<K,V>(pair.first, pair.second);
    if (head == nullptr) {
        head = newNode;
    } else {
        SLLNode<K,V>* t_head = head;
        while (t_head->next != nullptr) {
            t_head = t_head->next;
        }
        t_head->next = newNode;
    }
}
template <typename K, typename V>
void SLL<K,V>::remove(const K& key) {
    SLLNode<K,V>* t_head = head;
    if (t_head == nullptr) {
        throw std::out_of_range("KeyError. The specified key is not found in the list");
    }
    if (t_head->data.first == key) {
        head = head->next;
        delete t_head;
        return;
    }
    while (t_head->next != nullptr) {
        if (t_head->next->data.first == key) {
            SLLNode<K,V>* nodeToDelete = t_head->next;
            t_head->next = nodeToDelete->next;
            delete nodeToDelete;
            return;
        }
        t_head = t_head->next;
    }
    throw std::out_of_range("KeyError. The specified key is not found in the list");
}
template <typename K, typename V>
bool SLL<K,V>::isEmpty() const {
    return head == nullptr ? true : false;
}
template <typename K, typename V>
V& SLL<K,V>::find(const K& key) const {
    SLLNode<K,V>* t_head = head;
    while (t_head != nullptr) {
        if (t_head->data.first == key) {
            return t_head->data.second;
        }
        t_head = t_head->next;
    }
    throw std::out_of_range("KeyError. The specified key is not found in the list");
}
template <typename K, typename V>
void SLL<K,V>::clear(){
    while (head != nullptr) {
        SLLNode<K,V>* head_next = head->next;
        delete head;
        head = head_next;
    }
}
template <typename K, typename V>
void SLL<K,V>::print() const{
    SLLNode<K,V>* t_head = head;
    while (t_head != nullptr) {
        std::cout << "Key: " << t_head->data.first << "Value: " << t_head->data.second << std::endl;
        t_head = t_head->next;
    }
}
template <typename K, typename V>
size_t SLL<K,V>::size() const {
    size_t size = 0;
    const SLLNode<K,V>* t_head = head;
    while (t_head != nullptr) {
        ++size;
        t_head = t_head->next;
    }

    return size;
}
template <typename K, typename V>
SLL<K,V>::SLL(const SLL& other) {
    SLLNode<K,V>* t_head_other = other.head;
    if (t_head_other == nullptr) {
        head = nullptr;
        return;
    }
    SLLNode<K,V>* firstNode = new SLLNode<K,V>(t_head_other->data);
    head = firstNode;

    t_head_other = t_head_other->next;
    while (t_head_other != nullptr) {
        SLLNode<K,V>* newNode = new SLLNode<K,V>(t_head_other->data);
        firstNode->next = newNode;
        firstNode = newNode;
        t_head_other = t_head_other->next;
    }
}
template <typename K, typename V>
SLL<K,V>::~SLL() {
    clear();
}