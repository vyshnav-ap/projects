#include<iostrem>
using namespace std;



class base{
    public:
    int x,y;
    Base(int x,int y){
       this ->x = x;
       this ->y = y;
    }
};
class child:public Base{
    public:
    int z;
    child(int x1,int y1,int z1) : Base(x1,y1){
        z=z1;
    }
}