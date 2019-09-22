#ifndef _ADC_H
#define _ADC_H

#define LED1_ON          P2OUT &=~(1<<7);
#define LED1_OFF         P2OUT |=(1<<7);
#define LED1_REVERSE     P2OUT ^=(1<<7);

#define LED2_ON          P2OUT &=~(1<<6);
#define LED2_OFF         P2OUT |=(1<<6);
#define LED2_REVERSE     P2OUT ^=(1<<6);

#define LED3_ON          P2OUT &=~(1<<5);
#define LED3_OFF         P2OUT |=(1<<5);
#define LED3_REVERSE     P2OUT ^=(1<<5);

#define CPU_F ((double)1100000) //设置时钟为8M
#define delay_ms(x)  __delay_cycles((long)(CPU_F*(double)x/1000.0))

#include "msp430f149.h"
void adc_init(void);
void led_init(void);
#endif
