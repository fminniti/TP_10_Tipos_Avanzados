#include "simulation.h"

/*
USER_VAL
Validación del input:
Funcion que revisa el caracter ingresado, devolviendo en formato
booleano si este es valido (1) o invalido (0)
*/
uint8_t user_val(int(c))
{ 
  uint8_t result = 0;
  if((c >= '0') && (c <= '7') || (c=='t') ||(c=='c')||(c=='s')) 
  {
    result = 1;
  }
  return result;
}

/*
PRINTLED
Impresion de estados en tiempo real de LED
0 indica apagado;
1 indica encendido;
*/
void printLed( Port_t port){
  int j;
  for (j = 0; j <= MSB; j++){
    printf("LED %d: %d\n", j ,bitGet(PORT_A, j, port));
  }
}

/*
SIMULATION
Esta función recibe el input y llama a las funciones según corresponda.
*/
void simulation(Port_t port){
  uint8_t c;
  do
  {
   c = getchar();    //Recibe el input
    if(user_val(c))   //Si es un caracter válido, evalúa que hacer.
    {
      switch (c)
      {
        case ('0'):
        case ('1'):
        case ('2'):
        case ('3'):
        case ('4'): 
        case ('5'): 
        case ('6'): 
        case ('7'): bitSet(PORT_A, c-ASCII_0, &port); break;  
        /*Resta el ASCII del 0 para transformar el caracter a 
        el valor numérico indicado. Se realiza la misma accion para 
        los 8 casos (0-7)*/
        
        case ('t'): maskToggle(PORT_A,&port,0xFF); break;
        case ('c'): maskOff(PORT_A, &port, 0xFF); break;
        case ('s'): maskOn(PORT_A, &port, 0xFF); break;
        default: break;
      }
      printLed(port);  //Se imprime en pantalla el estado de los LEDS actualizados
    }
    else if(c!= EXIT_GAME && c!= ENTER)
    {
      printf("Ingrese un caracter valido\n");  //Caracter no valido, se pide reingresarlo
    }
  } while(c != EXIT_GAME);
}