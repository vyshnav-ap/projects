#include<stdio.h>

int main(){
    int pos,num;
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("Enter the position to check: ");
    scanf("%d",&pos);
    int mask = (1<<pos);
    int ret=(num &mask);
    if(ret){
        printf("set bit");
    }
    else{
    printf("not set");
    }

}