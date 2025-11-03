#include<stdio.h>
union U
{
    char data;
    strct S
    {
        unsigned char c1 : 4;
        unsigned char c2 : 4;
    }s;
}u;

int main(){
    printf("Enter 1 byte data(Hexa)\n",sizeof(u));
    scanf("%hhx",&u.data);
    u.s.c1 = u.s.c1+u.s.c2;
    u.s.c2 = u.s.c1-u.s.c2;
    u.s.c1 = u.s.c1-u.s.c2;
    printf("After swapping nibble : %hhx",&u.data);
}
