#include "String.h"
#include "iostream"

using namespace std;

int main() {
#if _WIN32 || WIN32 || WIN64
    system("chcp 65001");
#endif
    String string1("Test");
    String string2 = String('T', 10);
    cout << string1;
    cout << string2;
    string1.append(" Test");
    cout << string1;
    string1.append(string2);
    cout << string1;
    string1.replace('T', 'A');
    cout << string1;
    string1.remove(1, 8);
    cout << string1;
    cout << string1.c_str() << endl;
    string1.clear();
    cout << string1;
    return 0;
}
