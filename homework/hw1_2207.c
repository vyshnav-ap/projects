#include<stdio.h>
int main(){
    int num,c;
    printf("enter the number");
    scanf("%d",&num);
    for(int i=1;i<=10;i++){
       // c=num*i;
        printf("%d x %d=%d\n",num,i,num*i);
    }


}