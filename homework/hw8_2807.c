#include<stdio.h>
int main(){
   for(int i=1;i<=4;i++){  //for creating rows
    for(int j=1;j<=4-i;j++){ // for spaces
        printf(" ");
    }
    for(int k=1;k<=i;k++){  //for number
        printf("%d",k);
    }
        
    printf("\n");
}
}
