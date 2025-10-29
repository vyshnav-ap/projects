/* ######################################################

new hw 23/07/2025
Q)WAP to print direction based on the character E W N S

#########################################################*/

#include<stdio.h>
int main(){
    char direction;
    printf("enter the direction: ");
    scanf("%c",&direction);
    if(direction == 'N'||direction =='n'){
        printf("North");
    }
    else if(direction == 'S'||direction =='s'){
        printf("South");
    }
    else if(direction == 'E'||direction =='e'){
        printf("East");
    }
    else if(direction == 'W'||direction =='w'){
        printf("West");
    }
    else{
        printf("invalid entry");
    }
}
