#include<iostream>
using namespace std;
int main(){
    string str;
    cout << "Enter string : ";
    // cin >> str;  //only one word 
    getline(cin,str);   //for multiple word

    cout << "str = " << str << endl;
    return 0;


}