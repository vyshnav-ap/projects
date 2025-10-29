#include<stdio.h>
int main(){
    int num;
    printf("enter the number:");
    scanf("%d",&num);
    if(num %3 ==0 && num %7 ==0){
        printf("the given number is divisible by 3 and 7");
    }
    else{
        printf("the number is not divisible by 3 and 7");
    }
}