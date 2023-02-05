#include "../INC/bsp_USART.h"
#include <stdio.h>


void USART_Init_general(void)
{

  for (bsp_USART usart_count = 0; usart_count < COUNT_USART_GPIO; usart_count++)
  {
	  GPIO_Init(&gpio_usart[usart_count]);
	  USART_Init(&usart[USART_1]);
  }

}



//*************************************************************
// settings USART

void USART_Init(USART_CFG* usart_init_struct)
{
	do
	{
		if (usart_init_struct->usart_x == NULL)
			return;

	if (usart_init_struct->usart_x == USART1)
		crm_periph_clock_enable(CRM_USART1_PERIPH_CLOCK, TRUE);
	} while(0);

  crm_clocks_freq_type clocks_freq;
  uint32_t apb_clock, temp_val;
  crm_clocks_freq_get(&clocks_freq);
  if((usart_init_struct->usart_x == USART1) || (usart_init_struct->usart_x == USART6) ||  (usart_init_struct->usart_x == UART7) || (usart_init_struct->usart_x == UART8))
  {
    apb_clock = clocks_freq.apb2_freq;
  }
  else
  {
    apb_clock = clocks_freq.apb1_freq;
  }
  temp_val = (apb_clock * 10 / usart_init_struct->baud_rate);
  if((temp_val % 10) < 5)
  {
    temp_val = (temp_val / 10);
  }
  else
  {
    temp_val = (temp_val / 10) + 1;
  }
  usart_init_struct->usart_x->baudr_bit.div = temp_val;
  usart_init_struct->usart_x->ctrl1_bit.dbn = usart_init_struct->data_bit;
  usart_init_struct->usart_x->ctrl2_bit.stopbn = usart_init_struct->stop_bit;

  // usart transmitter enable
  usart_init_struct->usart_x->ctrl1_bit.ten = usart_init_struct->status_transmit;

  // usart receiver enable
  usart_init_struct->usart_x->ctrl1_bit.ren = usart_init_struct->status_received;

  // enable or disable the usart single line bidirectional half-duplex communication
  usart_init_struct->usart_x->ctrl3_bit.slben = usart_init_struct->status_half_duplex;

  // usart enable the specified usart peripheral
  usart_init_struct->usart_x->ctrl1_bit.uen = usart_init_struct->status_enable;

}



