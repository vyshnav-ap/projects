#include<stdio.h>
int factorial(int);
int main(){
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    if(num < 0){
        printf("Invalid entry\n");
        return 0;
    }
    unsigned long long int res = factorial(num);
    printf("res = %lld\n",res);
    return 0;
}
unsigned long long int factorial(int num){
    unsigned long long int fact=1;
    while(num){
        fact*=num;
        num--;
    }
    return fact;
}