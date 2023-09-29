/*
 * main.c
 *
 *  Created on: Sep 14, 2023
 *      Author: mh_sm
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "delay.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
int main(){
	MNVIC_voidSetPriority(6, 3, 1,  Option_2);
	MNVIC_voidSetPriority(7, 2, 1,  Option_2);		//EXTI have a highly piriorty
	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidEnableInterrupt(7);
	MRCC_voidInit();
	MRCC_voidEnablePeripheral(RCC_BUS_APB2 , 3);
	MRCC_voidEnablePeripheral(RCC_BUS_APB2 , 2);
	MGPIO_voidSetPinDirection(PORTA,3,GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirection(PORTA,2,GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
	/*Penging for Inturrupt6 -------EXTI0*/
	MNVIC_voidSetPendingFlag(6);

	while(1){



	}
}



void EXTI0_IRQHandler(void)	{
    MGPIO_voidSetPinValue(PORTA,3,1);
		delay(5000);
		MNVIC_voidSetPendingFlag(7);
		/*Pendging for Inturrupt6 -------EXTI1*/
		MGPIO_voidSetPinValue(PORTA,2,1);
		delay(5000);
}
void EXTI1_IRQHandler(void)	{
    MGPIO_voidSetPinValue(PORTA,2,1);
		delay(5000);
}




