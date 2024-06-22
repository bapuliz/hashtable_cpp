#ifndef SLL_ITERATOR_H
#define SLL_ITERATOR_H

template <typename K, typename V>
class SLL_Iterator {
    SLLNode<K,V>* current;
    SLL_Iterator() = delete;
    public:
        SLL_Iterator<K,V> (SLLNode<K,V>* t) : current(t) {}
        SLL_Iterator<K,V>& operator++() {
            current = current->next;
            return (*this);
        }
        std::pair<K, V> operator* () {
            return current->data;
        }
        bool operator!= (const SLL_Iterator<K,V>& t) const{
            return (t.current != current ? true : false);
        }

};

#endif // SLLITERATOR_H