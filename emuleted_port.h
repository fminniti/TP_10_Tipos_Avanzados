#ifndef EMULETED_PORT_H  // guarda evita redefiniciones
#define EMULETED_PORT_H

#include <stdint.h>
/*
Asignacion de un valor en especifico para cada port.
Esto permite diferenciarlos al ser uttilizados como parametros
en cualqueir funcion.
*/
enum{
  PORT_A,     //Port A
  PORT_B,     //Port B
  PORT_D      //Port D
};

/*
De esta manera, queda un puerto al lado del otro
*/
typedef struct{
  uint8_t B;    
  uint8_t A;
} PortAB_t;

/*
El puerto D es los puertos A y B concatenados.
*/
typedef union {
  PortAB_t AB;  
  uint16_t D;
} Port_t;

/*
PROTOTIPOS
*/
void InitPort(Port_t * port);

void bitSet (uint8_t id_port , uint8_t bit , Port_t * port);

void bitClr (uint8_t id_port , uint8_t bit , Port_t * port);

void bitToggle (uint8_t id_port , uint8_t bit , Port_t * port);

uint8_t bitGet (uint8_t id_port , uint8_t bit , Port_t port);

void maskOn(uint8_t id_port , Port_t * port, uint16_t mask);

void maskToggle(uint8_t id_port , Port_t * port, uint16_t mask);

#endif //EMULETED_PORT_H
