#ifndef DATA_STRUCTURE_LIST_H
#define DATA_STRUCTURE_LIST_H

#include "Definition.h"

template<typename T>
class List {
public:
    // 清空线性表
    virtual void clear() = 0;

    // 判断线性表是否为空
    virtual bool isEmpty() = 0;

    // 获取线性表长度
    virtual uint size() = 0;

    // 向线性表末尾添加元素
    virtual bool append(const T &src) = 0;

    // 批量添加元素
    virtual bool append(const std::initializer_list<T> &src) = 0;

    // 向线性表中间插入元素
    virtual bool insert(uint pos, const T &src) = 0;

    // 批量插入元素
    virtual bool insert(const std::initializer_list<std::pair<uint, T>> &src) = 0;

    // 移除某一元素
    virtual bool remove(uint pos) = 0;

    // 批量移除元素
    virtual bool remove(uint start, uint end) = 0;

    // 获取某一元素
    virtual T &find(uint pos) = 0;

    // 设置某一元素
    virtual bool setValue(uint pos, const T &src) = 0;

    // 获取某个元素的下标
    virtual int getPos(const T &src) = 0;

    // 重载[]运算符
    virtual T &operator[](int pos) = 0;

    // 从start下标到end下标依次做opt处理
    virtual void forEach(uint start, uint end, void (*opt)(T &)) = 0;
};

#endif
