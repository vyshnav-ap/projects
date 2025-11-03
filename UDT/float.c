#include<stdio.h>
union U
{
    float f;
    int i;

}u;

int main(){
    printf("Enter float vlaue",sizeof(u));
    scanf("%hhx",&u.data);
    u.s.c1 = u.s.c1+u.s.c2;
    u.s.c2 = u.s.c1-u.s.c2;
    u.s.c1 = u.s.c1-u.s.c2;
    printf("After swapping nibble : %hhx",&u.data);
}
