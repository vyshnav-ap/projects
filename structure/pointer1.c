#include<stdio.h>
struct student{
    int i;
    char ch;

};
void fun(struct student * sptr){
    printf("-> %d\n",sptr->i);
    printf("-> %c\n",sptr->ch);
    sptr->ch = 'B';
}
int main(){
    struct student s1={100,'A'};
    fun(&s1); //pass by reference
    printf("->> %c\n",s1.ch);
    return 0;
}