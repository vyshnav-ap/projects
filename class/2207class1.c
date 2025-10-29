#include<stdio.h>
int main(){
    int num;
    printf("enter the number :");
    scanf("%d",&num);
    if(num %5 == 0){
        printf("the given number is divisible by 5");
    
    }
    else{
        printf("the given number is not divisible by 5");
    }
    
}