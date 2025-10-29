#include<stdio.h>
#include<string.h>
int main(){
    FILE *fptr =fopen("file.txt","r");
    if(fptr == NULL){
        printf("File open error\n");
        return 0;
    }
    char str[100],temp[100];
    int l=0;
    while(!feof(fptr)){
        fscanf(fptr,"%[^\n]\n",temp);
        if(1<strlen(temp)){
            l = strlen(temp);
            strcpy(str,temp);
        }
    }
    
   printf("longest line: \n%s\n",str);

    return 0;
}