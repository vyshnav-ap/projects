#include<stdio.h>

 char* my_strtok(char*str,char*delim){
    static char* ptr;
    if(str != NULL)
        ptr = str;
    static int i =0;
    int j=0;
    int start = i;
    while(ptr[i] !='\0'){
        j=0;
        while(delim[j] !='\0'){
            if(ptr[i] == delim[j]){
                ptr[i] ='\0';
                i++;
                return ptr+start;
            }
            else{
                j++;
            }
        }
        i++;
    }
    if(ptr[start] !='\0')
        return ptr+start;
    else
        return NULL;
    
}

 
int main(){
    char str[100],delim[10];
    printf("Enter the string : ");
    scanf("%[^\n]",str);
    printf("Enter the delimeter : ");
    scanf(" %s",delim);
    //my_strtok(str,delim);
   char* token = my_strtok(str, delim);
while (token != NULL) {
    printf("%s\n", token);
    token = my_strtok(NULL, delim);
};
}