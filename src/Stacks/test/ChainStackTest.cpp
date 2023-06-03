#include <iostream>
#include "ChainStack.h"

using namespace std;

int main() {
    // 初始化
    ChainStack<int> stack{1, 2, 3, 4, 5, 6};
    cout << "At Begin: " << endl << stack;
    // 自动扩容
    stack.push({7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17});
    cout << "Add 7 to 17 into stack: " << endl << stack;
    cout << "Take the top of the stack three times: " << endl << stack.pop() << " " << stack.pop() << " " << stack.pop() << endl;
    cout << stack << "Delete 8 elements: " << endl;
    // 自动缩容
    for (int i = 0; i < 8; ++i) {
        stack.pop();
    }
    cout << stack;
    return 0;
}