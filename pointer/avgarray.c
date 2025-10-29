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
    float avg= avg_array(arr,size);
    printf("avg=%f",avg);
    return 0;
}

void avg_array(int Arr[],int size){
    float avg=0;
    for(int i=0;i<size;i++)
        avg +=arr[i];
    return avg/size;
}