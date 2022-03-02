/*
 * spi.h
 *
 *  Created on: Mar 2, 2022
 *      Author: adithya
 */

#ifndef SPI_H_
#define SPI_H_
#include<stdio.h>
#include<stdint.h>
#include "stm32f446xx.h"
void spi_gpio_setup(void);
void spi_config(void);
void spi1_transmit(uint8_t *data, uint32_t size);
void spi1_receive(uint8_t *data, uint32_t size);
void cs_enable(void);
void cs_disable(void);

#endif /* SPI_H_ */
