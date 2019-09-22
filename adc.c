#include "adc.h"

int a=0;
void led_init(void)
{
  
  P2DIR |=(1<<7);//P2.7设置为输出模式
  P2DIR |=(1<<6);//P2.6设置为输出模式
  P2DIR |=(1<<5);//P2.5设置为输出模式
}


void adc_init(void)
{
  P6SEL |=(1<<0);//p6.1的adc 功能使能
  ADC12CTL0 &=~(ENC);
  ADC12CTL0 = SHT0_2 + ADC12ON; // ADC10ON, interrupt enabled
  
  ADC12CTL1 = SHP; 
  ADC12IE = 0x01;                             // 使能ADC中断
  ADC12CTL0 |= ENC;                         // Conversion enabled


    for (;;)
  {
    ADC12CTL0 |= ADC12SC;                   // Sampling open
    _BIS_SR( GIE);                  // LPM0, ADC12_ISR will force exit
  }


       // Sampling and conversion start
   // while((ADC12CTL1&ADC12BUSY)!=0)_NOP();//等待转化完成
}

// ADC12 interrupt service routine
#pragma vector=ADC12_VECTOR
__interrupt void ADC12_ISR(void)
{
  a =ADC12MEM0;
  if (ADC12MEM0 < 0x7FF)//2047
  {LED2_ON;}//有转化中断就会有灯亮起来
    else
    {LED2_OFF;}//有转化中断就会有灯亮起来
}



