#include<stdio.h>


int main(){
    char src_data[] ={0x00,0x01,0xAB,0xCD,0x0A,0x11,0x09,0xAA};
    char ch = 'A';
    //int res = ch & ((1<<8)-1);
    //printf("%d",res);
    for(int i=0;i<8;i++){
    int clear = src_data[i] & (~1);
    //printf("%x ",clear);
    
    int bit = (ch >> (7-i))&1;
    int merged =clear | bit;
    printf("%hhx ",merged);
    }
}