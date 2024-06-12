#include <string>
#include <iostream>

#include "SLLNode.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
    SLLNode* head;
    public:
        LinkedList () : head(nullptr) {};
        void insertAtEnd(const std::string& data) {
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
        void print() {
            SLLNode* t_head = head;
            while (t_head != nullptr) {
                std::cout << t_head->data << std::endl;
                t_head = t_head->next;
            }
        }

};

#endif