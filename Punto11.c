/*Diseñar una solución programable de manera tal que en el Puerto A se obtenga el
resultado de la operación xnor entre el Puerto B y el literal 0x23.*/

#include "MKL2574.h"
int main()
{

    SIM->SCGCS|=SIM_SCGCS_PORTA_MASK|SIM_SCGCS_PORTB_MASK;
    PORTA->PDDR|=0x00000000;
    PORTB->PDDR|=0xFFFFFFFF;

while(1)
{
    
    uint32_t est_PTB = PTB->PDIR;
    uint32_t XNOR = ~(est_PTB ^ 0x23);
    PTA->PDOR = XNOR;

}
return 0;
}
