#include "../bsp/INC/bsp.h"

//���������� ���������� ������ TMR1

/* Проект с lcd1602 и ds18b20 датчиком температуры */

uint8_t Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2;
uint16_t TEMP;

void TMR1_OVF_TMR10_IRQHandler(void)
{
	if (tmr_flag_get(TMR1, TMR_OVF_FLAG) != RESET)
	{
		/* add user code... */
		LED_toggle(bsp_LED2);
		LED_toggle(bsp_LED3);
		LED_toggle(bsp_LED4);
		tmr_flag_clear(TMR1, TMR_OVF_FLAG);
	}
}

//���������� ���������� ������ TMR8

//void TMR8_OVF_TMR13_IRQHandler(void)
//{
//	if(tmr_flag_get(TMR8, TMR_OVF_FLAG) != RESET)
//	  {
//	    /* add user code... */
//		LED_toggle(bsp_LED3);
//	    tmr_flag_clear(TMR8, TMR_OVF_FLAG);
//	  }
//}


int main(void)
{
	system_printf();

	system_clock_config();

	LED_Init_general();
	TIMER_Init_general();
	USART_Init_general();

	I2C_Init_general();
	LCD_Init();

	printf("HELLO, WORLD! \r\n");

	lcd_put_cur(0, 0);
	lcd_send_string("Hello, world!");
	delay_ms(1000);

	float Temperature = 0;
	float Humidity = 0;
	uint8_t Presence = 0;

	char str[30] =
	{ 0 };

	while (1)
	{

		Display_Temp(Temperature);

		/********************* DS18B20 *******************/

		Presence = DS18B20_Start();
		delay_ms(1);
		DS18B20_Write(0xCC);  // skip ROM
		DS18B20_Write(0x44);  // convert t (0x44)
		delay_ms(800);

		Presence = DS18B20_Start();
		delay_ms(1);
		DS18B20_Write(0xCC);  // skip ROM
		DS18B20_Write(0xBE);  // Read Scratch-pad

		Temp_byte1 = DS18B20_Read();
		Temp_byte2 = DS18B20_Read();
		TEMP = (Temp_byte2 << 8) | Temp_byte1;
		Temperature = (float) TEMP / 16;

		printf("Temperature now: %.2f \r\n", Temperature);
		delay_ms(100);

	}
}


