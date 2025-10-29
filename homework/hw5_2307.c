/* ######################################################

new hw 23/07/2025
Q)WAP to print direction based on the character E W N S

#########################################################*/

#include<stdio.h>
int main(){
    char direction;
    printf("enter the direction: ");
    scanf("%c",&direction);
    switch(direction){
        case 'N':
        case 'n':
        printf("North\n");
        break;
        case 'W':
        case 'w':
        printf("West\n");
        break;
        case 'S':
        case 's':
        printf("south\n");
        break;
        case 'E':
        case 'e':
        printf("East\n");
        break;
        default:
        printf("invalid entry\n");
    }
}