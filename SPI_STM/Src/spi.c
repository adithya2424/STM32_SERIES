/*
 * spi.c
 *
 *  Created on: Mar 2, 2022
 *      Author: adithya
 */

#include "spi.h"

//AF5 - This is the alternate function map to Port A pins for SPI1

//PA5 - SPI1_SCK
//PA6 - SPI1_MISO
//PA7 - SPI1_MOSI
//PB6 - CS
#define CS (1U<<6)
#define GPIOA_EN (1U<<0)
#define GPIOB_EN (1U<<1)
#define FULL_DUPLEX ~(1U<<10)
#define MSB_FIRST ~(1U<<7)
#define SSM (1U<<9)
#define SSI (1U<<8)
#define DFF ~(1U<<11)
#define SSOE (1U<<2)
#define SPE  (1U<<6)
#define SPI_CLK (1U<<12)
#define MSTR (1U<<2)
#define TXE (1U<<1)
#define RXNE (1U<<0)
#define SR_BSY (1U<<7)

void spi_gpio_setup(void)
{
	//First enable clock access to GPIO PORT A

    RCC->AHB1ENR |= GPIOA_EN;
    RCC->AHB1ENR |= GPIOB_EN;

    //Set the GPIO PORT A in alternate function mode

    GPIOA->MODER &= ~(1U<<10);
    GPIOA->MODER |=  (1U<<11);

    GPIOA->MODER &= ~(1U<<12);
    GPIOA->MODER |=  (1U<<13);

    GPIOA->MODER &= ~(1U<<14);
    GPIOA->MODER |=  (1U<<15);

    //Set the GPIO PORT B in output mode
    GPIOB->MODER |=  (1U<<12);
    GPIOB->MODER &= ~(1U<<13);

   // Set the GPIO alternate function low register GPIOx_AFRL n AF5 for required SPI pin

    // FOR PA5
    GPIOA->AFR[0] |=  (1U<<20);
    GPIOA->AFR[0] &= ~(1U<<21);
    GPIOA->AFR[0] |=  (1U<<22);
    GPIOA->AFR[0] &= ~(1U<<23);

    // FOR PA6
    GPIOA->AFR[0] |=  (1U<<24);
    GPIOA->AFR[0] &= ~(1U<<25);
    GPIOA->AFR[0] |=  (1U<<26);
    GPIOA->AFR[0] &= ~(1U<<27);

    // FOR PA7
    GPIOA->AFR[0] |=  (1U<<28);
    GPIOA->AFR[0] &= ~(1U<<29);
    GPIOA->AFR[0] |=  (1U<<30);
    GPIOA->AFR[0] &= ~(1U<<31);

}


void spi_config(void)
{

	//Enable clock access to SP1
	RCC->APB2ENR |=SPI_CLK;
//Configure the serial clock baud rate for SPI
//Set the bits as 101 for fPCLK/64
	SPI1->CR1 |= (1U<<3);
	SPI1->CR1 &=~(1U<<4);
	SPI1->CR1 |= (1U<<5);
//Set the SP1 in mode 0 which CPOL=0 and CPHA=1
	SPI1->CR1 &=~(1U<<0);
	SPI1->CR1 &=~(1U<<1);
//Set the SP1 clock in full DUPLEX mode
	SPI1->CR1 &= FULL_DUPLEX;
//Set the frame format of the SPI1 in MSBFirst
	SPI1->CR1 &= MSB_FIRST;
//Set this is master mode
	SPI1->CR1 |= MSTR;
//Leave the CRC check bits, their default state is in disabled mode
//There is  usage of software slave management in this example SET SSM bit as 1
	SPI1->CR1 |= SSM;
//Now set SSI bit as 1 - this value will be forced value into the slave select pin
	SPI1->CR1 |= SSI;
//Set the data frame format bit as 8-bit transmission/reception
	SPI1->CR1 &= DFF;

//Enable the SPI
	SPI1->CR1 |= SPE;

}

void spi1_transmit(uint8_t *data, uint32_t size)
{

	uint32_t i=0;
	uint8_t temp;

	while(i<size)
	{
		//wait for TXE buffer to be set
		while(!(SPI1->SR & TXE)){}
		SPI1->DR = data[i];
		i++;
	}
	//wait for BSY buffer to be set
	while((SPI1->SR & SR_BSY)){}
    //clear the over-run flag
    temp = SPI1->DR;
    temp = SPI1->SR;

}

void spi1_receive(uint8_t *data, uint32_t size)
{

	uint32_t i=0;
	uint8_t temp;

	while(size)
	{
		SPI1->DR = 0;
		//wait for RXNE buffer to be set
		while(!(SPI1->SR & RXNE)){}
		*data++=SPI1->DR;
		size--;
	}
//	//wait for BSY buffer to be set
//	while((SPI1->SR & SR_BSY)){}
//    //clear the over-run flag
//    temp = SPI1->DR;
//    temp = SPI1->SR;

}

void cs_enable(void)
{
	GPIOB->ODR &=~CS;
}

void cs_disable(void)
{
	GPIOB->ODR |= CS;
}

