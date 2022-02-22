/*
 * adc.c
 *
 *  Created on: Feb 21, 2022
 *      Author: adithya
 */

//First step before writing any header file
//The block diagram of stm32f446re displays the registers that are connected to the respective peripherals
//GPIO CLOCK IS AHB1
//ADC CLOCK IS APB2
//Let us use PA0 pin as an ADC input
#include "adc.h"

#define ADC1_EN (1U<<8)
#define ADC1_ON (1U<<0)
#define SWSTART (1U<<30)
#define STRT    (1U<<4)
#define EOC 	(1U<<1)

uint16_t *data;

void adc_init(void)
{
	//Enable clock access to port A
	RCC->AHB1ENR |= (1U<<0);
	//Set GPIO A to analog mode
	GPIOA->MODER |= (1U<<0);
	GPIOA->MODER |= (1U<<1);
	//Enable clock access to ADC1
	RCC->APB2ENR |= (1U<<8);
	//Before we start we have to setup the sequencing in ADC
	//Note: suppose we have three different ADC modules connected to the stm32 board then if we want to first enable
	//the required sensor then we set the channel number in the configuration and we can set the order in which we can
	//use the ADC values
    ADC1->SQR3 |= (0U<<0);//FOR pa0 for pa1 we keep this value as 1
    // THIS IS FOR THE SEQUENCE LENGTH
    ADC1->SQR1 = 0x00;
    //THIS FLAG ENABLES THE ADC conversion
    ADC1->CR2 |= ADC1_ON;
}

void start_conversion(void)
{

	ADC1->CR2 |= SWSTART;

}

uint32_t adc_read(void)
{

while(!(ADC1->SR & EOC));

return (ADC1->DR);

}





