#ifndef DATA_STRUCTURE_STRING_BASE_H
#define DATA_STRUCTURE_STRING_BASE_H

#include "include.h"

class StringBase {
public:
    virtual void append(char src) = 0;

    virtual void append(const char *src) = 0;

    virtual void insert(uint pos, char src) = 0;

    virtual void insert(uint pos, const char *src) = 0;

    virtual void replace(char src, char tar) = 0;

    virtual void remove(uint start, uint end) = 0;

    virtual void clear() = 0;

    virtual char *c_str() = 0;

    virtual uint size() = 0;
};


#endif
