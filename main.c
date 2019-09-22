#include "adc.h"

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
   
  led_init();//显示灯初始化
  LED1_OFF
  LED2_OFF;//关闭led2
  LED3_OFF; //关闭led3
   
  adc_init();//adc初始化
  while(1)
  {
  
  LED3_REVERSE;
  delay_ms(200);
  
  }
}
