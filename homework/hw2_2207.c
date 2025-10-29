#include<stdio.h>
int main(){
    int x,y;
    long long r=1;
    printf("enter the value of x and y: ");
    scanf("%d %d",&x,&y);
    for(int i=1;i<=y;i++){
        r *=x;
    }
    printf("%lld",r);
}