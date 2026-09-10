#include "stm32c0xx.h"
int main(void) {
  //masking pin 4 interrupts
  EXTI -> IMR1 &= ~(1 << 4);
  
  //set pin 4 to trigger on rising edge
  EXTI -> RTSR1 |= (1 << 4);


  while(1){}
}
