#include<iostream>
using namespace std;

class Data{
    public:
    
}
Data(){
    name ="none";
    ID = 0;
    cout << 
}
Data(string name_new,int i){
    name =name_new;
    ID =i;
    cout << "para constr" << endl;
}
Data(Data & other) // copy [must use PBR]
{
    name = other.name;
    ID = other.ID;
    cout << "copy constr" << endl;
}
void print(){
    cout << "Name : " << name << endl;
    cout << "ID : " << ID <<endl;
};

int main(){
    Data per1;
    Data per2("Rahul",1001);
    Data per3(per2);
    per1.print();
    per2.print();
    per3.print();
    
}