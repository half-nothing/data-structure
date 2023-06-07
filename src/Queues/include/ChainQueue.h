/**
 * @author Half_nothing
 * @data 2023.06
 * @class ChainQueue
 */

#ifndef DATA_STRUCTURE_CHAIN_QUEUE_H
#define DATA_STRUCTURE_CHAIN_QUEUE_H

#include "Queue.h"

template<typename T>
class ChainQueue : public Queue<T> {
public:
    ChainQueue() {
        head = new DoubleLinkNode<T>();
        tail = new DoubleLinkNode<T>();
        head->next = tail;
        tail->prev = head;
    }

    ChainQueue(const std::initializer_list<T> &init) {
        head = new DoubleLinkNode<T>();
        tail = new DoubleLinkNode<T>();
        head->next = tail;
        tail->prev = head;
        push(init);
    }

    ~ChainQueue() {
        DoubleLinkNode<T> *temp;
        uint total = 0;
        while (head != nullptr) {
            temp = head->next;
            delete head;
            head = temp;
            total++;
        }
        std::cout << "Release " << total << " nodes." << std::endl;
    }

    bool push(const T &src) override {
        DoubleLinkNode<T> *temp = new DoubleLinkNode<T>(src);
        tail->prev->next = temp;
        temp->next = tail;
        temp->prev = tail->prev;
        tail->prev = temp;
        length++;
        return true;
    }

    bool push(const std::initializer_list<T> &src) override {
        for (const T &tmp: src) {
            push(tmp);
        }
        return true;
    }

    T pop() override {
        DoubleLinkNode<T> *temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
        length--;
        T tmp = temp->data;
        delete temp;
        return tmp;
    }

    T &top() override {
        return head->next->data;
    }

    void clear() override {
        DoubleLinkNode<T> *temp;
        while (head != nullptr) {
            temp = head->next;
            delete head;
            head = temp;
        }
        length = 0;
        head = new DoubleLinkNode<T>();
        tail = new DoubleLinkNode<T>();
        head->next = tail;
        tail->prev = head;
    }

    bool isEmpty() override {
        return length == 0;
    }

    uint size() override {
        return length;
    }

    friend std::ostream &operator<<(std::ostream &os, const ChainQueue &queue) {
        os << "ChainQueue Length: " << queue.length << std::endl
           << "Content: ";
        DoubleLinkNode<T> *temp = queue.head->next;
        while (temp != queue.tail) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
        return os;
    }

private:
    DoubleLinkNode<T> *head;
    DoubleLinkNode<T> *tail;
    uint length = 0;
};


#endif
