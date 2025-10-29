#include<stdio.h>
int main(){
    
    for(int i=5;i>=1;i--){
        for(int j=i;j<=5;j++){
            printf(" %d",j%2); //printf(" %d",!(i+j)%2);
        }
        printf("\n");
    }
}