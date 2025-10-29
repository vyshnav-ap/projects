#include<stdio.h>
int main(){
    int size;
    printf("Enter the array size: ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("odd elements are:");
    for(int i=1;i<size;i++){
        printf("%d ",arr[i]);
        i+=1;
    }
}
