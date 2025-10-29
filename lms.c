#include<stdio.h>
int main(){
    char name_letter;
    int pincode;
    float height;
    double latitude,longitude;
    printf("Enter first letter of your name: ");
    scanf("%c",&name_letter);
    printf("Enter your pincode:");
    scanf("%d",&pincode);
    printf("Enter your heoght in feet:");
    scanf("%f",&height);
    printf("Enter latitude & longitude of your address:");
    scanf("%lf %lf",&latitude,&longitude);
    printf("\nHere is what you have entered:\n");
    printf("First letter is Name:%c\n",name_letter);
    printf("Pincode:%d\n",pincode);
    printf("Height:%f\n",height);
    printf("Location:%lf %lf\n",latitude,longitude);
}