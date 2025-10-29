#include<stdio.h>
void p_binary(unsigned int);
int main(){
    int num;
    printf("enter the number: ");
    scanf("%d",&num);
    if(num == 0)
        printf("0");
    else
        p_binary(num);
    printf("\n");
    return 0;
}
void p_binary(unsigned int num){
    if(num){
        p_binary(num/2);
        printf("%d",num%2);
    }
    
    

       //return num = num%2;
       // printf("%d",res);
}
