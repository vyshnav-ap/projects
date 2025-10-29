#include<stdio.h>
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int k=n;k>=1;k--){
            printf("%d",k);
        }
        for(int j=n;j>=n-j;j--){
            printf(" ");
        }
        
    }

}