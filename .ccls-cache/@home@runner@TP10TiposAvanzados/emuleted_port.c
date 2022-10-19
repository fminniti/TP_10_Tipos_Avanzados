#include "emuleted_port.h"

void InitPort(Port_t * port){
  (*port).D = 0;
}
/*
BITSET
Con una mascara base de 16 bits (0x0001), se utiliza el operando 
"left shift bitwise", 'bit' veces para setear la mascara previo a su uso
en el bit especificado en el argumento.
Con la mascara correctamente modificada, se realiza una comparacion (bitwise) OR
entre la misma y el puerto seleccionado para finalmente asignar su
valor a las variables dentro de la union port en la que se guardan sus valores.
*/
void bitSet (uint8_t id_port , uint8_t bit , Port_t * port)
{
  uint16_t mask = 0x0001;
  int i;
  for (i = 0; i < bit; i++){
    mask = mask<<1;
  }
  
  switch (id_port){
    case (PORT_A): (*port).AB.A |= mask; break;
    case (PORT_B): (*port).AB.B |= mask; break;
    case (PORT_D): (*port).D |= mask; break;
  }
}

/* 
BITCLR
Nos aseguramos que el bit elegido se apague al usar la compuerta lógica AND bitwise con una máscara de todos 1s, salvo un 0 en el bit deseado. 
*/

void bitClr (uint8_t id_port , uint8_t bit , Port_t * port)
{
if (id_port == PORT_D)  // cuando le llega PORT D, trabajamos con el A o el B segun corresponda
  {
    if(bit > 7){
      bit -= 7;
      id_port = PORT_A;
    } 
    else {
      id_port = PORT_B;
    }
  }
  int8_t mask = -65;   //10111111
  
  int i;
  if (bit == 7){ // tratamos el caso en el que el bit es el 7 por separado porque necesitamos que entren 1s por la izquierda al shiftear, no 0s. Además, no funcionaría el for.
    
    mask = 127;        //01111111
  } else {
    for (i = 0; i < 6-bit; i++){
    mask = mask>>1;
  }
    switch (id_port){
      case (PORT_A): (*port).AB.A &= mask; break;
      case (PORT_B): (*port).AB.B &= mask; break;
      
    }
  }
}
//SACAR LOS MAGIC NUMBERS Ej: 7, 127, -65

uint8_t bitGet (uint8_t id_port , uint8_t bit , Port_t port)
{
  uint16_t mask = 1;
  int i;
  for (i = 0; i < bit; i++){
    mask = mask<<1;
  }
  switch (id_port){
    case (PORT_A): 
      port.AB.A &= mask;
      if(port.AB.A){
        return 1;
      } else {
        return 0;
      }
      break;
    
    case (PORT_B): 
      port.AB.B &= mask;
      if(port.AB.B){
        return 1;
      } else {
        return 0;
      }
      break;

        case (PORT_D): 
      port.D &= mask;
      if(port.D){
        return 1;
      } else {
        return 0;
      }
      break;
  }
  return 0;
}

/*
BITTOGGLE
Reutilizando funciones anteriores, logramos:
--Utilizar bitGet para acceder al bit especificado,
--bitClr para igualar a 0 en caso de que el bit especificado sea 1
--bitSet para igualar a 1 en caso de que el bit especificado sea 0
*/
void bitToggle (uint8_t id_port , uint8_t bit , Port_t * port)
{
  if(bitGet(id_port,bit,*port)){
    bitClr(id_port,bit,port);
  } else{
    bitSet(id_port,bit,port);
  }
}

/*    
MaskOn
Para que todos los bits que estan encendidos en la mascara se enciendan en el puerto pero no se modifiquen los otros, utilizamos la compuerta lógica OR bitwise. 
Tabla de verdad:
P M OR
0 1 1
0 0 0    Se puede observar que los bits que  esta   encendidos en la mascara estan encendidos en
1 1 1    el puerto y los apagados no se modifican
1 0 1

*/
void maskOn(uint8_t id_port , Port_t * port, uint16_t mask)
{
  switch (id_port)
  {
    case (PORT_A): (*port).AB.A |= mask; break;
    case (PORT_B): (*port).AB.B |= mask; break;
    case (PORT_D): (*port).D |= mask; break;
  }
}
/* 
MASKOFF
Luego de invertir la mascara, utilizar la puerta logica 
AND bitwise con la nueva mascara apaga todos los bits que 
eran 1's en la mascara inicial y deja igual los bits que eran 
0's en la mascara original.
*/
void maskOff(uint8_t id_port , Port_t * port, uint16_t mask){ 
  mask = ~mask; //invertimos todos los bits de la mascara

  switch (id_port){
    case (PORT_A): (*port).AB.A &= mask; break;
    case (PORT_B): (*port).AB.B &= mask; break;
    case (PORT_D): (*port).D &= mask; break;
  }
}

/*
MASKTOGGLE
Al realizar la tabla de verdad para maskToggle, 
esta describia el comportamiento de la puerta logica XOR bitwise.
De esta manera, comparamos (bitwise) el puerto seleccionado con
la mascara usando dicha puerta logica.

Tabla de verdad:
P M XOR
0 1 1
0 0 0    Se puede observar que los bits que  esta   encendidos en la mascara invierten su valor en
1 1 0    el puerto y los apagados no se modifican
1 0 1
*/
void maskToggle(uint8_t id_port , Port_t * port, uint16_t mask){
  switch (id_port){
    case (PORT_A): (*port).AB.A ^= mask; break;  
    case (PORT_B): (*port).AB.B ^= mask; break;
    case (PORT_D): (*port).D ^= mask; break;
  }
}
