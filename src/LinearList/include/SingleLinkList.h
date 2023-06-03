#ifndef DATA_STRUCTURE_SINGLE_LINK_LIST_H
#define DATA_STRUCTURE_SINGLE_LINK_LIST_H

#include <initializer_list>
#include "List.h"

template<typename T>
struct LinkNode {
    LinkNode<T> *next{nullptr};
    T data;

    LinkNode() = default;

    explicit LinkNode(const T &data) : data(data) {}
};

template<typename T>
class SingleLinkList : public List<T> {
public:
    SingleLinkList() {
        head = new LinkNode<T>();
    };

    SingleLinkList(const std::initializer_list<T> &init){
        head = new LinkNode<T>();
        append(init);
    }

    ~SingleLinkList() {
        uint total = 0;
        LinkNode<T> *tmp;
        while (head != nullptr) {
            tmp = head->next;
            delete head;
            total++;
            head = tmp;
        }
        std::cout << "Release " << total << " nodes." << std::endl;
    }

    void clear() override {
        LinkNode<T> *tmp;
        while (head != nullptr) {
            tmp = head->next;
            delete head;
            head = tmp;
        }
        length = 0;
        head = new LinkNode<T>();
    }

    bool isEmpty() override {
        return length == 0;
    }

    uint size() override {
        return length;
    }

    bool append(const T &src) override {
        LinkNode<T> *temp = new LinkNode<T>(src);
        LinkNode<T> *tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = temp;
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
        LinkNode<T> *tmp = findPtr(pos);
        LinkNode<T> *temp = new LinkNode<T>(src);
        temp->next = tmp->next;
        tmp->next = temp;
        length++;
        return true;
    }

    bool insert(const std::initializer_list<std::pair<uint, T>> &src) override {
        for (const std::pair<uint, T> &tmp: src){
            insert(tmp.first, tmp.second);
        }
        return true;
    }

    bool remove(uint pos) override {
        if (pos >= length) return false;
        LinkNode<T> *temp = findPtr(pos);
        LinkNode<T> *target = temp->next;
        temp->next = target->next;
        delete target;
        length--;
        return true;
    }

    bool remove(uint start, uint end) override {
        if (start > end) return false;
        if (start == end) return remove(start);
        if (end >= length) {
            LinkNode<T> *startPtr = findPtr(start);
            LinkNode<T> *temp = startPtr->next;
            startPtr->next = nullptr;
            startPtr = temp;
            while (startPtr != nullptr){
                temp = startPtr->next;
                delete startPtr;
                startPtr = temp;
            }
            length -= length - start - 1;
            return true;
        }
        LinkNode<T> *startPtr = findPtr(start);
        LinkNode<T> *endPtr = findPtr(end);
        LinkNode<T> *temp = startPtr->next;
        startPtr->next = endPtr->next->next;
        startPtr = temp;
        endPtr = endPtr->next;
        while (startPtr != endPtr->next){
            temp = startPtr->next;
            delete startPtr;
            startPtr = temp;
        }
        length -= end - start + 1;
        return true;
    }

    T &find(uint pos) override {
        return findPtr(pos)->next->data;
    }

    bool setValue(uint pos, const T &src) override {
        findPtr(pos)->next->data = src;
        return true;
    }

    int getPos(const T &src) override {
        int total = 0;
        LinkNode<T> *temp = head->next;
        while (temp != nullptr){
            if (temp->data == src) return total;
            total++;
            temp = temp->next;
        }
        return -1;
    }

    T &operator[](int pos) override {
        return find(pos);
    }

    void forEach(uint start, uint end, void (*opt)(T &)) override {
        if (start > end) return;
        LinkNode<T> *startPtr = findPtr(start)->next;
        LinkNode<T> *endPtr = findPtr(end);
        while (startPtr != endPtr->next){
            opt(startPtr->data);
            startPtr = startPtr->next;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const SingleLinkList &list) {
        os << "SingleLinkList Length: " << list.length << std::endl
            << "Content: ";
        LinkNode<T> *temp = list.head->next;
        while (temp != nullptr){
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
        uint total = 0;
        LinkNode<T> *prev = head;
        LinkNode<T> *temp = head->next;
        while (temp != nullptr){
            if (total == pos) return prev;
            total++;
            prev = temp;
            temp = temp->next;
        }
        return prev;
    }
};


#endif
