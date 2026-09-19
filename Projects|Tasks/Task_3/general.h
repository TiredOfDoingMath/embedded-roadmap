#ifndef GENERAL_H
#define GENERAL_H
//-------header guard---------
#include <stdint.h>

//struct for edge Configuration (includes masking and unmasking)
typedef struct {
  EXTI_TypeDef *ptr;
  uint8_t line;
} edgeConfig;

typedef enum {
  Port_A,
  Port_B,
  Port_C,
  Port_D,
  Port_F = 5
} PortType;

//creating an enumerated type for functions dealing with edges
typedef enum {
  risingEdge,
  fallingEdge
} Edge_Type;

//enumerated type for functions that mask or unmask events and interrupts
typedef enum{
  masked,
  unmasked
} Mask;

//setting GPIO ports to recieve external interrupts
//registers 1 corresponding to pins {0,1,2,3}
//register 2 corresponding to pins {4,5,6,7}
//register 3 corresponding to pins {8,9,10 11}
//register 4 corresponding to pins {12,13,14,15}
//{3,7,11,15} are quadrant 4, {2,6,10,14} are quadrant 3
//{1,5,9,14} are quadrant 2, {0,4,8,12} are quadrant 1
//ports correspond to A, B, D, D, and F. used to select port letter
void set(uint8_t Register, uint8_t quad, uint8_t port);

//turning on and off and configuring rising edge and falling edge event/interrupt trigger
//enable = to 1 turns line on while 0 turns line off
void config(edgeConfig *self, Edge_Type edge, bool enable);

//fire a software triggered interrupt/event on a line determined by edgeConfig object
void fireSWE(edgeConfig *self);

//clear rising edge pending event or interrupt
void clearRPR1(edgeConfig *self);

//clear falling edge pending event or interrupt
void clearFPR1(edgeConfig *self);

//mask or unmask interrupts on a line connected to the edgeConfig object
void interrupt_Mask_Unmask(edgeConfig *self, Mask status);

//mask or unmask events on a line connected to the edgeConfig object
void event_Mask_Unmask(edgeConfig *self, Mask status);
//--------header guard-------------
#endif

