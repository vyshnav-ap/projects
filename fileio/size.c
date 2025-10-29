#include<stdio.h>

int main(){
    FILE *fptr =fopen("file.txt","r");
    if(fptr == NULL){
        printf("File open error\n");
        return 0;
    }
   fseek(fptr,0,SEEK_END);
   printf("Size -> %ld\n",ftell(fptr));
    return 0;
}