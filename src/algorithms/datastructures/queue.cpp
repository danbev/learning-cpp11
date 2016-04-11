#include <iostream>
#include "dlinkedlist.cpp"

class Queue {
    private:
        DLinkedList * list;
    public:
        Queue();
        Queue &enqueue(int value);
        int dequeue();
        int size() const;
        const IntIterator* iterator() const;
        void print() const;
};

class QueueIterator : public IntIterator {
    private:
        const Queue * queue;
    public:
        QueueIterator(const Queue *queue);
        int next() const;
        bool hasNext() const;
};

Queue::Queue() {
    this->list = new DLinkedList();
}

Queue& Queue::enqueue(int value) {
    list->addEnd(value);
    return *this;
}

int Queue::dequeue() {
    return list->removeFront();
}

int Queue::size() const {
    return list->size();
}

void Queue::print() const {
    list->print();
}

const IntIterator * Queue::iterator() const {
    return list->iterator();
}

