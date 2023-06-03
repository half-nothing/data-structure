/**
 * @author Half_nothing
 * @data 2023.06
 * @class SequentialStack
 */

#ifndef DATA_STRUCTURE_SEQUENTIAL_STACK_H
#define DATA_STRUCTURE_SEQUENTIAL_STACK_H

#include "Stack.h"

template<typename T>
class SequentialStack : public Stack<T> {
public:
    SequentialStack() {
        data = new T[capacity];
    }

    SequentialStack(const std::initializer_list<T> &init){
        data = new T[capacity];
        push(init);
    }

    ~SequentialStack() {
        delete[] data;
    }

    bool push(const T &src) override {
        if (now < capacity - 1) {
            data[++now] = src;
            return true;
        }
        resize(capacity * 2);
        data[++now] = src;
        return true;
    }

    bool push(const std::initializer_list<T> &src) override {
        for (const T &tmp: src) {
            push(tmp);
        }
        return true;
    }

    T &pop() override {
        if (now == -1) throw std::exception();
        T &temp = data[now--];
        if (now <= capacity / 4 && capacity / 2 >= STACK_MINIMUM_SIZE) {
            resize(capacity / 2);
        }
        return temp;
    }

    T &top() override {
        if (now == -1) throw std::exception();
        return data[now];
    }

    bool isEmpty() override {
        return now == -1;
    }

    void clear() override {
        delete[] data;
        now = -1;
        data = new T[capacity];
    }

    uint size() override {
        return now + 1;
    }

    friend std::ostream &operator<<(std::ostream &os, const SequentialStack &stack) {
        os << "SequentialStack Capacity Usage: " << stack.now + 1 << "/" << stack.capacity << std::endl
           << "Content: ";
        for (int i = 0; i < stack.now + 1; ++i) {
            std::cout << stack.data[i] << " ";
        }
        std::cout << std::endl;
        return os;
    }

private:
    T *data = nullptr;
    int now = -1;
    int capacity = 8;

    void resize(int newSize) {
        capacity = newSize;
        T *temp = data;
        data = new T[capacity];
        for (int i = 0; i < now + 1; ++i) {
            data[i] = temp[i];
        }
        delete[] temp;
    }
};

#endif