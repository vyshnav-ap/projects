#include<stdio.h>
int main(){
    int n,num;
    scanf("%d",&n);
    while(num=num/10){
        n=num%10;
        n+=n*n*n;

    }
    if(num == n){
        printf("the number is armstrong");
    }
    else{
        printf("not an armstrong number");
    }
}