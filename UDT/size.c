#include<stdio.h>
union U
{
    int i;
    //char ch;
    int j;
    char *ptr;
    char ch[10];
}u;

int main(){
    printf("size = %ld\n",sizeof(u));
    printf("A1 = %p\n",&u.i);
    printf("A2 = %p\n",&u.ch);
    printf("A3 = %p\n",&u.j);
    printf("A4 = %p\n",&u.ptr);
}
