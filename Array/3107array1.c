#include<stdio.h>
int main(){
    int size;
    printf("Enter the aize of array : ");
    scanf("%d",&size);
    printf("enter the array elements : ");
    int arr[size];  //array declaration
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("you have given:");
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
        printf("\n");

}