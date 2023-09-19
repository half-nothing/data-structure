/**
 * @author Half_nothing
 * @data 2023.06
 * @class Array
 */

#ifndef DATA_STRUCTURE_ARRAY_H
#define DATA_STRUCTURE_ARRAY_H

#include "List.h"

template<typename T>
class Array : public List<T> {
public:
    Array() {
        data = new T[capacity]{}; // 开一块新空间并初始化
    }

    Array(const std::initializer_list<T> &init) {
        data = new T[capacity]{};
        append(init);
    }

    ~Array() {
        delete[] data; // 如果不是空指针则delete掉(nullptr delete也没啥事就是说)
    }

    void clear() override {
        delete[] data; // 清空数据存储
        length = 0;
        data = new T[capacity]; // 新开一块内存
    }

    bool isEmpty() override {
        return length == 0;
    }

    uint size() override {
        return length;
    }

    bool append(const T &src) override {
        if (length < capacity) { // 如果没有超出容量限制
            data[length++] = src; // 直接放进去然后长度+1
            return true;
        }
        resize(capacity * 2); // 如果超出容量限制则重新分配空间,新空间大小是原来的两倍(n特别大的时候会内存错误)
        data[length++] = src;
        return true;
    }

    bool append(const std::initializer_list<T> &args) override {
        for (const T &tmp: args) {
            append(tmp);
        }
        return true;
    }

    bool insert(uint pos, const T &src) override {
        if (pos >= length) return append(src); // 如果pos大于长度,压根找不到你这个地方就在队尾推入
        if (length >= capacity) {
            resize(capacity * 2);
        }
        for (int i = length; i > pos; --i) {
            data[i] = data[i - 1]; // 将元素依次后移一个位置
        }
        data[pos] = src;
        length++;
        return true;
    }

    bool insert(const std::initializer_list<std::pair<uint, T>> &src) override {
        for (const std::pair<uint, T> &tmp: src) {
            insert(tmp.first, tmp.second);
        }
        return true;
    }

    bool remove(uint pos) override {
        if (pos >= length) return false; // 如果压根没有,直接返回
        for (int i = pos; i < length - 1; ++i) {
            data[i] = data[i + 1]; // 元素依次前移
        }
        length--;
        if (length <= capacity / 4 && capacity / 2 >= ARRAY_MINIMUM_SIZE) {
            resize(capacity / 2); // 如果当前长度小于等于容量的四分之一并且容量的一半大于等于最小容量,则缩容至原来的一半
        }
        return true;
    }

    bool remove(uint start, uint end) override {
        if (end >= length) return false;
        if (start > end) return false;
        for (int i = end; i < length; ++i) {
            data[start + i - end] = data[i]; // 直接整体前移
        }
        length -= end - start + 1;
        if (length <= capacity / 4 && capacity / 2 >= ARRAY_MINIMUM_SIZE) {
            resize(capacity / 2);
        }
        return true;
    }

    T &get(uint pos) override {
        return data[pos];
    }

    bool setValue(uint pos, const T &src) override {
        if (pos >= length) return false;
        data[pos] = src;
        return true;
    }

    int getPos(const T &src) override {
        for (int i = 0; i < length; ++i) {
            if (data[i] == src) {
                return i;
            }
        }
        return -1;
    }

    T &operator[](int pos) override {
        return data[pos];
    }

    void forEach(uint start, uint end, void (*opt)(T &)) override {
        if (end > length) return;
        if (start > end) return;
        for (int i = start; i < end; ++i) {
            opt(data[i]);
        }
    }

    friend std::ostream &operator<<(std::ostream &out, const Array<T> &src) {
        out << "Capacity Usage: " << src.length << "/" << src.capacity << std::endl
            << "Content: ";
        for (int i = 0; i < src.length; ++i) {
            out << src.data[i] << " ";
        }
        return out;
    }

private:
    T *data = nullptr;
    uint length = 0;
    uint capacity = 8;

    void resize(uint newSize) {
        capacity = newSize;
        T *temp = data;
        data = new T[capacity];
        for (int i = 0; i < length; i++) {
            data[i] = temp[i];
        }
        delete[] temp;
    }
};

#endif
