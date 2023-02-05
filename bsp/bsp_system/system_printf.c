#include "../INC/bsp.h"

void system_printf(void)
{
	//**********************************************************
#ifdef __GNUC__
	int __io_putchar(int ch)
#else
	int fputc(int ch, FILE *f)
	#endif
	{
		while (usart_flag_get(USART1, USART_RDBF_FLAG) == RESET)
		{
		};
		usart_data_transmit(USART1, ch);

		return ch;
	}
#ifdef __GNUC__
	int _write(int file, char *ptr, int len)
	{
		int DataIdx;
		for (DataIdx = 0; DataIdx < len; DataIdx++)
		{
			__io_putchar(*ptr++);
		}
		return len;
	}
#endif
	//******************************************************************
}
