/*
 * KEYPAD.h
 *
 *  Created on: ??�/??�/????
 *      Author: RAGAB
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stdint.h"
#include "tm4c123gh6pm.h"

/*CONNECTION
 * ROW1--->PB0
 * ROW2--->PB1
 * ROW3--->PB2
 * ROW4--->PB3
 * COL1--->PB4
 * COL2--->PB5
 * COL3--->PB6
 *
 */

#define KEYPAD_DDR  GPIO_PORTB_DIR_R
#define KEYPAD_DATA GPIO_PORTB_DATA_R
#define KEYPAD_PIN  GPIO_PORTB_DATA_R
#define KEYPAD_PULL GPIO_PORTB_PUR_R
#define KEYPAD_DEN  GPIO_PORTB_DEN_R


#define COL 3
#define ROW 4
typedef unsigned char uint8;

void keypad_init();
unsigned char KEYPAD_pressed();
void delayMMs(int n);

#endif /* KEYPAD_H_ */
