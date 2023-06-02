/**
 * @author Half_nothing
 * @data 2023.06
 * @class DoubleLinkList
 */

#ifndef DATA_STRUCTURE_DOUBLE_LINK_LIST_H
#define DATA_STRUCTURE_DOUBLE_LINK_LIST_H

#include <ostream>
#include "List.h"

template<typename T>
struct LinkNode {
    LinkNode *prev{nullptr};
    LinkNode *next{nullptr};
    T data{};

    LinkNode() = default;

    LinkNode(const T &src) : data(src) {}
};

template<typename T>
class DoubleLinkList : public List<T> {
public:
    DoubleLinkList() {
        head = new LinkNode<T>();
        tail = new LinkNode<T>();
        head->next = tail;
        tail->prev = head;
    };

    ~DoubleLinkList() {
        uint total = 0; // 开个变量用来记录释放数量
        LinkNode<T> *tmp;
        while (head != tail) {
            tmp = head->next;
            delete head;
            head = tmp;
            total++;
        }
        delete head;
        std::cout << "Release " << total + 1 << " nodes" << std::endl;
    }

    DoubleLinkList(const std::initializer_list<T> &init) {
        head = new LinkNode<T>();
        tail = new LinkNode<T>();
        head->next = tail;
        tail->prev = head;
        append(init);
    }

    void clear() override {
        LinkNode<T> *tmp;
        while (head != tail) {
            tmp = head->next;
            delete head;
            head = tmp;
        }
        delete head;
        head = new LinkNode<T>();
        tail = new LinkNode<T>();
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
        LinkNode<T> *tmp = new LinkNode<T>{src};
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
        LinkNode<T> *temp = findNode(pos);
        LinkNode<T> *tmp = new LinkNode<T>{src};
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
        LinkNode<T> *temp = findNode(pos);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        length--;
        return true;
    }

    bool remove(uint start, uint end) override {
        if (start > end) return false;
        if (start == end) return remove(start);
        LinkNode<T> *startPtr = findNode(start);
        LinkNode<T> *endPtr = findNode(end);
        startPtr->prev->next = endPtr->next;
        endPtr->next->prev = startPtr->prev;
        length -= end - start + 1;
        LinkNode<T> *temp;
        while (startPtr != endPtr) {
            temp = startPtr->next;
            delete startPtr;
            startPtr = temp;
        }
        delete startPtr;
        return true;
    }

    T &find(uint pos) override {
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
        LinkNode<T> *startPtr = findNode(start);
        LinkNode<T> *endPtr = findNode(end);
        LinkNode<T> *temp;
        while (startPtr != endPtr) {
            temp = startPtr->next;
            opt(startPtr->data);
            startPtr = temp;
        }
        opt(startPtr->data);
    }

    friend std::ostream &operator<<(std::ostream &os, const DoubleLinkList &list) {
        os << "DoubleLinkList Length: " << list.length << std::endl
           << "Content: ";
        LinkNode<T> *temp = list.head->next;
        while (temp != list.tail) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
        return os;
    }

private:
    LinkNode<T> *head;
    LinkNode<T> *tail;
    uint length = 0;

    LinkNode<T> *findNode(uint pos) {
        uint index = 0;
        LinkNode<T> *temp = head->next;
        while (temp != nullptr) {
            if (index == pos) break;
            temp = temp->next;
            index++;
        }
        return temp;
    }

    int findNode(const T &src, bool ) {
        int index = 0;
        LinkNode<T> *temp = head->next;
        while (temp != tail) {
            if (temp->data == src) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }
};


#endif
