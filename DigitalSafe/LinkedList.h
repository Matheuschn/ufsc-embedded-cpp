#include "Node.h"
#include "internals.h"

#ifndef __LINKEDLIST_H_INCLUDED__
#define __LINKEDLIST_H_INCLUDED__

template<typename T>
class LinkedList {
    private:
        Node<T> *head;
        Node<T> *tail;
        unsigned int listLength;
    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
            listLength = 0;
        }

        T get(unsigned int position) {
            if (position > listLength - 1) {
                return nullptr;
            }

            Node<T> *current = head;
            for (unsigned int i = 0; i <= position; i++) {
                if (i == position) return current->getValue();
                current = current->getNext();
            }

            return nullptr;
        };

        void pushBack(T value) {
            Node<T> *node = new Node<T>(value);
            listLength++;

            if (head == nullptr) {
                head = node;
                tail = head;
                return;
            }

            tail->changeNext(node);
            tail = node;
        };

        T deleteNode(unsigned int position) {
            if (position > listLength - 1) {
                return nullptr;
            }

            listLength--;

            if (head == tail) {
                T value = head->getValue();
                delete head;
                head = nullptr;
                tail = nullptr;
                return value;
            }

            Node<T> *current = head, *previous = nullptr;
            for (unsigned int i = 0; i <= position; i++) {
                if (i == position) {
                    T value = current->getValue();
                    Node<T> *next = current->getNext();

                    if (position == 0) {
                        head = next;
                    } else {
                        previous->changeNext(next);
                    }

                    delete current;

                    if (position == listLength) tail = previous;

                    return value;
                }

                previous = current;
                current = current->getNext();
            }

            return nullptr;
        };

        void clearList() {
            if (!listLength) return;

            Node<T> *current = head, *tmp;

            for (unsigned int i = 0; i < listLength; i++) {
                tmp = current->getNext();
                delete current;
                current = tmp;
            }

            head = nullptr;
            tail = nullptr;
            listLength = 0;
        }

        unsigned int length() { return listLength; };
};

#endif
