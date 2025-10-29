#include<stdio.h>
struct student{
    int i;
    char ch;

};
void fun(struct student s_new){
    printf("-> %d\n",s_new.i);
    printf("-> %c\n",s_new.ch);
}
int main(){
    struct student s1={100,'A'};
    fun(s1); //pass by value
    return 0;
}