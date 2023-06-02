#include <iostream>
#include "Array.h"
using namespace std;

int main(){
    // 创建数组
    Array<int> array{1, 2, 3, 4};
    cout << "At begin: " << endl << array;
    // 插入数据
    array.insert(2, 5);
    array.insert({{2, 6}, {2, 7}});
    cout << "Insert 5,6,7 in index 2: " << endl << array;
    // 移除数据
    array.remove(1);
    cout << "Remove element in index 1: " << endl << array;
    // 测试自动扩容
    array.append({1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1});
    cout << "Add a lot of numbers: " << endl << array;
    // 测试自动缩容
    array.remove(0, 14);
    cout << "Remove a lot of numbers: " << endl << array;
    // 测试读取数据
    cout << "Element at index 1: " << array[1] << endl;
    cout << "Element at index 2: " << array.find(2) << endl;
    // 测试修改数据
    array[3] = 10;
    cout << "Change element at index 3 to 10: " << array[3] << endl;
    array.setValue(4, 12);
    cout << "Change element at index 4 to 12: " << array[4] << endl;
    cout << array;
    // 测试遍历处理
    cout << "Every element add 1: " << endl;
    array.forEach(0, array.size(), [](int &tmp){ tmp += 1;});
    cout << array;
    // 测试查找元素
    cout << "Element 13 at index: " << array.getPos(13) << endl;
    return 0;
}
