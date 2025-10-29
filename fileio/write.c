#include<stdio.h>

int main(){
    FILE *fptr =fopen("file.txt","w");
    if(fptr == NULL){
        printf("File open error\n");
        return 0;
    }
    char *str = "Bangluru,chennai,hyderabad";
    int i=0;
    while(str[i]){
        if(str[i] == ',')
            fputc('\n',fptr);
        else
            fputc(str[i],fptr);
        i++;
    }
    return 0;
}