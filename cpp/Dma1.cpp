#include<iostream>
using namespace std;
int main(){
   string *str = new string("vyshnav");
   cout << *str <<endl;
   str ->at(0) = 'w';
   cout << *str << endl;
   cout <<"length = " << str->length() << endl;

   delete str;
    
   return 0;

}