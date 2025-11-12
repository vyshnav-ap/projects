#include<iostream>
using namespace std;

void SWAP(int &ref1, int & ref2){
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}
void SWAP_str(string &ref1, string & ref2){
    string temp =ref1;
    ref1 =ref2;
    ref2 = temp;
}
int main(){
    string s1,s2;
    cout << "Enter  s1 : ";getline(cin,s1);
    cout << "Enter  s2 : ";getline(cin,s2);
    SWAP_str(s1,s2); // call by reference
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    return 0;
}