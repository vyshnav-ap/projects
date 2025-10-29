/* ######################################################

new hw 23/07/2025
Q)WAP to check the given character is uppercase ,lowercase,special character using "if condition"

#########################################################*/
#include<stdio.h>
int main(){
    char ch;
    printf("enter the character: ");
    scanf("%c",&ch);
    if(ch>='a' && ch <='z'){
        printf("entered character is in lowercase");
    }
    else if(ch>='A' && ch <='Z'){
        printf("entered character is in uppercase");
    }
    else {
        printf("it is a special character");
    }


}