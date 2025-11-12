#include<iostream>
using namespace std;
class rectangle{
    public:
    int length,width;
    rectangle(){
        length = width =0;
    }
    rectangle (int l,int w){
        length = l;
        width = w;

    }
    rectnagle(rectangle & other){
        length = other.length;
        width = other.width;

    }
    int get_area(){
        return 2*(length+width);
    }
    void print_dim(){
        cout << "length = " << length <<endl;
        cout <<"width = " << width << endl;
    }
};
int main(){
    rectangle r1,r2(4,3);
    rectangle r3(r2);
    r3.print_dim();
    // cout << " " << <<endl;
}