/**
 * @author Half_nothing
 * @data 2023.06
 * @class CircularlyLinkList
 */

#ifndef DATA_STRUCTURE_CIRCULARLY_LINK_LIST_H
#define DATA_STRUCTURE_CIRCULARLY_LINK_LIST_H

#include "List.h"

template<typename T>
class CircularlyLinkList : public List<T> {
public:
    CircularlyLinkList() {
        head = new DoubleLinkNode<T>();
        head->prev = head;
        head->next = head;
    }

    CircularlyLinkList(const std::initializer_list<T> &init) {
        head = new DoubleLinkNode<T>();
        head->prev = head;
        head->next = head;
        append(init);
    }

    ~CircularlyLinkList() {
        uint total = 0;
        head->prev->next = nullptr; // 首先断开圆环
        DoubleLinkNode<T> *temp;
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
        DoubleLinkNode<T> *temp;
        while (head != nullptr) { // 依次delete
            temp = head->next;
            delete head;
            head = temp;
        }
        length = 0;
        head = new DoubleLinkNode<T>();
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
        DoubleLinkNode<T> *temp = new DoubleLinkNode<T>(src);
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
        DoubleLinkNode<T> *temp = findPtr(pos);
        DoubleLinkNode<T> *tmp = new DoubleLinkNode<T>(src);
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
        DoubleLinkNode<T> *temp = findPtr(pos);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        length--;
        return true;
    }

    bool remove(uint start, uint end) override {
        if (start > end) return false;
        if (start == end) return remove(start);
        DoubleLinkNode<T> *startPtr = findPtr(start);
        DoubleLinkNode<T> *endPtr = findPtr(end);
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

    T &find(uint pos) override {
        return findPtr(pos)->data;
    }

    bool setValue(uint pos, const T &src) override {
        findPtr(pos)->data = src;
        return true;
    }

    int getPos(const T &src) override {
        int index = 0;
        DoubleLinkNode<T> *temp = head->next;
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
        DoubleLinkNode<T> *startPtr = findPtr(start);
        DoubleLinkNode<T> *endPtr = findPtr(end);
        while (startPtr != endPtr->next) {
            opt(startPtr->data);
            startPtr = startPtr->next;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const CircularlyLinkList &list) {
        os << "CircularlyLinkList Length: " << list.length << std::endl
           << "Content: ";
        DoubleLinkNode<T> *temp = list.head->next;
        while (temp != list.head) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
        return os;
    }

private:
    DoubleLinkNode<T> *head;
    uint length = 0;

    DoubleLinkNode<T> *findPtr(uint pos){
        uint index = 0;
        DoubleLinkNode<T> *temp = head->next;
        while (temp->next != head){
            if (index == pos) return temp;
            index++;
            temp = temp->next;
        }
        return temp;
    }
};


#endif
