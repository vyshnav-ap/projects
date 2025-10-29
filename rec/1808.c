#include<stdio.h>
int main(){
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    ret = int get_no_of_digit(num);
     printf("no of digits = %d",ret);

}
int get_no_of_digit(int num,int count){
    num=num/10;
    count++;
    if(num != 0){
        return get_no_of_digit(num,count)+1;
    }
    else{
        return 1;
    }
}