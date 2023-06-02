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
        data = new T[capacity];
    }

    Array(const std::initializer_list<T> &init) {
        data = new T[capacity];
        append(init);
    }

    ~Array() {
        if (data != nullptr) {
            delete[] data;
        }
    }

    void clear() override {
        delete[] data;
        length = 0;
        data = new T[capacity];
    }

    bool isEmpty() override {
        return length == 0;
    }

    uint size() override {
        return length;
    }

    bool append(const T &src) override {
        if (length < capacity) {
            data[length++] = src;
            return true;
        }
        resize(capacity * 2);
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
        if (pos >= length) return append(src);
        if (length >= capacity) {
            resize(capacity * 2);
        }
        for (int i = length; i > pos; --i) {
            data[i] = data[i - 1];
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
        if (pos >= length) return false;
        for (int i = pos; i < length - 1; ++i) {
            data[i] = data[i + 1];
        }
        length--;
        if (length <= capacity / 4 && capacity / 2 > ARRAY_MINIMUM_SIZE) {
            resize(capacity / 2);
        }
        return true;
    }

    bool remove(uint start, uint end) override {
        if (end >= length) return false;
        if (start > end) return false;
        for (int i = end; i < length; ++i) {
            data[start + i - end] = data[i];
        }
        length -= end - start + 1;
        if (length <= capacity / 4 && capacity / 2 > ARRAY_MINIMUM_SIZE) {
            resize(capacity / 2);
        }
        return true;
    }

    T &find(uint pos) override {
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
        out << std::endl;
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
    }
};

#endif
