#include "SingleLinkList.h"

using namespace std;

int main() {
#if _WIN32 || WIN32 || WIN64
    system("chcp 65001");
#endif
    // 初始化链表
    SingleLinkList<int> singleLinkList{1, 2, 3, 4};
    cout << "At begin: " << endl << singleLinkList << endl;
    // 添加元素
    singleLinkList.append({5, 6, 7});
    cout << "Add 5,6,7 to the end: " << endl << singleLinkList << endl;
    // 插入元素
    singleLinkList.insert({{2, 8},
                           {2, 9}});
    cout << "Insert 8,9 to index 2: " << endl << singleLinkList << endl;
    // 删除元素
    singleLinkList.remove(2, 5);
    cout << "Remove elements index between 2 and 5: " << endl << singleLinkList << endl;
    // 获取元素值
    cout << "Element at index 2 is " << singleLinkList[2] << endl;
    cout << "Element at index 3 is " << singleLinkList.get(3) << endl;
    // 修改元素值
    singleLinkList[2] = 10;
    cout << "Change element at index 2 to " << singleLinkList[2] << endl;
    singleLinkList.setValue(3, 12);
    cout << "Change element at index 3 to " << singleLinkList[3] << endl;
    cout << singleLinkList << endl;
    // 遍历测试
    cout << "Every element add 1: " << endl;
    singleLinkList.forEach(0, singleLinkList.size(), [](int &tmp) { tmp += 1; });
    cout << singleLinkList << endl;
    // 查找测试
    cout << "Element 13 at index " << singleLinkList.getPos(13) << endl;
    return 0;
}