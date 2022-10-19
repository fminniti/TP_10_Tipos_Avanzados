#ifndef EMULETED_PORT_H
#define EMULETED_PORT_H

#include <stdint.h>

enum{
  PORT_A,     //Port A
  PORT_B,     //Port B
  PORT_D      //Port D
};

typedef struct{
  uint16_t D;
} portD_t;

typedef struct{
  uint8_t A;
  uint8_t B;
} portAB_t;

typedef struct {
  uint16_t b0 : 1;
  uint16_t b1 : 1;
  uint16_t b2 : 1;
  uint16_t b3 : 1;
  uint16_t b4 : 1;
  uint16_t b5 : 1;
  uint16_t b6 : 1;
  uint16_t b7 : 1;
  uint16_t b8 : 1;
  uint16_t b9 : 1;
  uint16_t b10 : 1;
  uint16_t b11: 1;
  uint16_t b12 : 1;
  uint16_t b13 : 1;
  uint16_t b14 : 1;
  uint16_t b15 : 1;
}portBit_t;

typedef union{
  portD_t   portD;
  portAB_t  portAB;
  portBit_t portBit;
} Port_t;

void bitSet (uint8_t id_port , uint8_t bit , Port_t port);

void bitClr (uint8_t id_port , uint8_t bit , Port_t port);

void bitToggle (uint8_t id_port , uint8_t bit , Port_t port);

uint8_t bitGet (uint8_t id_port , uint8_t bit , Port_t port);

#endif //EMULETED_PORT_H