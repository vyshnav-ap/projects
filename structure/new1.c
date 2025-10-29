#include<stdio.h>
struct student{
    char name[25];
    int age;
    int roll;
    char gender;
}s1 = {"vyshnav",23,1,'M'};     // global variable
int main(){
        //struct student s1 = {"vyshnav",23,1,'M'};
        printf("Name: %s\n",s1.name);
        printf("age: %d\n",s1.age);
        printf("roll number: %d\n",s1.roll);
        printf("Gender: %c\n",s1.gender);

        return 0;

}