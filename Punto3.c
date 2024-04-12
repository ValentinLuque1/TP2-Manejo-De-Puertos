/*Diseñar una solución programable de manera tal que en el Puerto A se visualice el
complemento a 2 del Puerto B*/

#include "MKL2574.h"
int main()
{

    SIM->SCGCS|=SIM_SCGCS_PORTA_MASK|SIM_SCGCS_PORTB_MASK;
    PORTA->PDDR|=0x00000000;
    PORTB->PDDR|=0xFFFFFFFF;

while(1)
{
    uint32_t est_PTB = PTB->PDIR;
    uint32_t CA2 = (~(est_PTB) + 1);
    PTA->PDOR = CA2;

}
return 0;
}
