#include<stdio.h>
int main(){
    char ch;
    int b;
    printf("enter the character: ");
    scanf("%c",&ch);
    if (ch>='a' && ch<='z')
    {
        b=1;
    }
    else if(ch>='A' && ch<='Z'){
        b=2;

    }
    switch(b){
        case 1:printf("the character is lower case%c",ch);
        break;
        case 2:printf("the character is upper case%c",ch);
        break;
    
    default:
    printf("it is a special character %c",ch);
    }
}