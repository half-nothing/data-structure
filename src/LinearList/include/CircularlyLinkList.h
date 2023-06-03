/**
 * @author Half_nothing
 * @data 2023.06
 * @class CircularlyLinkList
 */

#ifndef DATA_STRUCTURE_CIRCULARLY_LINK_LIST_H
#define DATA_STRUCTURE_CIRCULARLY_LINK_LIST_H

#include "List.h"

template<typename T>
struct LinkNode {
    LinkNode *prev{nullptr};
    LinkNode *next{nullptr};
    T data{};

    LinkNode() = default;

    explicit LinkNode(const T &src) : data(src) {}
};

template<typename T>
class CircularlyLinkList : public List<T> {
public:
    CircularlyLinkList() {
        head = new LinkNode<T>();
        head->prev = head;
        head->next = head;
    }

    CircularlyLinkList(const std::initializer_list<T> &init) {
        head = new LinkNode<T>();
        head->prev = head;
        head->next = head;
        append(init);
    }

    ~CircularlyLinkList() {
        uint total = 0;
        head->prev->next = nullptr; // 首先断开圆环
        LinkNode<T> *temp;
        while (head != nullptr) { // 依次delete
            temp = head->next;
            delete head;
            head = temp;
            total++;
        }
        std::cout << "Release " << total << " nodes." << std::endl;
    }

    void clear() override {
        head->prev->next = nullptr; // 首先断开圆环
        LinkNode<T> *temp;
        while (head != nullptr) { // 依次delete
            temp = head->next;
            delete head;
            head = temp;
        }
        length = 0;
        head = new LinkNode<T>();
        head->prev = head;
        head->next = head;
    }

    bool isEmpty() override {
        return length == 0;
    }

    uint size() override {
        return length;
    }

    bool append(const T &src) override {
        LinkNode<T> *temp = new LinkNode<T>(src);
        temp->next = head;
        temp->prev = head->prev;
        head->prev = temp;
        temp->prev->next = temp;
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
        LinkNode<T> *temp = findPtr(pos);
        LinkNode<T> *tmp = new LinkNode<T>(src);
        tmp->next = temp;
        tmp->prev = temp->prev;
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
        LinkNode<T> *temp = findPtr(pos);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        length--;
        return true;
    }

    bool remove(uint start, uint end) override {
        if (start > end) return false;
        if (start == end) return remove(start);
        LinkNode<T> *startPtr = findPtr(start);
        LinkNode<T> *endPtr = findPtr(end);
        startPtr->prev->next = endPtr->next;
        endPtr->next->prev = startPtr->prev;
        length -= end - start + 1;
        LinkNode<T> *temp;
        while (startPtr != endPtr->next) {
            temp = startPtr->next;
            delete startPtr;
            startPtr = temp;
        }
        return true;
    }

    T &find(uint pos) override {
        return findPtr(pos)->data;
    }

    bool setValue(uint pos, const T &src) override {
        findPtr(pos)->data = src;
        return true;
    }

    int getPos(const T &src) override {
        int index = 0;
        LinkNode<T> *temp = head->next;
        while (temp->next != head){
            if (temp->data == src) return index;
            index++;
            temp = temp->next;
        }
        return -1;
    }

    T &operator[](int pos) override {
        return find(pos);
    }

    void forEach(uint start, uint end, void (*opt)(T &)) override {
        LinkNode<T> *startPtr = findPtr(start);
        LinkNode<T> *endPtr = findPtr(end);
        while (startPtr != endPtr->next) {
            opt(startPtr->data);
            startPtr = startPtr->next;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const CircularlyLinkList &list) {
        os << "CircularlyLinkList Length: " << list.length << std::endl
           << "Content: ";
        LinkNode<T> *temp = list.head->next;
        while (temp != list.head) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
        return os;
    }

private:
    LinkNode<T> *head;
    uint length = 0;

    LinkNode<T> *findPtr(uint pos){
        uint index = 0;
        LinkNode<T> *temp = head->next;
        while (temp->next != head){
            if (index == pos) return temp;
            index++;
            temp = temp->next;
        }
        return temp;
    }
};


#endif
