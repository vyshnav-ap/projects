#include<stdio.h>
int main(){
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    int i=1;
label:
    //int i=i;                   //if(i<=n){
    printf("%d ",i);             // printf("%d,i++");
    i+=1;                        // goto label;
    if(i == n+1){                //}
    goto vy;
 }
goto label;
 vy:
 return 0;
}