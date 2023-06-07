#include "ChainQueue.h"

using namespace std;

int main() {
    // 初始化
    ChainQueue<int> queue{1, 2, 3, 4, 5, 6};
    cout << "At Begin: " << endl << queue;
    // 自动扩容
    queue.push({7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17});
    cout << "Add 7 to 17 into queue: " << endl << queue;
    cout << "Take the top of the queue three times: " << endl << queue.pop() << " " << queue.pop() << " " << queue.pop() << endl;
    cout << queue << "Delete 8 elements: " << endl;
    // 自动缩容
    for (int i = 0; i < 8; ++i) {
        queue.pop();
    }
    cout << queue;
    return 0;
}