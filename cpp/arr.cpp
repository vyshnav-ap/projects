#include<iostream>
using namespace std;
int main(){
    int arr[4] = {1,0,3,12};
    for(int i=0; i<4; i++)
        cout << arr[i] << " ";
    cout << endl;

    int x =20;
    cout << "Address_x = " << &x << endl;
    return 0;

}