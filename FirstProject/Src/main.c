#include <stdio.h>
#include <stdint.h>
#include "stm32f446xx.h"
#include "adc.h"

//This is the code that implements both ADC and SPI
//The ADC readings are obtained from a GAS sensor
//The SDHC flash memory used here is based on SPI

uint32_t gas_sensor;

int main(void)
{
	adc_init();

	while(1)
	{
		start_conversion();
		gas_sensor = adc_read();

	}

}

