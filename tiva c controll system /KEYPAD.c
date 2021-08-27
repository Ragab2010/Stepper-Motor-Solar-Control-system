/*
 * KEYPAD.c
 *
 *  Created on: ??�/??�/????
 *      Author: RAGAB
 */

#include "KEYPAD.h"



void keypad_init(){
	/*THE 4BIT ROWs IS START FROM BIT0 --TO--->BIT4 IN PORT*/
	/*THE 4BIT COLs IS START FROM BIT3 --TO--->BIT7 IF THE COLs 4LINE ,OR TO--> BIT6 IF THE COLs 3LINE*/
	/*MAKE THE ROWs INPUT AND COLs OUPUT , ENABLE PULL-UP FOR ROWs , WRITE LOW ON COLs*/
    SYSCTL_RCGCGPIO_R |=(1<<2);
    KEYPAD_DEN  =0XFF;
	KEYPAD_DDR  =0xF0;
	KEYPAD_PULL =0x0F;
	KEYPAD_DATA =0X00;

}

unsigned char KEYPAD_pressed(){
	unsigned char col , row;
	unsigned char keypad_matrix[ROW][COL]=
		   {{'1','2','3'},
			{'4','5','6'},
			{'7','8','9'},
			{'*','0','#'}};

while(1){
	for(col =0 ; col<COL ; col++)
		{
			KEYPAD_DDR  = (0b00010000<<col);

			delayMMs(30);
			for(row=0 ;row <ROW ; row++){
				if(!(KEYPAD_PIN &(1<<row))){
					while(!(KEYPAD_PIN &(1<<row)));//polling to print one key
					return keypad_matrix[row][col];
				}

			}
		}

}



}


void delayMMs(int n){
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{}  /* do nothing for 1 ms */
}


