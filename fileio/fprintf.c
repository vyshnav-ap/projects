#include<stdio.h>

int main(){
    FILE *fptr =fopen("file.txt","r");
    if(fptr == NULL){
        printf("File open error\n");
        return 0;
    }
    char name[20];
    int ID;
    fscanf(fptr,"%[^,],%d\n",name,&ID);
    printf("Name:%s\n",name);
    printf("ID:%d\n",ID);
    return 0;
}