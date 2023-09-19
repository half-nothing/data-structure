#include "StringMatching.h"
#include <iostream>
using namespace std;

int main(){
    String string("ABCABCDABCDEFG");
    String target("ABCD");
    cout << string;
    cout << target;
    cout << StringMatching::simple(string, target) << endl;
    cout << StringMatching::kmp(string, target) << endl;
    return 0;
}