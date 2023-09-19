/**
 * @author Half_nothing
 * @data 2023.06
 * @class ChainStack
 */

#ifndef DATA_STRUCTURE_CHAIN_STACK_H
#define DATA_STRUCTURE_CHAIN_STACK_H

#include "Stack.h"

template<typename T>
class ChainStack : public Stack<T> {
public:
    ChainStack() {
        head = new SingleLinkNode<T>();
    }

    ChainStack(const std::initializer_list<T> &init) {
        head = new SingleLinkNode<T>();
        push(init);
    }

    ~ChainStack() {
        uint total = 0; // 开个变量用来记录释放数量
        SingleLinkNode<T> *temp;
        while (head != nullptr) {
            temp = head->next;
            delete head;
            head = temp;
            total++;
        }
        std::cout << "Release " << total << " nodes" << std::endl;
    }

    bool push(const T &src) override {
        SingleLinkNode<T> *temp = new SingleLinkNode<T>(src);
        temp->next = head->next;
        head->next = temp;
        length++;
        return true;
    }

    bool push(const std::initializer_list<T> &src) override {
        for (const T &tmp: src) {
            push(tmp);
        }
        return true;
    }

    T &pop() override {
        SingleLinkNode<T> *temp = head->next;
        head->next = temp->next;
        T &tmp = temp->data;
        delete temp;
        length--;
        return tmp;
    }

    T &top() override {
        return head->next->data;
    }

    bool isEmpty() override {
        return length == 0;
    }

    void clear() override {
        SingleLinkNode<T> *temp;
        while (head != nullptr) {
            temp = head->next;
            delete head;
            head = temp;
        }
        head = new SingleLinkNode<T>();
    }

    uint size() override {
        return length;
    }

    friend std::ostream &operator<<(std::ostream &os, const ChainStack &stack) {
        os << "ChainStack Length: " << stack.length << std::endl
           << "Content: ";
        SingleLinkNode<T> *temp = stack.head->next;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        return os;
    }

private:
    SingleLinkNode<T> *head;
    uint length = 0;
};


#endif
