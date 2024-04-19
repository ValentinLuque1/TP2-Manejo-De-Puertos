/*Diseñar una solución programable de manera tal que las salidas A0 y A1 se activen si
B0 está activo, las salidas A2 y A3 se activen si B1 está activo, las salidas A4 y A5 se activen
si B2 está activo, las salidas A6 y A7 se activen si B3 está activo.*/

#include "MKL2574.h"
int main()
{
    uint8_t PinesASalida1[4]={0,1};
    uint8_t PinesASalida2[4]={2,3};
    uint8_t PinesASalida3[4]={4,5};
    uint8_t PinesASalida4[4]={6,7};
   
    SIM->SCGCS|=SIM_SCGCS_PORTA_MASK|SIM_SCGCS_PORTB_MASK;
   
    PORTB->PDDR|=0x00000000;
   
    for (int i = 0; i < 4; i++)
    {
        PORTA->PCR[PinesASalida1[i]]|=PORT_PCR_MUX(1);
        PORTA->PCR[PinesASalida2[i]]|=PORT_PCR_MUX(1);
        PORTA->PCR[PinesASalida3[i]]|=PORT_PCR_MUX(1);
        PORTA->PCR[PinesASalida4[i]]|=PORT_PCR_MUX(1);
    }
    
    

while(1)
{
    
    uint32_t est_PINPB0 = (PTB->PDIR) & (1u << 0);
    uint32_t est_PINPB1 = (PTB->PDIR) & (1u << 1);
    uint32_t est_PINPB2 = (PTB->PDIR) & (1u << 2);
    uint32_t est_PINPB3 = (PTB->PDIR) & (1u << 3); 


    if(est_PINPB0 == 1 )
    {
        for (int i = 0; i < 4; i++) 
        {
            PORTA->PSOR |= (1u << PinesASalida1[i]);
        }
}
       
        if(est_PINPB1 == 1 )
    {
        for (int i = 0; i < 4; i++) 
        {
            PORTA->PSOR |= (1u << PinesASalida2[i]);
        }
}

        if(est_PINPB2 == 1 )
    {
        for (int i = 0; i < 4; i++) 
        {
            PORTA->PSOR |= (1u << PinesASalida3[i]);
        }
}

        if(est_PINPB3 == 1 )
    {
        for (int i = 0; i < 4; i++) 
        {
            PORTA->PSOR |= (1u << PinesASalida4[i]);
        }
}

return 0;
}
