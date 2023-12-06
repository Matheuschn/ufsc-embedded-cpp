#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

template<typename T>
class Node {
    private:
        T val;
        Node *next;
    public:
        Node(T value): val(value) {
            next = nullptr;
        }

        T getValue() { return val; };
        Node *getNext() { return next; };
        void changeValue(T value) { val = value; };
        void changeNext(Node *ptr) { next = ptr; };
};

#endif
