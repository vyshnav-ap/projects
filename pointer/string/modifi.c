#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* constant_to_modifiable(char *);
int main(){
    char* str = constant_to_modifiable("hello");
    str[0]='s';
    puts(str);
    return 0;
}
char* constant_to_modifiable(char * str){
    char* new = malloc(strlen(str)+1);
    strcpy(new,str);
    return new;
} 