#pragma once

#include <at32f403a_407_usart.h>
#include "../INC/bsp_GPIO.h"

typedef enum
{
	DISABLE = 0,
	ENABLE = !DISABLE,
} status;

typedef struct
{
	usart_type					*usart_x;
	uint32_t			 		baud_rate;
	usart_data_bit_num_type		data_bit;
	usart_stop_bit_num_type		stop_bit;
	status						status_transmit;	// transmit enable
	status						status_received;	// received enable
	status						status_half_duplex; // half-duplex communication
	status						status_enable;		// enable the specified usart peripheral
	USART_GPIO					TX;
	USART_GPIO					RX;

} USART_CFG;

void USART_Init_general(void);
void USART_Init(USART_CFG* usart_init_struct);
extern USART_CFG usart[USART_COUNT];
extern GPIO_CFG gpio_usart[USART_COUNT];


