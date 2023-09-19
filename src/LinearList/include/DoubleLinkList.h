/**
 * @author Half_nothing
 * @data 2023.06
 * @class DoubleLinkList
 */

#ifndef DATA_STRUCTURE_DOUBLE_LINK_LIST_H
#define DATA_STRUCTURE_DOUBLE_LINK_LIST_H

#include "List.h"

template<typename T>
class DoubleLinkList : public List<T> {
public:
    DoubleLinkList() {
        head = new DoubleLinkNode<T>();
        tail = new DoubleLinkNode<T>();
        head->next = tail;
        tail->prev = head;
    };

    ~DoubleLinkList() {
        uint total = 0; // 开个变量用来记录释放数量
        DoubleLinkNode<T> *tmp;
        while (head != nullptr) {
            tmp = head->next;
            total++;
            delete head;
            head = tmp;
        }
        std::cout << "Release " << total << " nodes" << std::endl;
    }

    DoubleLinkList(const std::initializer_list<T> &init) {
        head = new DoubleLinkNode<T>();
        tail = new DoubleLinkNode<T>();
        head->next = tail;
        tail->prev = head;
        append(init);
    }

    void clear() override {
        DoubleLinkNode<T> *tmp;
        while (head != nullptr) {
            tmp = head->next;
            delete head;
            head = tmp;
        }
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

    bool append(const T &src) override {
        DoubleLinkNode<T> *tmp = new DoubleLinkNode<T>{src};
        tmp->next = tail;
        tmp->prev = tail->prev;
        tail->prev = tmp;
        tmp->prev->next = tmp;
        length++;
        return true;
    }

    bool append(const std::initializer_list<T> &src) override {
        for (const T &tmp: src) {
            append(tmp);
        }
        return true;
    }

    bool insert(uint pos, const T &src) override {
        if (pos >= length) return append(src);
        DoubleLinkNode<T> *temp = findNode(pos);
        DoubleLinkNode<T> *tmp = new DoubleLinkNode<T>{src};
        tmp->prev = temp->prev;
        tmp->next = temp;
        temp->prev = tmp;
        tmp->prev->next = tmp;
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
        DoubleLinkNode<T> *temp = findNode(pos);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        length--;
        return true;
    }

    bool remove(uint start, uint end) override {
        if (start > end) return false;
        if (start == end) return remove(start);
        DoubleLinkNode<T> *startPtr = findNode(start);
        DoubleLinkNode<T> *endPtr = findNode(end);
        startPtr->prev->next = endPtr->next;
        endPtr->next->prev = startPtr->prev;
        length -= end - start + 1;
        DoubleLinkNode<T> *temp;
        while (startPtr != endPtr->next) {
            temp = startPtr->next;
            delete startPtr;
            startPtr = temp;
        }
        return true;
    }

    T &get(uint pos) override {
        return findNode(pos)->data;
    }

    bool setValue(uint pos, const T &src) override {
        if (pos >= length) return false;
        findNode(pos)->data = src;
        return true;
    }

    int getPos(const T &src) override {
        return findNode(src, false);
    }

    T &operator[](int pos) override {
        return findNode(pos)->data;
    }

    void forEach(uint start, uint end, void (*opt)(T &)) override {
        DoubleLinkNode<T> *startPtr = findNode(start);
        DoubleLinkNode<T> *endPtr = findNode(end);
        while (startPtr != endPtr->next) {
            opt(startPtr->data);
            startPtr = startPtr->next;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const DoubleLinkList &list) {
        os << "DoubleLinkList Length: " << list.length << std::endl
           << "Content: ";
        DoubleLinkNode<T> *temp = list.head->next;
        while (temp != list.tail) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        return os;
    }

private:
    DoubleLinkNode<T> *head;
    DoubleLinkNode<T> *tail;
    uint length = 0;

    DoubleLinkNode<T> *findNode(uint pos) {
        uint index = 0;
        DoubleLinkNode<T> *temp = head->next;
        while (temp != nullptr) {
            if (index == pos) break;
            temp = temp->next;
            index++;
        }
        return temp;
    }

    int findNode(const T &src, bool) {
        int index = 0;
        DoubleLinkNode<T> *temp = head->next;
        while (temp != tail) {
            if (temp->data == src) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }
};


#endif
