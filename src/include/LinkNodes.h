#ifndef DATA_STRUCTURE_LINK_NODES_H
#define DATA_STRUCTURE_LINK_NODES_H

template<typename T>
struct SingleLinkNode {
    SingleLinkNode *next{nullptr};
    T data;

    SingleLinkNode() = default;

    explicit SingleLinkNode(const T &data) : data(data) {}
};

template<typename T>
struct DoubleLinkNode {
    DoubleLinkNode *prev{nullptr};
    DoubleLinkNode *next{nullptr};
    T data{};

    DoubleLinkNode() = default;

    explicit DoubleLinkNode(const T &src) : data(src) {}
};

#endif
