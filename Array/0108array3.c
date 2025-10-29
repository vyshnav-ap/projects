#include<stdio.h>
int main(){
    int temp,size;
    printf("Enter the aize of array : ");
    scanf("%d",&size);
    printf("enter the array elements : ");
    int arr[size];  //array declaration
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
     printf("you have given:");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
        //printf("\n");
        }
    for(int i=0;i<size/2;i++){
        temp=arr[i];
        arr[i]=arr[size-i-1];
        arr[size-i-1]=temp;
       // printf("\nreverse array is %d",arr[i]);
    }
    printf("\nreverse array is");

    for(int i=0;i<size;i++){
        printf(" %d",arr[i]);
        }
        printf("\n");
    
}