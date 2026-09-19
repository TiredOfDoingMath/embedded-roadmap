#include "general.h"
#include <stdint.h>
//***function to reset all EXTICR modes***

//each register (1,2,3,4) corresponds to (0,1,2,3) in the array
// any register can configure 4 distinct pins to A,B,C,D,F
// pins in each register do not overlap 


//this is a better implementation of a reset function
static void reset(uint8_t Register, uint8_t quad) {
  uint8_t shift = 8 * (quad - 1);
  EXTI -> EXTICR[Register] &= ~(0xFUL << shift);
}

// a much better implementation of setting ports
void set(uint8_t Register, uint8_t quad, PortType port) {
   uint8_t shift = 8 * (quad - 1);
   reset(Register, quad);
   switch (port) {
    case Port_A:
    //do nothing we are already in this state
    break;
    case Port_B:
    EXTI -> EXTICR[Register] |= (1UL << shift);
    break;
    case Port_C:
    EXTI -> EXTICR[Register] |= (2UL << shift);
    break;
    case Port_D:
    EXTI -> EXTICR[Register] |= (3UL << shift);
    break;
    case Port_F:
    EXTI -> EXTICR[Register] |= (5UL << shift);
    default:
    break;
   }
}

//turning on and off and configuring rising edge and falling edge event/interrupt trigger
void config(edgeConfig *self, Edge_Type edge, bool enable) {
  if(edge == risingEdge && enable == true) {
    self -> ptr -> FTSR1 &= ~(1UL << self -> line);
    self -> ptr -> RTSR1 |= (1UL << self -> line);
  } else if(edge == fallingEdge && enable == true) {
    self -> ptr -> RTSR1 &= ~(1UL << self -> line);
    self -> ptr -> FTSR1 |= (1UL << self -> line);
  } else if(enable == false) {
    self -> ptr -> FTSR1 &= ~(1UL << self -> line);
    self -> ptr -> RTSR1 &= ~(1UL << self -> line);
  }
}
//software event/interrupt trigger (cleared by hardware automatically)
void fireSWE(edgeConfig *self) {
  self -> ptr -> SWIER1 |= (1UL << self -> line);
}

//clearing rising edge pending event
void clearRPR1(edgeConfig *self) {
  self -> ptr -> RPR1 |= (1UL << self -> line);
}

//clearing falling edge pending event
void clearFPR1(edgeConfig *self) {
  self -> ptr -> FPR1 |= (1UL << self -> line);
}


void interrupt_Mask_Unmask(edgeConfig *self, Mask status) {
  if(status == masked) {
    self -> ptr -> IMR1 &= ~(1UL << self -> line);
  } else if(status == unmasked) {
    self -> ptr -> IMR1 |= (1UL << self -> line);
  }
}

void event_Mask_Unmask(edgeConfig *self, Mask status) {
  if(status == masked) {
    self -> ptr -> EMR1 &= ~(1UL << self -> line);
  } else if(status == unmasked) {
    self -> ptr -> EMR1 |= (1UL << self -> line);
  }
}
