#include "ChainStack.h"

using namespace std;

int main() {
#if _WIN32 || WIN32 || WIN64
    system("chcp 65001");
#endif
    // 初始化
    ChainStack<int> stack{1, 2, 3, 4, 5, 6};
    cout << "At Begin: " << endl << stack << endl;
    // 自动扩容
    stack.push({7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17});
    cout << "Add 7 to 17 into stack: " << endl << stack << endl;
    cout << "Take the top of the stack three times: " << endl << stack.pop() << " " << stack.pop() << " " << stack.pop()
         << endl;
    cout << stack << endl << "Delete 8 elements: " << endl;
    // 自动缩容
    for (int i = 0; i < 8; ++i) {
        stack.pop();
    }
    cout << stack << endl;
    return 0;
}