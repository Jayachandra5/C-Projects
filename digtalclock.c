#include<lpc21xx.h>

 #include"lcd4bit.h"


unsigned char flag=0;


void rtc_int(void)__irq{

ILR = 0X01;

flag = 1;

VICVectAddr = 0X00000000;

}



void init_rtc(){

ILR = 0X01;

CCR  = 0X13;

CCR =  0X11;

CIIR = 0X01;

SEC = 0X00;

HOUR =0X00;

MIN = 0X00;

VICIntEnable = 0x00002000;

VICVectCntl0 = 0x0000002D;

VICVectAddr0 = (unsigned)rtc_int;

}



int main(void){

init_lcd(); 

init_rtc();

while(1){

if(flag){

lcd_command(0x80);

flag=0;

lcd_data(HOUR/10 + '0');

lcd_data(HOUR%10 + '0'); 

lcd_data(':') ;

lcd_data(MIN/10 + '0');

lcd_data(MIN%10 + '0');

lcd_data(':') ;

lcd_data(SEC/10 + '0');

lcd_data(SEC%10 + '0');

}

  }

}
