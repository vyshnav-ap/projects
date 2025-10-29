#include<stdio.h>
#include<stdlib.h>
struct car
{
    char name[20];
    int price;
    int mileage;
};
int main(){
    struct car*c = malloc(2*sizeof(struct car));
    strcpy(c[0].name,"maruti");
    c[0].price = 80000;
    c[0].mileage = 25;

    printf("Name : %s\n",c[0].name);
    printf("Name : %d\n",c[0].price);
    printf("Name : %d\n",c[0].mileage);
    free(c);
    return 0;
}