#include<stdio.h>

int main(){
    int n,num;
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("Enter the number of bits to set: ");
    scanf("%d",&n);
    printf("%d",(num|((1<<n)-1)));

}