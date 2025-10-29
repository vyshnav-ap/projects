#include<stdio.h>
#include<stdarg.h>
#include<string.h>
char *long_string(int count,...){
    va_list ap;
    va_start(ap,count);
    char *str =NULL;
    int len = 0;
    for(int i=0;i<count;i++){
        char *str1 = va_arg(ap,char *);
        int l1 = strlen(str1);
        if(len < l1){
            len = l1;
            str = str1;
        }
    }
    va_end(ap);
    return str;
}
int main(){
    printf("longest = %s\n",long_string(3,"ok","hello","fine"));
}