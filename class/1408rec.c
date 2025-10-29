#include<stdio.h>
void pn(int n){
    if(n>0)
    pn(n-1);
    printf("%d",n);
    //pn(n--);
    //return 1;
}

int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    pn(n);
    return 0;
}
