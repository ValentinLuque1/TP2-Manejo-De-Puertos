/*Diseñar una solución programable de manera tal que en el Puerto A se refleje el valor
del Puerto B menos uno.*/

#include "MKL2574.h"
int main()
{

    SIM->SCGCS|=SIM_SCGCS_PORTA_MASK|SIM_SCGCS_PORTB_MASK;
    PORTA->PDDR|=0x00000000;
    PORTB->PDDR|=0xFFFFFFFF;

while(1)
{
    
    uint32_t est_PTB = PTB->PDIR;
    uint32_t RES = (est_PTB - 1);
    PTA->PDOR = RES;

}
return 0;
}
