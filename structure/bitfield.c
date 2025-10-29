#include<stdio.h>
struct s{
    unsigned char FL_1 :1;
    unsigned char FL_2 :1;
    unsigned char FL_3 :1;
    unsigned char FL_4 :1;
    unsigned char FL_5 :1;
    unsigned char FL_6 :1;
    unsigned char FL_7 :1;
    unsigned char FL_8 :1;
}B;
int main(){
    printf("size : %ld\n",sizeof(B));
    B.FL_1 = 1;
    printf("flag1 value : %d\n",B.FL_1);
    return 0;
}