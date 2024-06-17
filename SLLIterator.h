#ifndef SLL_ITERATOR_H
#define SLL_ITERATOR_H

template <typename T, typename V>
class SLL_Iterator {
    SLLNode<T,V>* current;
    SLL_Iterator() = delete;
    public:
        SLL_Iterator<T,V> (SLLNode<T,V>* t) : current(t) {}
        SLL_Iterator<T,V>& operator++() {
            current = current->next;
            return (*this);
        }
        std::pair<T, V> operator* () {
            return current->data;
        }
        bool operator!= (const SLL_Iterator<T,V>& t) const{
            return (t.current != current ? true : false);
        }

};

#endif // SLLITERATOR_H