#include<stdio.h>
int main(){
    int n,r,rev=0,l,f;
    printf("Enter the number: ");
    scanf("%d",&n);
    int a=n;
    for(;n>=1;n=n/10){
        r=n%10;
        rev=rev*10+r;
    }
    l=a%10;
    f=rev%10;
    printf("last digit is %d\n",a%10);
    printf("first digit is %d\n",rev%10);
    printf("%d\n",a/10+f);
    printf("%d\n",rev/10+l);
}