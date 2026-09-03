#include "stm32c031xx.h"

int main(void)
{
	//enabling clock for GPIO pins
	RCC -> IOPENR |= (1 << 1);
	//clearing the bits corresponding to PB10
	GPIOB -> MODER &= ~(3 << 20);
	//setting PB10 to an output configuration
	GPIOB -> MODER |= (1 << 20);
	//setting PB10 output to high 
	GPIOB -> ODR |= (1 << 10);
	while(1){
	}
}

