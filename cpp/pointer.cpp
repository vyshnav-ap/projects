#include<iostream>
using namespace std;
class polygon{
    protected:
    int width,
    height;
    public:
    void set_values(int a,int b){
        width =a;height=b;
    }
};
class rectangle:public polygon{
    public:
    int area(){
        return width*height;
    }
};
class triangle:public polygon{
    public:
    int area(){
        return width*height/2;
    }
};

int main()
{
    rectangle rect;
    triangle trgl;

}