#include <stdio.h>
int main(){
    int a,b,c;
    printf("enter the 3 number: ");
    scanf("%d %d %d",&a,&b,&c);
    if((a<b && b<c)||(a>b && b>c)){
        printf("middle character is %d",b);

    }
    else if((a>b && b<c)||(a>b && b>c)){
        printf("middle character is %d",a);
    }
    //else if((a<b && b>c)||(a>b && b<c)){
        //printf("middle character is %d",c);
    //}
    else{
        printf("middle character is %d",c);
    }
}