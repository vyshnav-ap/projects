#include<stdio.h>
#include<limits.h>
int main(){
    //int arr[2][3] = {{1,2,3},{4,5,6}};
    int row,col,r;
    printf("Enter the row: ");
    scanf("%d",&row);
    printf("Enter the col: ");
    scanf("%d",&col);
    printf("enter the elements : \n");
    int large = INT_MIN;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
           scanf("%d",&arr[i][j]);
           if(large < arr[i][j])
            large=arr[i][j];
        }
    }
        printf("\n");
}
    