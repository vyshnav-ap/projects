#include<stdio.h>
int main(){
    int size;
    printf("Enter the array size: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("odd elements in the array are: ");
    for(int i=0;i<size;i++){
        if(arr[i]%2 != 0){
            printf("%d ",arr[i]);
        }

    }

}
