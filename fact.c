#include<stdio.h>
int main(){
    int num,c;
    printf("enter the number for factorial:");
    scanf("%d",&num);
    long int fact=1;
    //for(;num;num--){
      //  fact=fact*num;
     unsigned long int fact=1;
        while(num){
            fact=fact*num;
            num--;}
    printf("factorial is %ld",fact);    
}