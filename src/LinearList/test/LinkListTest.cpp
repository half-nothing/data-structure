#include <iostream>
#include "LinkList.h"
using namespace std;

int main() {
    // 初始化链表
    LinkList<int> linkListTest{1, 2, 3, 4};
    cout << "At begin: " << endl << linkListTest;
    // 添加元素
    linkListTest.append({5, 6, 7});
    cout << "Add 5,6,7 to the end: " << endl << linkListTest;
    // 插入元素
    linkListTest.insert({{2, 8}, {2, 9}});
    cout << "Insert 8,9 to index 2: " << endl << linkListTest;
    // 删除元素
    linkListTest.remove(2, 5);
    cout << "Remove elements index between 2 and 5: " << endl << linkListTest;
    // 获取元素值
    cout << "Element at index 2 is " << linkListTest[2] << endl;
    cout << "Element at index 3 is " << linkListTest.find(3) << endl;
    // 修改元素值
    linkListTest[2] = 10;
    cout << "Change element at index 2 to " << linkListTest[2] << endl;
    linkListTest.setValue(3, 12);
    cout << "Change element at index 3 to " << linkListTest[3] << endl;
    cout << linkListTest;
    // 遍历测试
    cout << "Every element add 1: " << endl;
    linkListTest.forEach(0, linkListTest.size(), [](int &tmp){tmp += 1;});
    cout << linkListTest;
    // 查找测试
    cout << "Element 13 at index " << linkListTest.getPos(13) << endl;
    return 0;
}