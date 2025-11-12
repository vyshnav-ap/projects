#include<iostream>
using namespace std;
int main(){
    int x = 100;
    int & ref_x = x;
    cout << ref_x <<endl;
    ref_x =200;
    cout << ref_x <<endl;

    cout << &x <<endl;
    cout << &ref_x <<endl;
}