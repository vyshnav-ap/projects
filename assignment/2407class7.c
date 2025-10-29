/*

Name:Vyshnav A P
Date:24/07/25
Description:find the middle of three number
Sample IP:1 2 3
Sample OP:The middle number is 2

*/


#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter the  three number: ");
    scanf("%d %d %d",&a,&b,&c);
    if(a>b){
        if(a<c){
            printf("the middle number is %d",a);
        }
    }
    else if(a<b){
        if(a>c){
            printf("the middle number is %d",a);
        }
    }
    /*else if(b>a){
        if(b<c){
            printf("the middle number is %d",b);
        }
    }
    else if(b<a){
        if(b>c){
            printf("the middle number is %d",b);
        }
    }
    else{
        printf("the middle number is %d",c);
    }*/
}