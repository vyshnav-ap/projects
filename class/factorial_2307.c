#include<stdio.h>
int main(){
    int num;
    printf("enter the number: ");
    scanf("%d",&num);
    if(num<0){
        printf("invalid entry,give a value (>0)!!\n");
    }
    unsigned long int fact=1;
        while(num){
            fact=fact*num;
            num--;}
    printf("factorial is %ld",fact);
    }
