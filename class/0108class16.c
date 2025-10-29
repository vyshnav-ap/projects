#include<stdio.h>
int main(){
    int n,r,rev=0,d;
    printf("Enter the number: ");
    scanf("%d",&n);
    int a=n;
    for(;n>=1;n=n/10){
        r=n%10;
        rev=rev*10+r;
    }
    //printf("%d",rev);
    printf("last digit is %d\n",a%10);
    printf("first digit is %d",rev%10);
    
}