/**
 * @author Half_nothing
 * @data 2023.06
 * @class SequentialQueue
 */
#ifndef DATA_STRUCTURE_SEQUENTIAL_QUEUE_H
#define DATA_STRUCTURE_SEQUENTIAL_QUEUE_H

#include "Queue.h"

template<typename T>
class SequentialQueue : public Queue<T> {
public:
    SequentialQueue() {
        data = new T[capacity];
    }

    SequentialQueue(const std::initializer_list<T> &init) {
        data = new T[capacity];
        push(init);
    }

    ~SequentialQueue() {
        delete[] data;
        data = nullptr;
    }

    bool push(const T &src) override {
        if (length >= capacity) {
            resize(capacity * 2);
        }
        data[length++] = src;
        return true;
    }

    bool push(const std::initializer_list<T> &src) override {
        for (const T &tmp: src) {
            push(tmp);
        }
        return true;
    }

    T pop() override {
        T res = data[0];
        for (int i = 1; i < length; ++i) {
            data[i - 1] = data[i];
        }
        length--;
        if (length <= capacity / 4 && capacity / 2 >= STACK_MINIMUM_SIZE) {
            resize(capacity / 2);
        }
        return res;
    }

    T &top() override {
        return data[0];
    }

    void clear() override {
        delete[] data;
        data = new T[capacity];
        length = 0;
    }

    bool isEmpty() override {
        return length == 0;
    }

    uint size() override {
        return length;
    }

    friend std::ostream &operator<<(std::ostream &os, const SequentialQueue &queue) {
        os << "SequentialQueue Capacity Usage: " << queue.length << "/" << queue.capacity << std::endl
           << "Content: ";
        for (int i = 0; i < queue.length; ++i) {
            std::cout << queue.data[i] << " ";
        }
        return os;
    }

private:
    T *data = nullptr;
    uint length = 0;
    uint capacity = QUEUE_MINIMUM_SIZE;

    void resize(uint newSize) {
        capacity = newSize;
        T *temp = data;
        data = new T[newSize];
        for (int i = 0; i < length; ++i) {
            data[i] = temp[i];
        }
        delete[] temp;
    }
};


#endif
