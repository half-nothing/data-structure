#ifndef DATA_STRUCTURE_STRING_H
#define DATA_STRUCTURE_STRING_H

#include <ostream>
#include "StringBase.h"

class String : public StringBase {
public:
    String() {
        data = new char[capacity]{'\0'};
    }

    explicit String(const char *str) {
        length = strlen(str);
        capacity = length * 2;
        data = new char[capacity]{'\0'};
        strcpy(str, data, length);
    }

    String(char src, uint length) {
        this->length = length;
        capacity = length * 2;
        data = new char[capacity]{'\0'};
        fill(src, data, length);
    }

    String(const String &str) {
        length = str.length;
        capacity = str.capacity;
        data = new char[capacity]{'\0'};
        strcpy(str.data, data, length);
    }

    ~String() {
        delete[] data;
    }

    void append(char src) override {
        if (length >= capacity - 1) {
            resize(capacity * 2);
        }
        data[length++] = src;
        data[length] = '\0';
    }

    void append(const char *src) override {
        uint len = strlen(src);
        if (len + 1 >= capacity - length) {
            resize(capacity * 2 + len);
        }
        strcpy(src, data + length, len);
        length += len;
    }

    void append(const String &src) {
        append(src.data);
    }

    void insert(uint pos, char src) override {
        if (pos == length) {
            append(src);
            return;
        }
        if (pos > length) {
            return;
        }
        if (length >= capacity - 1) {
            resize(capacity * 2);
        }
        for (uint i = length; i >= pos; --i) {
            data[i + 1] = data[i];
        }
        data[pos] = src;
        data[++length] = '\0';
    }

    void insert(uint pos, const char *src) override {
        if (pos == length) {
            append(src);
            return;
        }
        if (pos > length) {
            return;
        }
        uint len = strlen(src);
        if (len + 1 >= capacity - length) {
            resize(capacity * 2 + len);
        }
        for (uint i = length; i >= pos; --i) {
            data[i + len] = data[i];
        }
        strcpy(src, data + pos, len);
        length += len;
        data[++length] = '\0';
    }

    void insert(uint pos, const String &src) {
        insert(pos, src.data);
    }

    void replace(char src, char tar) override {
        for (int i = 0; i < length; ++i) {
            if (data[i] == src) {
                data[i] = tar;
            }
        }
    }

    void remove(uint start, uint end) override {
        if (start == 0 && end == length) {
            clear();
            return;
        }
        if (start > end || end > length) {
            return;
        }
        if (start == end) {
            for (uint i = start; i < length; ++i) {
                data[i] = data[i + 1];
            }
            data[length--] = '\0';
            if (length <= capacity / 4 && capacity > STRING_MINIMUM_SIZE) {
                resize(capacity / 2);
            }
            return;
        }
        uint len = end - start + 1;
        for (uint i = start; i < length; ++i) {
            data[i] = data[i + len];
        }
        length -= len;
        data[length + 1] = '\0';
        if (length <= capacity / 4 && capacity > STRING_MINIMUM_SIZE) {
            resize(capacity / 2);
        }
    }

    char &operator[](uint index) {
        return data[index];
    }

    void clear() override {
        delete[] data;
        data = new char[STRING_MINIMUM_SIZE]{'\0'};
        length = 0;
    }

    char *c_str() override {
        return data;
    }

    uint size() override {
        return this->length;
    }

    static uint strlen(const char *str) {
        uint len = 0;
        while (*str != '\0') {
            len++;
            str++;
        }
        return len;
    }

    static uint strcpy(const char *src, char *dst, uint length) {
        uint len = 0;
        while (*src != '\0' && len < length) {
            *dst = *src;
            len++;
            dst++;
            src++;
        }
        return len;
    }

    static uint fill(char src, char *dst, uint length) {
        uint len = 0;
        while (len < length) {
            *dst = src;
            len++;
            dst++;
        }
        return len;
    }

    friend std::ostream &operator<<(std::ostream &os, const String &string) {
        os << "Capacity Usage: " << string.length << "/" << string.capacity << std::endl
           << "Content: " << string.data << std::endl
           << "String length: " << string.length << std::endl;
        return os;
    }

private:
    char *data = nullptr;
    uint length = 0;
    uint capacity = 8;

    void resize(uint newSize) {
        capacity = newSize;
        char *temp = data;
        data = new char[capacity]{'\0'};
        strcpy(temp, data, length);
        delete[] temp;
    }
};


#endif
