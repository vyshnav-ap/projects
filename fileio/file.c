#include<stdio.h>

int main(){
    FILE *fptr =fopen("file.txt","r");
    if(fptr == NULL){
        printf("File open error\n");
        return 0;
    }
    char ch;
    while((ch = fgetc(fptr))!= EOF){
        printf("%c",ch);
    }
    return 0;
}