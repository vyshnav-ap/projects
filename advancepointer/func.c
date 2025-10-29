#include<stdio.h>
#include<stdlib.h>

int asc(const void *a,const void *b);
int dsc(const void *a,const void *b);


int main(){
    int arr[7]={1,2,3,7,5,6,4};
    qsort(arr,7,sizeof(int),asc);
    for(int i=0;i<7;i++){
    printf("%d ",arr[i]);
    }
}
int asc(const void *a,const void *b){
    return (*(int*)a - *(int*)b);
}
int dsc(const void *a,const void *b){
    return (*(int*)b - *(int*)a);
}