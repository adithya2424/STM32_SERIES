

#include <stdint.h>
#include "stm32f446xx.h"
#include "spi.h"

int main(void)
{

	spi_gpio_setup();
	spi_config();
	uint8_t data = 0x06;
    while(1)
    {
    	cs_enable();
    	spi1_transmit(&data, 1);
    	cs_disable();
    }


}
