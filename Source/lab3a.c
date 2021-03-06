/*
 * lab3a.c
 *
 *  Created on: Apr 8, 2014
 *      Author: Anh Huy
 */
#include "control.h"

int j;
int lab3a(void){
	P2DIR |= 0xFF;
	P2SEL = 0;
	P2OUT &=~ 0xFF;

	P1DIR &=~ 0x04;
	P1REN |= 0x04;
	P1OUT |= 0x04;

	P1IE |= 0x04;
	P1IES |= 0x04;
	P1IFG |=0x04;
	_BIS_SR(LPM1_bits + GIE);
	while(1){
		j=0;
	}
}
#pragma vector = PORT1_VECTOR
__interrupt void Port1(){
	if(j==0){
		P2OUT ^= 0xFF;
	}
	P1IFG &=~ 0x04;
}
