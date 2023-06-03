#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

template<typename T>
class Queue {
public:
    virtual bool push(const T &src) = 0;

    virtual T &pop() = 0;

    virtual T &front() = 0;

    virtual T &back() = 0;
};

#endif
