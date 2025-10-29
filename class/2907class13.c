#include<stdio.h>
#include<math.h>
int main(){
    int n,flag=0;
    printf("Enter the number:");
    scanf("%d",&n);
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            flag=1;
            printf("Not prime\n");
            break;
        }
    }
    if(flag == 0){
        printf("number is prime\n");
    }

}