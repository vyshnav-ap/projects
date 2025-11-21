#include<iostream>
using namespace std;

class Animal{
    public:
   virtual  void sound(void){
    cout << "Animal make sound" << endl;
    }
};
class dog : public Animal{
    void sound(void){ // 
        cout << "bark" << endl;
    }
};

class cat : public Animal{
    void sound(void){
        cout << "meow" <<endl;
    }
};

int main(){
    Animal * A;
    dog d;
    A = &d;
    A ->sound();
    cat c;
    A = &c;
    A ->sound();
}