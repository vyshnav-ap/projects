#include<iostream>
using namespace std;
struct A
{
    int x;
    void fun(){
        cout << "Welcome x = " << x << endl;

    }
};
int main(){
    A obj;
    obj.x = 100;
    obj.fun();
}