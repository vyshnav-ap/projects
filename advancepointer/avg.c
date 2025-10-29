#include<stdio.h>
#include<stdarg.h>
float Average(int count,...){
    va_list ap;
    va_start(ap,count);
    float avg = 0.0;
    for(int i=0;i<count;i++){
        avg +=va_arg(ap,int);
    }
    va_end(ap);
    return avg/count;
}
int main(){
    printf("Average = %f\n",Average(3,1,2,4));
}