/*
 * adc.h
 *
 *  Created on: Feb 21, 2022
 *      Author: adithya
 */

#ifndef ADC_H_
#define ADC_H_
#include <stdio.h>
#include "stm32f446xx.h"

void adc_init(void);

void start_conversion(void);

uint32_t adc_read(void);

#endif /* ADC_H_ */
