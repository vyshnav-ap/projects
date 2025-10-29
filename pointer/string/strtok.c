#include<stdio.h>
//#include<string.h>


 void strrev(char str[],int len){
    char temp = str[i];
    str[i] = str[len-i-1];
    str[len-i-1] =  temp;
 }

    
int main(){
    char str[]="hello ok fine then!!";
    int i=0,count=0;
    char *temp = str;
    while(str[i]){
        if(str[i] != ' ' && str[i] != '\t'){
            count++;
    
        }
        if((str[i] == ' ' || str[i] == '\t')&&(str[i+1] != ' ' || str[i+1] != '\t')){
            strrev(temp,count);
            temp = &str[i+1];
            count =0;
        }
        i++;
    }
    if(str[i] == '\0')
    strrev(temp,count);
puts(str);
}

   