#include<stdio.h>
int sum_digits(int,int);
int main(){
    int num;
    printf("enter the number: ");
    scanf("%d",&num);
    int sum = sum_digits(num,0);
    printf("sum of digits = %d\n",sum);
    return 0;

}
int sum_digits(int num,int sum){
    if(num){
        sum += (num%10);
        sum_digits(num/10,sum);
    }
    else{
        return sum;
    }
}
