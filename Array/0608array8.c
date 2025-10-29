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
   int cp[size];
    for(int i=0;i<size;i++){
        cp[i]=arr[i];
        printf("%d ",cp[i]);
        }

}


