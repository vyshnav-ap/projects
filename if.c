#include<stdio.h>
int main(){
    int mark;
    printf("whats ur mark:");
    scanf(" %d",&mark);
    if (mark>=90 && mark<=100){
        printf("ur grade is A+");
    }
    else if(mark>=80 && mark<=90){
        printf("ur grade is A");
    }
    else if(mark>=70)
    {
        printf("ur grade is B+ ");
    }
    else if(mark>=100){
        printf("invalid");
    }
    else{
        printf("failed");
    }
}