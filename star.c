#include<stdio.h>
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int num=i;
        for(int j=1;j<=n;j++){
            printf(" %d",num);
            num=num+j;
            
        }
        printf("\n");
    }
}