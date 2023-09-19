#include "CircularlyLinkList.h"

using namespace std;

int main() {
#if _WIN32 || WIN32 || WIN64
    system("chcp 65001");
#endif
    // 初始化链表
    CircularlyLinkList<int> circularlyLinkList{1, 2, 3, 4};
    cout << "At begin: " << endl << circularlyLinkList << endl;
    // 添加元素
    circularlyLinkList.append({5, 6, 7});
    cout << "Add 5,6,7 to the end: " << endl << circularlyLinkList << endl;
    // 插入元素
    circularlyLinkList.insert({{2, 8},
                               {2, 9}});
    cout << "Insert 8,9 to index 2: " << endl << circularlyLinkList << endl;
    // 删除元素
    circularlyLinkList.remove(2, 5);
    cout << "Remove elements index between 2 and 5: " << endl << circularlyLinkList << endl;
    // 获取元素值
    cout << "Element at index 2 is " << circularlyLinkList[2] << endl;
    cout << "Element at index 3 is " << circularlyLinkList.get(3) << endl;
    // 修改元素值
    circularlyLinkList[2] = 10;
    cout << "Change element at index 2 to " << circularlyLinkList[2] << endl;
    circularlyLinkList.setValue(3, 12);
    cout << "Change element at index 3 to " << circularlyLinkList[3] << endl;
    cout << circularlyLinkList << endl;
    // 遍历测试
    cout << "Every element add 1: " << endl;
    circularlyLinkList.forEach(0, circularlyLinkList.size(), [](int &tmp) { tmp += 1; });
    cout << circularlyLinkList << endl;
    // 查找测试
    cout << "Element 13 at index " << circularlyLinkList.getPos(13) << endl;

    return 0;
}