#include "at32f403a_407_board.h"

#define STEP_DELAY_MS                    50

/* delay variable */
static __IO uint32_t fac_us;
static __IO uint32_t fac_ms;


void Delay_Init(void)
{
  /* configure systick */
	systick_clock_source_config(SYSTICK_CLOCK_SOURCE_AHBCLK_NODIV);
	fac_us = system_core_clock / (1000000U);
	fac_ms = fac_us * (1000U);
}


void Delay_Us(uint32_t nus)
{
  uint32_t temp = 0;
  SysTick->LOAD = (uint32_t)(nus * fac_us);
  SysTick->VAL = 0x00;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk ;
  do
  {
    temp = SysTick->CTRL;
  }while((temp & 0x01) && !(temp & (1 << 16)));

  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->VAL = 0x00;
}

void Delay_Ms(uint16_t nms)
{
  uint32_t temp = 0; //....what is temp
  while(nms)
  {
    if(nms > STEP_DELAY_MS)
    {
      SysTick->LOAD = (uint32_t)(STEP_DELAY_MS * fac_ms);
      nms -= STEP_DELAY_MS;
    }
    else
    {
      SysTick->LOAD = (uint32_t)(nms * fac_ms);
      nms = 0;
    }
    SysTick->VAL = 0x00;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    do
    {
      temp = SysTick->CTRL;
    }while((temp & 0x01) && !(temp & (1 << 16)));

    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    SysTick->VAL = 0x00;
  }
}

void Delay_Sec(uint16_t sec)
{
  uint16_t index;
  for(index = 0; index < sec; index++)
  {
	Delay_Ms(500);
	Delay_Ms(500);
  }
}

