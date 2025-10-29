#include<stdio.h>
int main(){
    int time,speed;
    char ped,light; 
    printf("input color of traffic :");
    scanf("%c",&light);
    if (light == 'r'){
        printf("what is the time in sec :\n");
        scanf("%d",&time);
        if(time>30){
            printf("jumping red signal");
        }
        else{
            printf("wait");
        }
    }
    else if (light == 'y'){
        printf("speed of car :");
        scanf("%d",&speed);

        if(speed>40){
            printf("slow down!");
        }
        
    }
    else if (light =='g'){
        printf("if pedestrian is crossing :");
        scanf(" %c",&ped);
        if(ped == 'y'){
            printf("wait");
        }
        else{
            printf("Go");
        }
    }
}


