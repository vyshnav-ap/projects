#include<iostream>
using namespace std;
int main(){
    int *p = new int(30);
    cout << *p << endl;
    char* c = new char ('A');
    cout << *c <<endl;
    int *arr =new int[5]{1,2,3,4,5};
    for(int i=0;i<5;i++)
        cout << arr[i] << " ";
    cout << endl;
    char *str = new char[20]{"vyshnav"};
    cout << str <<endl;
    delete p;
    delete c;
    delete []arr;
    delete []str;
}