//Blinking an LED with a PWM using the general timers on the register level
#include "stm32c031xx.h"

int main(void){

  //enable IO clock

  RCC->IOPENR |= (1 << 1);


  //enable APB peripheral clock for TIM3

  RCC->APBENR1 |= (1 << 1);


  //APB prescaler set to 16

  RCC->CFGR |= (7 << 12);


  //configuring pin PB4

  GPIOB->MODER &= ~(3 << 8);


  //setting pin to alternate function mode

  GPIOB->MODER |= (2 << 8);


  //setting PB4 to alternate function TIM3_CH1

  GPIOB->AFR[0] &= ~(15 << 16);

  GPIOB->AFR[0] |= (1 << 16);


  //Hardware timer configuration

  TIM3->SMCR &= ~(7 << 0);


  //Prescaler

  TIM3->PSC = 50000;


  //Enable preload for channel 1

  TIM3->CCMR1 |= (1 << 3);

  //CC1S = 00: channel 1 configured as output

  TIM3->CCMR1 &= ~(3 << 0);

  //Clear OC1M[3]

  TIM3->CCMR1 &= ~(1 << 16);

  //Clear OC1M[2:0]

  TIM3->CCMR1 &= ~(7 << 4);

  //OC1M = 110: PWM mode 1

  TIM3->CCMR1 |= (6 << 4);

  //Enable auto-reload preload

  TIM3->CR1 |= (1 << 7);

  //Auto-reload value

  TIM3->ARR = 99;

  //Compare value for channel 1

  TIM3->CCR1 = 50;

  //Enable Channel 1 output

  TIM3->CCER |= (1 << 0);

  //Channel 1 active-high polarity

  TIM3->CCER &= ~(1 << 1);

  //Generate update event

  TIM3->EGR |= (1 << 0);

  //Enable timer

  TIM3->CR1 |= TIM_CR1_CEN;

  while(1){

  }

}
