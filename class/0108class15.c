#include<stdio.h>
int main(){
    int n,r,rev=0;
    printf("Enter the number: ");
    scanf("%d",&n);
    int a=n;
    for(;n>=1;n=n/10){
        r=n%10;
        rev=rev*10+r;
        printf("\n%d",rev);
    }
    if(a == rev){
        printf("the number is palindrome");
    }
    else{
        printf("not a palindrome");
    }
}