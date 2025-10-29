#include<stdio.h>
int main(){
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i%3 == 0||i%5 == 0){
            continue;
        }
        printf("%d",i);
    }
}