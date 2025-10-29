#include<stdio.h>

int main(){
    //int arr[2][3] = {{1,2,3},{4,5,6}};
    int row,col;
    printf("Enter the row: ");
    scanf("%d",&row);
    printf("Enter the col: ");
    scanf("%d",&col);
    int arr[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
           scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("| ");
            printf("%d",arr[i][j]);
           // printf(" ");
        }
        printf("|\n");
    }
}