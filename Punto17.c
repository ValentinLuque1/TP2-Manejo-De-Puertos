/*Diseñar una solución programable de manera tal que las salidas A0, A2, A4 y A6 se
activen si B0 está inactivo; y las salidas A1, A3, A5 y A7 se activen si B0 está activo.*/

#include "MKL2574.h"
int main()
{
    uint8_t PinesASalida[4]={0,2,4,6};
    uint8_t PinesASalida2[4]={1,3,5,7};
   
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
