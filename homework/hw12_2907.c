#include<stdio.h>
int main(){
    int n,flag,i;
    printf("Enter the limit: ");
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        for (i = 2; i <= n; i++) {
        isPrime = 0; // Assume i is prime

        // Check for factors from 2 to sqrt(i)
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 1; // Not prime
                break;
            }
        }

        if (isPrime) {
        printf("%d",i);
        }
    

}
