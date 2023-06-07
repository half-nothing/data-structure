#ifndef DATA_STRUCTURE_SINGLE_LINK_LIST_H
#define DATA_STRUCTURE_SINGLE_LINK_LIST_H

#include "List.h"

template<typename T>
class SingleLinkList : public List<T> {
public:
    SingleLinkList() {
        head = new SingleLinkNode<T>();
    };

    SingleLinkList(const std::initializer_list<T> &init){
        head = new SingleLinkNode<T>();
        append(init);
    }

    ~SingleLinkList() {
        uint total = 0;
        SingleLinkNode<T> *tmp;
        while (head != nullptr) {
            tmp = head->next;
            delete head;
            total++;
            head = tmp;
        }
        std::cout << "Release " << total << " nodes." << std::endl;
    }

    void clear() override {
        SingleLinkNode<T> *tmp;
        while (head != nullptr) {
            tmp = head->next;
            delete head;
            head = tmp;
        }
        length = 0;
        head = new SingleLinkNode<T>();
    }

    bool isEmpty() override {
        return length == 0;
    }

    uint size() override {
        return length;
    }

    bool append(const T &src) override {
        SingleLinkNode<T> *temp = new SingleLinkNode<T>(src);
        SingleLinkNode<T> *tmp = head;
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
        SingleLinkNode<T> *tmp = findPtr(pos);
        SingleLinkNode<T> *temp = new SingleLinkNode<T>(src);
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
        SingleLinkNode<T> *temp = findPtr(pos);
        SingleLinkNode<T> *target = temp->next;
        temp->next = target->next;
        delete target;
        length--;
        return true;
    }

    bool remove(uint start, uint end) override {
        if (start > end) return false;
        if (start == end) return remove(start);
        if (end >= length) {
            SingleLinkNode<T> *startPtr = findPtr(start);
            SingleLinkNode<T> *temp = startPtr->next;
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
        SingleLinkNode<T> *startPtr = findPtr(start);
        SingleLinkNode<T> *endPtr = findPtr(end);
        SingleLinkNode<T> *temp = startPtr->next;
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
        SingleLinkNode<T> *temp = head->next;
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
        SingleLinkNode<T> *startPtr = findPtr(start)->next;
        SingleLinkNode<T> *endPtr = findPtr(end);
        while (startPtr != endPtr->next){
            opt(startPtr->data);
            startPtr = startPtr->next;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const SingleLinkList &list) {
        os << "SingleLinkList Length: " << list.length << std::endl
            << "Content: ";
        SingleLinkNode<T> *temp = list.head->next;
        while (temp != nullptr){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
        return os;
    }

private:
    SingleLinkNode<T> *head;
    uint length = 0;

    SingleLinkNode<T> *findPtr(uint pos){
        uint total = 0;
        SingleLinkNode<T> *prev = head;
        SingleLinkNode<T> *temp = head->next;
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
