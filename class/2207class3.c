#include<stdio.h>
int main(){
    int balance,amount,b;
    balance=10000;
    printf("enter the amount to withdraw: ");
    scanf("%d",&amount);
    if(amount<=10000){
    b=balance-amount;
    printf("the withdrawal amount is %d and the balace is %d",amount,b);
}
else{
    printf("the balance is low you can't withdraw the amount");
}

}