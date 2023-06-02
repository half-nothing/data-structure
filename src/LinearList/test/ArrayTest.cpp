#include <iostream>
#include "Array.h"
using namespace std;

int main(){
    // 创建数组
    Array<int> arrayTest{1, 2, 3, 4};
    cout << "At begin: " << endl << arrayTest;
    // 插入数据
    arrayTest.insert(2, 5);
    arrayTest.insert({{2, 6}, {2, 7}});
    cout << "Insert 5,6,7 in index 2: " << endl << arrayTest;
    // 移除数据
    arrayTest.remove(1);
    cout << "Remove element in index 1: " << endl << arrayTest;
    // 测试自动扩容
    arrayTest.append({1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1});
    cout << "Add a lot of numbers: " << endl << arrayTest;
    // 测试自动缩容
    arrayTest.remove(0, 14);
    cout << "Remove a lot of numbers: " << endl << arrayTest;
    // 测试读取数据
    cout << "Element at index 1: " << arrayTest[1] << endl;
    cout << "Element at index 2: " << arrayTest.find(2) << endl;
    // 测试修改数据
    arrayTest[3] = 10;
    cout << "Change element at index 3 to 10: " << arrayTest[3] << endl;
    arrayTest.setValue(4, 12);
    cout << "Change element at index 4 to 12: " << arrayTest[4] << endl;
    cout << arrayTest;
    // 测试遍历处理
    cout << "Every element add 1: " << endl;
    arrayTest.forEach(0, arrayTest.size(), [](int &tmp){ tmp += 1;});
    cout << arrayTest;
    // 测试查找元素
    cout << "Element 13 at index: " << arrayTest.getPos(13) << endl;
    return 0;
}
