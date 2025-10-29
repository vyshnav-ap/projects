#include <stdio.h>

void positive_fibonacci(int, int, int, int);

int main()
{
    int limit;
    
    printf("Enter the limit : ");
    scanf("%d", &limit);
    
    positive_fibonacci(limit, 0, 1, 0);
    return 0;
}

void positive_fibonacci(int limit, int f, int s, int N){
    if(f <=limit){
        printf("%d ",f);
        N=f+s;
        f=s;
        s=N;
        
        positive_fibonacci(limit, f, s, N);
    }
    
}