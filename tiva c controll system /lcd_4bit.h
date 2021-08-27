/*
 * lcd_4bit.h
 *
 *  Created on: //
 *      Author:
 */

#ifndef LCD_4BIT_H_
#define LCD_4BIT_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "tm4c123gh6pm.h"

/*CONNECTION
 *
 * DB4-->PD0
 * DB5-->PD1
 * DB6-->PD2
 * DB7-->PD3
 * RS-->PD6 , R/W--->GND  ,E --->PD7;
 */






#define RS 6
#define E  7
#define LCD_CTRL_PORT GPIO_PORTD_DATA_R
#define LCD_CTRL_PORT_DIR GPIO_PORTD_DIR_R
#define LCD_DATA_PORT GPIO_PORTD_DATA_R
#define LCD_DATA_PORT_DIR GPIO_PORTD_DIR_R

void LCD_init();
void LCD_command(unsigned char command);
void LCD_Data(unsigned char data);
void LCD_displayString(unsigned char *str );
void LCD_displayCharacter(unsigned char Byte );
void LCD_intToString(int data);
void LCD_clearScreen(void);
void LCD_displayStringRowCol(unsigned char row , unsigned char col , unsigned char *str );
void _delay_ms(int n);




void _delay_ms(int n){
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{}  /* do nothing for 1 ms */
}

void delayUs(int n){
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3; j++)
{}  /* do nothing for 1 us */
}


void LCD_init(){
    SYSCTL_RCGCGPIO_R |=(1<<4);  /* enable clock to GPIOD */
    LCD_DATA_PORT_DIR = 0XFF;
    LCD_CTRL_PORT_DIR |=(1<<RS)|(1<<E);
    LCD_command(0x02);
    LCD_command(0x28);
    LCD_command(0x0C);
    LCD_command(0x01);



}


void LCD_command(unsigned char command){
    LCD_CTRL_PORT &=~(1<<RS);
    _delay_ms(1);
    LCD_CTRL_PORT |=(1<<E);
    _delay_ms(1);
    LCD_DATA_PORT &=~0X0F;
    LCD_DATA_PORT  |= ((command>>4) & 0x0F);
    _delay_ms(1);
    LCD_CTRL_PORT &=~(1<<E);
    _delay_ms(1);
    LCD_CTRL_PORT |=(1<<E);
    _delay_ms(1);
    LCD_DATA_PORT &=~0X0F;
    LCD_DATA_PORT |= (command  & 0x0F);
    _delay_ms(1);
    LCD_CTRL_PORT &=~(1<<E);
    _delay_ms(1);
}
void LCD_Data(unsigned char data){
    LCD_CTRL_PORT |=(1<<RS);

    _delay_ms(1);
    LCD_CTRL_PORT |=(1<<E);
    _delay_ms(1);
    LCD_DATA_PORT &=~0X0F;
    LCD_DATA_PORT |=  ((data >>4 )& 0x0F);
    _delay_ms(1);
    LCD_CTRL_PORT &=~(1<<E);
    _delay_ms(1);
    LCD_CTRL_PORT |=(1<<E);
    _delay_ms(1);
    LCD_DATA_PORT &=~0X0F;
    LCD_DATA_PORT |= (data  & 0x0F);
    _delay_ms(1);
    LCD_CTRL_PORT &=~(1<<E);
    _delay_ms(1);
}
void LCD_goToRowCol(unsigned char row ,unsigned char col ){
    unsigned char fristCharAddr[]={0x80 , 0XC0, 0X94 ,0XD4};
    LCD_command(fristCharAddr[row-1] + col-1);
    _delay_ms(1);

}
void LCD_displayCharacter(unsigned char Byte ){
    LCD_Data(Byte);
}

void LCD_displayString(unsigned char *str ){
    do{
        LCD_Data(*str++);
    }while(*str);
}
void LCD_displayStringRowCol(unsigned char row , unsigned char col , unsigned char *str ){
    LCD_goToRowCol(row , col);
    LCD_displayString(str);
}
void LCD_clearScreen(void){
    LCD_command(0x01); //clear display
    LCD_goToRowCol(1, 1);
}
void LCD_intToString(int data){
    unsigned char buff[16]; /* String to hold the ascii result */
     sprintf(buff,"%d",data); /* 10 for decimal */
     LCD_displayString(buff);
}



#endif /* LCD_4BIT_H_ */
