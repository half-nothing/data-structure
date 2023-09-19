#ifndef DATA_STRUCTURE_STRING_MATCHING_H
#define DATA_STRUCTURE_STRING_MATCHING_H

#include "String.h"

class StringMatching {
public:
    static int simple(String &string, String &target) {
        int i = 0, j = 0;

        while (i < string.size() && j < target.size()) {
            if (string[i] == target[j]) {
                i++;
                j++;
            } else {
                i = i - j + 1;
                j = 0;
            }
        }

        if (j == target.size()) {
            return i - j;
        }
        return -1;
    };

    static int kmp(String &string, String &target) {
        int next[string.size()];
        getNext(string, next);
        int i = 0, j = 0;

        while (i < string.size() && j < target.size()) {
            if (j == -1 || string[i] == target[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        if (j == target.size()) {
            return i - j;
        }

        return -1;
    }

private:
    static void getNext(String &string, int *next) {
        int i = 0, j = -1;
        next[0] = -1;

        while (i < string.size() - 1) {
            if (j == -1 || string[i] == string[j]) {
                i++;
                j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
    }
};

#endif
