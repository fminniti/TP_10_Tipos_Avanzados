#ifndef EMULETED_PORT_H
#define EMULETED_PORT_H

#include <stdint.h>

enum{
  PORT_A,     //Port A
  PORT_B,     //Port B
  PORT_D      //Port D
};


typedef struct{
  uint8_t B;
  uint8_t A;
} PortAB_t;

typedef union {
  PortAB_t AB;
  uint16_t D;
} Port_t;

void InitPort(Port_t * port);

void bitSet (uint8_t id_port , uint8_t bit , Port_t * port);

void bitClr (uint8_t id_port , uint8_t bit , Port_t * port);

void bitToggle (uint8_t id_port , uint8_t bit , Port_t * port);

uint8_t bitGet (uint8_t id_port , uint8_t bit , Port_t port);

void maskOn(uint8_t id_port , Port_t * port, uint16_t mask);

#endif //EMULETED_PORT_H
