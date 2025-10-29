#include<stdio.h>

void Reverse(char);

int main(){
    char str[30];
    printf("Enter the string: ");
    scanf("%[^\n]",str);
    printf("Before reversing:%s",str);
    Reverse(str);
    printf("After reversing:%s",str);
    return 0;

}
void Reverse(char* str){
    int l=0;
    while(str[l++]){
        l--;
    }
    for(int i=0;i<l/2;i++){
        char temp =str[i];
        str[i]=str[l-i-1];
        str[l-i-1]=temp;
    }
    
}