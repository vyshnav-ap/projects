#include<stdio.h>
int main(){
    int size,count=0,count1=0;
    printf("Enter the array size: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the array elements: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<size;i++){
    if(arr[i]%2 == 0){
        count++;
    }
    else if(arr[i]%2 !=0){
        count1++;
    }
}
printf("Even count: %d\n",count);
printf("Odd count: %d",count1);
    
}