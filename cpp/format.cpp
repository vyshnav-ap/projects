#include<iostream>
using namespace std;
int main(){
    cout <<sizeof('A') << endl;
    auto z = sizeof('A');

    cout << sizeof(z) << endl;
    return 0;
}