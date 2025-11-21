#include<iostream>
using namespace std;

void SWAP(int &ref1, int & ref2){
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}
int main(){
    int x,y;
    cout << "Enter  x and y : "; cin >> x >> y;
    SWAP(x,y); // call by reference
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}