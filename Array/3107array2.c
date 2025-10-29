#include<stdio.h>
int main(){
    int size,n=0;
    printf("Enter the aize of array : ");
    scanf("%d",&size);
    printf("enter the array elements : ");
    int arr[size];  //array declaration
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
        n+=arr[i];
    }
    
    printf("avg is: %.2f\n",(float)n/size);


}