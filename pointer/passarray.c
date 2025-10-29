#include<stdio.h>
int main(){
    int size;
    printf("Enter the array size: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the array elements: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    print_array(arr,size);
    return 0;
}

void print_array(int Arr[],int size){
    for(int i=0;i<size;i++)
    printf("%d ",Arr[i]);
    printf("\n");
}