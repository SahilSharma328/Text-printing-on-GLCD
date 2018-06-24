/*
 * File:   GLCD_1.c
 * Author: Sahil
 *
 * Created on 5 January, 2018, 9:46 AM
 */


#include<xc.h>
#define _XTAL_FREQ 16000000
#define RS PORTCbits.RC2
#define EN PORTCbits.RC3

void cmd(unsigned char command)
{
    PORTD=command;
	RS=0;
	EN=1;
	__delay_us(20);
	EN=0;
	__delay_us(20);
}
void data(unsigned char dat)
{
    PORTD=dat;
	RS=1;
	EN=1;
	__delay_us(20);
	EN=0;
	__delay_us(20);
}
void main()
{

	ANSELC=0;
    ANSELD=0;
    TRISC=0X00;
	TRISD=0X00;
	//cmd(0x3E);
    cmd(0x40);
    cmd(0xB8);
    cmd(0xC0);
    cmd(0x3F);
    
    cmd(0x40);
    data(0xf8);
    
    cmd(0x41);
    data(0x14);
    
    cmd(0x42);
    data(0x12);
    
    cmd(0x43);
    data(0x14);
  
    cmd(0x44);
    data(0xff);
    
    cmd(0x45);
    data(0xff);
    
    cmd(0x46);
    data(0b10011001);
    
    cmd(0x47);
    data(0b10011001);
    
    cmd(0x48);
    data(0xff);
    
    cmd(0x49);
    data(0b11111111);
    
    cmd(0x50);
    data(0b10000001);
    
    cmd(0x51);
    data(0b10000001);
    
    cmd(0x52);
    data(0b10000001);
    
    cmd(0x53);
    data(0b01000010);
}
