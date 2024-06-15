#ifndef SLL_ITERATOR_H
#define SLL_ITERATOR_H

class SLL_Iterator {
    SLLNode* current;
    SLL_Iterator() = delete;
    public:
        SLL_Iterator (SLLNode* t) : current(t) {}
        SLL_Iterator& operator++() {
            current = current->next;
            return (*this);
        }
        std::pair<std::string, int> operator* () {
            return current->data;
        }
        bool operator!= (const SLL_Iterator& t) const{
            return (t.current != current ? true : false);
        }

};



#endif // SLLITERATOR_H