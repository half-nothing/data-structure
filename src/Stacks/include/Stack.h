#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#include "include.h"

template<typename T>
class Stack {
public:
    virtual bool push(const T &src) = 0;

    virtual bool push(const std::initializer_list<T> &src) = 0;

    virtual T &pop() = 0;

    virtual T &top() = 0;

    virtual bool isEmpty() = 0;

    virtual void clear() = 0;

    virtual uint size() = 0;
};

#endif
