#ifndef SIMULATION_H
#define SIMULATION_H

#include <stdint.h>
#include <stdio.h>
#include "emuleted_port.h"

#define EXIT_GAME 'q'
#define ASCII_0 48
#define ENTER 0xA

uint8_t user_val(int(c));
void printLed(Port_t port);
void dec2bin(uint8_t num, Port_t port);
void simulation(Port_t port);
#endif