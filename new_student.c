#include<stdio.h>
int main(){
    int a,b,c,mark,avg;
    printf("input mark of 3 subject :");
    scanf("%d %d %d",&a,&b,&c);
    if (a>=40 && b>=40 && c>=40){
        mark=a+b+c;
        avg=mark/3;
        if(avg>=75){
            printf("Distinction");
        }
        else if(avg>=60){
            printf("first class");
        }
        else{
            printf("pass");
        }
    }
    else{
        printf("fail");
    }
    

    
}