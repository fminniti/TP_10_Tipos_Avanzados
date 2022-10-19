#include "emuleted_port.h"

void InitPort(Port_t * port){
  (*port).D = 0;
}

void bitSet (uint8_t id_port , uint8_t bit , Port_t * port)
{
  uint16_t mask = 1;
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

void bitClr (uint8_t id_port , uint8_t bit , Port_t * port)
{
if (id_port == PORT_D)
  {
    if(bit > 7){
      bit -= 7;
      id_port = PORT_A;
    } 
    else {
      id_port = PORT_B;
    }
  }
  /*
Laburamos con D directamente, no con A y con B
Hacemos un mask que sea: 1011 1111 1111 1111
*/
  int8_t mask = -65;   //10111111
  
  int i;
  if (bit == 7){
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


void bitToggle (uint8_t id_port , uint8_t bit , Port_t * port)
{
  if(bitGet(id_port,bit,*port)){
    bitClr(id_port,bit,port);
  } else{
    bitSet(id_port,bit,port);
  }
}

void maskOn(uint8_t id_port , Port_t * port, uint16_t mask){
  switch (id_port){
    case (PORT_A): (*port).AB.A |= mask; break;
    case (PORT_B): (*port).AB.B |= mask; break;
    case (PORT_D): (*port).D |= mask; break;
  }
}

void maskOff(uint8_t id_port , Port_t * port, uint16_t mask){ //togglear toda la mascara y hacer un and
  mask = ~mask;
  switch (id_port){
    case (PORT_A): (*port).AB.A &= mask; break;
    case (PORT_B): (*port).AB.B &= mask; break;
    case (PORT_D): (*port).D &= mask; break;
  }
}

void maskToggle(uint8_t id_port , Port_t * port, uint16_t mask){
  
}
