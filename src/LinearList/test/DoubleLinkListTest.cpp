#include "DoubleLinkList.h"

using namespace std;

int main() {
#if _WIN32 || WIN32 || WIN64
    system("chcp 65001");
#endif
    // 初始化链表
    DoubleLinkList<int> doubleLinkList{1, 2, 3, 4};
    cout << "At begin: " << endl << doubleLinkList << endl;
    // 添加元素
    doubleLinkList.append({5, 6, 7});
    cout << "Add 5,6,7 to the end: " << endl << doubleLinkList << endl;
    // 插入元素
    doubleLinkList.insert({{2, 8},
                           {2, 9}});
    cout << "Insert 8,9 to index 2: " << endl << doubleLinkList << endl;
    // 删除元素
    doubleLinkList.remove(2, 5);
    cout << "Remove elements index between 2 and 5: " << endl << doubleLinkList << endl;
    // 获取元素值
    cout << "Element at index 2 is " << doubleLinkList[2] << endl;
    cout << "Element at index 3 is " << doubleLinkList.get(3) << endl;
    // 修改元素值
    doubleLinkList[2] = 10;
    cout << "Change element at index 2 to " << doubleLinkList[2] << endl;
    doubleLinkList.setValue(3, 12);
    cout << "Change element at index 3 to " << doubleLinkList[3] << endl;
    cout << doubleLinkList << endl;
    // 遍历测试
    cout << "Every element add 1: " << endl;
    doubleLinkList.forEach(0, doubleLinkList.size(), [](int &tmp) { tmp += 1; });
    cout << doubleLinkList << endl;
    // 查找测试
    cout << "Element 13 at index " << doubleLinkList.getPos(13) << endl;
    return 0;
}