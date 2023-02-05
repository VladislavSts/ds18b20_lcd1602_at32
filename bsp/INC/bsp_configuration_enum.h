#pragma once

#define DELAY                            100
#define FAST                             1
#define SLOW                             4


// ========= LEDS =========
typedef enum
{
	bsp_LED2 = 0,
	bsp_LED3,
	bsp_LED4,
	LED_COUNT,
} bsp_leds_e;

// ========= BUTTONS =========
typedef enum
{
	BUTTON_1 = 0,
	BUTTON_COUNT,
} bsp_button_e;

// ========= TIMERS =========

typedef enum
{
	TIMER_1 = 0,
	TIMER_8,
	TIMER_COUNT,
} bsp_timer_e;

// ========= USART =========

typedef enum
{
	USART_1 = 0,
	USART_COUNT,
}bsp_USART;

typedef enum
{
	bsp_USART_GPIO_TX = 0,
	bsp_USART_GPIO_RX,
	COUNT_USART_GPIO
} USART_GPIO;

// ========= USART =========
typedef enum
{
	I2C_1 = 0,
	I2C_COUNT,
}bsp_I2C;

typedef enum
{
	bsp_I2C_SCL = 0,
	bsp_I2C_SDA,
	COUNT_I2C_GPIO
} I2C_GPIO;

// ========= DS18B20 =========

typedef enum
{
	bsp_ds_pin = 0,
	COUNT_DS18B20_GPIO
} DS18B20_GPIO;















