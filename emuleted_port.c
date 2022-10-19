#include "emuleted_port.h"

void bitSet (uint8_t id_port , uint8_t bit , Port_t * port)
{
  if(id_port == PORT_A)
  {

  }
  else if (id_port == PORT_B)
  {
    
  }
  else
  {
    
  }
}

void bitClr (uint8_t id_port , uint8_t bit , Port_t port)
{
  if(id_port == PORT_A)
  {

  }
  else if (id_port == PORT_B)
  {
    
  }
  else
  {
    
  }
}

uint8_t bitGet (uint8_t id_port , uint8_t bit , Port_t port)
{
  
  return 1;
}

void bitToggle (uint8_t id_port , uint8_t bit , Port_t port)
{
  if(bitGet(id_port,bit,port)) bitClr(id_port,bit,port);
  else bitSet(id_port,bit,port);
}