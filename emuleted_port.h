#ifndef EMULETED_PORT_H
#define EMULETED_PORT_H

#include <stdint.h>


enum{
  PORT_A,     //Port A
  PORT_B,     //Port B
  PORT_D      //Port D
};

typedef union {
  int16_t  B :8;
  int16_t  A :8;
  int16_t  D :16;
}Port_t;


void bitSet (uint8_t id_port , uint8_t bit , Port_t port);

void bitClr (uint8_t id_port , uint8_t bit , Port_t port);

void bitToggle (uint8_t id_port , uint8_t bit , Port_t port);

uint8_t bitGet (uint8_t id_port , uint8_t bit , Port_t port);

#endif //EMULETED_PORT_H