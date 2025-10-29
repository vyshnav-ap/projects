#include<stdio.h>
struct student{
    char name[25];
    int roll;
    int maths;
    int physics;
    int chemistry;
    
};//s1 = {"vyshnav",23,1,'M'};     // global variable
int main(){
        int n,name,roll,maths,physics,chemistry;
       
        printf("Enter the number of student: ");
        scanf("%d",&n);
         struct student s[n];
        for(int i=0;i< n;i++){
            printf("Enter details for student %d\n", i+1);
            printf("name: ");scanf(" %[^\n]",s[i].name);
            printf("roll: ");scanf("%d",&s[i].roll);
            printf("maths: ");scanf("%d",&s[i].maths);
            printf("physics: ");scanf("%d",&s[i].physics);
            printf("chemistry: ");scanf("%d",&s[i].chemistry);
    
        }
       // struct student s1 = {name,roll,maths,physics,chemistry};
        printf("s.no\tName\tmaths\tphysics\tchemistry\taverage\n");
        printf("-------------------------------------------------------------\n");
        float avg = 0.0;
        for(int i=0;i < n;i++){
            avg = (s[i].maths + s[i].physics + s[i].chemistry)/n;
        printf("%d\t%s\t%d\t%d\t%d\t%.2f\n",i+1,s[i].name,s[i].maths,s[i].physics,s[i].chemistry,avg);
        }
        return 0;

}