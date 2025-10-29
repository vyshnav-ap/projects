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
    rep_array(arr,size);
    //printf("a",avg);
    return 0;
}

void rep_array(int Arr[],int size){
    int flag=0;
    for(int i=0;i<size;i++)
       for(int j=0;1<=j;j++){
        if(Arr[i]==Arr[j]){
            flag++;
        }
        else{
        printf("%d",Arr[i]);
       }
    }
    //return avg/size;
}