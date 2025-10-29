#include<stdio.h>

int main(){
    int bits,num,pos;
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("Enter the number of bits to set: ");
    scanf("%d",&bits);
    printf("Enter the position to set: ");
    scanf("%d",&pos);
    int mask = ((1<<bits)-1)<<(pos-bits+1);
    printf("%d",mask);

}