#include <stdio.h>
#include <stdint.h>
#include "emuleted_port.h"

int main(void) {

  Port_t port;
  Port_t * p1 = &port;  //Pointer 
  InitPort(p1);  //Sets Ports to zero

//Debugging y prueba de funciones
  bitSet(PORT_A,6,p1);
  bitSet(PORT_B,3,p1);
  bitClr(PORT_D,13,p1);

  printf("%d , %d\n", port.AB.A, port.AB.B);
  printf("El puerto D dice %X \n", port.D);

  uint16_t a = 0x4248;
  maskOn(PORT_D, &port, a);

  printf("El puerto D dice %X \n", port.D);

  maskOn(PORT_A, &port, 0xEE); 
  printf("El puerto D dice %X \n", port.D);

  maskOn(PORT_B, &port, 0xFF); 
  printf("El puerto D dice %X \n", port.D);

  maskOff(PORT_A, &port, 0x44); 
  printf("El puerto D dice %X \n", port.D);
  
  maskOff(PORT_B, &port, 0xFF); 
  printf("El puerto D dice %X \n", port.D);
  
  maskOff(PORT_D, &port, 0x56FF); 
  printf("El puerto D dice %X \n", port.D);

maskToggle(PORT_D, &port, 0xA800); 
  printf("El puerto D dice %X \n", port.D);

  maskToggle(PORT_A, &port, 0x23); 
  printf("El puerto D dice %X \n", port.D);

  maskToggle(PORT_B, &port, 0x32); 
  printf("El puerto D dice %X \n", port.D);

  maskToggle(PORT_B, &port, 0x02); 
  printf("El puerto D dice %X \n", port.D);
  
  bitSet(PORT_A,4,p1);
  printf("El bit es un %d\n", bitGet(PORT_D, 12, port));

  bitClr(PORT_A, 6, p1);
  bitClr(PORT_B, 3, p1);

  printf("%d , %d\n", port.AB.A, port.AB.B);

  bitToggle(PORT_A, 3, &port);
  bitToggle(PORT_A, 4, &port);

  printf("%d , %d\n", port.AB.A, port.AB.B);  

  return 0;
}