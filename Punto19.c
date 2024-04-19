/*Diseñar una solución programable de manera tal que las salidas A0, A1, A2 y A3 se
activen si B0 está inactivo; y las salidas A4, A5, A6 y A7 se activen si B0 está activo.*/

#include "MKL2574.h"
int main()
{
    uint8_t PinesASalida[4]={0,1,2,3};
    uint8_t PinesASalida2[4]={4,5,6,7};
   
    SIM->SCGCS|=SIM_SCGCS_PORTA_MASK|SIM_SCGCS_PORTB_MASK;
   
    PORTB->PDDR|=0x00000000;
   
    for (int i = 0; i < 4; i++)
    {
        PORTA->PCR[PinesASalida[i]]|=PORT_PCR_MUX(1);
        PORTA->PCR[PinesASalida2[i]]|=PORT_PCR_MUX(1);
    }
    
    

while(1)
{
    
    uint32_t est_PINPB0 = (PTB->PDIR) & (1u << 0);


    if(est_PINPB0 == 0 )
    {
        for (int i = 0; i < 4; i++) 
        {
            PORTA->PSOR |= (1u << PinesASalida[i]);
        }
        
    }else
    {
        for (int i = 0; i < 4; i++) 
        {
            PORTA->PSOR |= (1u << PinesASalida2[i]);
        }
    }
}
}

return 0;
}
