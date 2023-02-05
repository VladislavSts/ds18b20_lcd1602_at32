#include "../INC/bsp.h"
//*********************************************************
void LED_Init_general(void)
{
	delay_init();

  for (bsp_leds_e led_count = 0; led_count < LED_COUNT; led_count++)
  {
	  GPIO_Init(&led_gpio[led_count]);
	  GPIO_WritePin(&led_gpio[led_count], led_gpio[led_count].DEFAULT);
  }

  GPIO_Init(&button_gpio[BUTTON_1]);

  for (bsp_timer_e timer_count = 0; timer_count < TIMER_COUNT; timer_count++)
  {
	  TIM_Init(&timer[timer_count]);
  }
	    nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);

	    nvic_irq_enable(TMR1_OVF_TMR10_IRQn, 0, 0);
	    nvic_irq_enable(TMR8_OVF_TMR13_IRQn, 0, 0);

	    tmr_counter_enable(TMR1, TRUE);
	    tmr_counter_enable(TMR8, TRUE);


}
//*********************************************************
void LED_DeInit(void)
{
  for (bsp_leds_e i = 0; i < LED_COUNT; ++i)
  {
	  GPIO_WritePin(&led_gpio[i], led_gpio[i].OFFLINE);
	  GPIO_DeInit(&led_gpio[i]);
  }
}
//*********************************************************
void LED_enable(bsp_leds_e led)
{
	GPIO_WritePin(&led_gpio[led], led_gpio[led].ENALBE);
};
//*********************************************************
void LED_toggle(bsp_leds_e led)
{
	GPIO_TogglePin(&led_gpio[led]);
};
//*********************************************************
void LED_disable(bsp_leds_e led)
{
	GPIO_WritePin(&led_gpio[led], led_gpio[led].DISABLE);
};
//*********************************************************
