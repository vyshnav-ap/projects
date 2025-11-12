#include<iostream>
using namespace std;
int main(){
    string s = "ok";
    auto x = 10;
    auto ch = 'A';
    auto y = 2.34;
    auto str = "Hello";
    auto s1 =s;
    auto z = 'd' + 'k';
    cout << sizeof(x) << endl;
    cout << sizeof(ch) << endl;
    cout << sizeof(y) << endl;
    cout << sizeof(str) << endl;
    cout << sizeof(s1) << endl;
    cout << sizeof(z) << endl;
    return 0;

}