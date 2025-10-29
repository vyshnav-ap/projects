#include<stdio.h>

void sum(char);

int main(){
    char str[30];
    printf("Enter the mobile number: ");
    scanf("%[^\n]",str);
    Reverse(str);
    printf("sum of digits:%s",str);
    return 0;
}
void sum(char* str){
    for(int i=0;i<10;i++){
        str[i]+=str[i];
    }
}