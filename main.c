/**************************************************************************
*                   Simulación del Puerto A                               *
*                                                                         *
* Autores: Santino Agosti                                                 *
*          Gonzalo Louzao                                                 *
*          Francisco Minniti                                              *
*          Matias Asmus                                                   *
*                                                                         *
*          2022                                                           *
*                                                                         *
**************************************************************************/

#include "simulation.h"

int main(void) {
  Port_t port;
  /*----SETEO INICIAL----*/
  Port_t * p1 = &port;  //Creacion e inicializacion de pointer la variable port 
  InitPort(p1);  //Se inicializan los ports a 0
  printLed(port); //Imprime el estado inicial del PORT_A

  /*------SIMULACION------*/
  simulation(port);  //Funcion referida a la simulacion misma 
  return 0;
}