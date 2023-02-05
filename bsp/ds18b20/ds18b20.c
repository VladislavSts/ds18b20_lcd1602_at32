 #include "../bsp/INC/bsp.h"

void Display_Temp (float Temp)
{
	char str[30] = {0};
	lcd_put_cur(0, 0);

	sprintf (str, "Temp: %.2f ", Temp);
	lcd_send_string(str);
	lcd_send_data('C');
}

void Set_Pin_Output(void)
{
	GPIO_CFG gpio_init_ds = {0};
	gpio_init_ds.gpio_pins = DS18B20_PIN;
	gpio_init_ds.gpio_port_x = DS18B20_PORT;
	gpio_init_ds.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
	gpio_init_ds.gpio_mode = GPIO_MODE_OUTPUT;
	gpio_init_ds.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
	GPIO_Init(&gpio_init_ds);
}

void Set_Pin_Input (void)
{
	GPIO_CFG gpio_init_ds = {0};
	gpio_init_ds.gpio_pins = DS18B20_PIN;
	gpio_init_ds.gpio_port_x = DS18B20_PORT;
	gpio_init_ds.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
	gpio_init_ds.gpio_mode = GPIO_MODE_INPUT;
	gpio_init_ds.gpio_pull = GPIO_PULL_UP;
	GPIO_Init(&gpio_init_ds);
}

uint8_t DS18B20_Start (void)
{
	uint8_t Response = 0;
	Set_Pin_Output();  									 	// set the pin as output
	gpio_bits_write(DS18B20_PORT, DS18B20_PIN, RESET);		// pull the pin low
	delay_us(480);  										// delay according to datasheet

	Set_Pin_Input();    									// set the pin as input
	delay_us(80);    										// delay according to datasheet

		if (!(gpio_input_data_bit_read(DS18B20_PORT, DS18B20_PIN)))
		Response = 1;    	// if the pin is low i.e the presence pulse is detected
	else
		Response = -1;

	delay_us(400); 			// 480 us delay totally.

	return Response;
}

void DS18B20_Write (uint8_t data)
{
	Set_Pin_Output();  				// set as output

	for (int i=0; i<8; i++)
	{

		if ((data & (1<<i))!=0)  	// if the bit is high
		{
			// write 1

			Set_Pin_Output(); 		 							// set as output
			gpio_bits_write(DS18B20_PORT, DS18B20_PIN, RESET);	// pull the pin LOW
			delay_us(1);  										// wait for 1 us

			Set_Pin_Input();  		// set as input
			delay_us(60);  			// wait for 60 us
		}

		else  // if the bit is low
		{
			// write 0

			Set_Pin_Output();
			gpio_bits_write(DS18B20_PORT, DS18B20_PIN, RESET); 	// pull the pin LOW
			delay_us(60);  										// wait for 60 us

			Set_Pin_Input();
		}
	}
}

uint8_t DS18B20_Read (void)
{
	uint8_t value=0;

	Set_Pin_Input();

	for (int i=0;i<8;i++)
	{
		Set_Pin_Output();   	// set as output

		// pull the data pin LOW
		gpio_bits_write(DS18B20_PORT, DS18B20_PIN, RESET);
		delay_us(2);  			// wait for > 1us

		Set_Pin_Input();  		// set as input
		// if the pin is HIGH
		if (gpio_input_data_bit_read(DS18B20_PORT, DS18B20_PIN))
		{
			value |= 1<<i;  	// read = 1
		}
		delay_us(60);  			// wait for 60 us
	}
	return value;
}

