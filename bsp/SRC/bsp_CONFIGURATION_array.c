#include "../INC/bsp_GPIO.h"
#include "../INC/bsp_TIMER.h"
#include "../INC/bsp_USART.h"
#include "at32f403a_407_gpio.h"
#include "at32f403a_407_crm.h"

GPIO_CFG led_gpio[LED_COUNT] =
{
  [bsp_LED2]= {.gpio_port_x = GPIOD, .gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER, .gpio_out_type = GPIO_OUTPUT_PUSH_PULL,
  .gpio_mode = GPIO_MODE_OUTPUT, .gpio_pins = GPIO_PINS_13, .gpio_pull = GPIO_PULL_NONE, .DEFAULT = GPIO_PIN_SET, .ENALBE = GPIO_PIN_RESET,
  .DISABLE = GPIO_PIN_SET, .OFFLINE = GPIO_PIN_RESET},
  [bsp_LED3]= {.gpio_port_x = GPIOD, .gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER, .gpio_out_type = GPIO_OUTPUT_PUSH_PULL,
  .gpio_mode = GPIO_MODE_OUTPUT, .gpio_pins = GPIO_PINS_14, .gpio_pull = GPIO_PULL_NONE, .DEFAULT = GPIO_PIN_SET, .ENALBE = GPIO_PIN_RESET,
  .DISABLE = GPIO_PIN_SET, .OFFLINE = GPIO_PIN_RESET},
  [bsp_LED4]= {.gpio_port_x = GPIOD, .gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER, .gpio_out_type = GPIO_OUTPUT_PUSH_PULL,
  .gpio_mode = GPIO_MODE_OUTPUT, .gpio_pins = GPIO_PINS_15, .gpio_pull = GPIO_PULL_NONE, .DEFAULT = GPIO_PIN_SET, .ENALBE = GPIO_PIN_RESET,
  .DISABLE = GPIO_PIN_SET, .OFFLINE = GPIO_PIN_RESET},
};

GPIO_CFG button_gpio[BUTTON_COUNT] =
{
//	[BUTTON_1]= {.gpio_port_x = GPIOA, .gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER, .gpio_out_type = GPIO_OUTPUT_PUSH_PULL,
//	.gpio_mode = GPIO_MODE_INPUT, .gpio_pins = GPIO_PINS_0, .gpio_pull = GPIO_PULL_DOWN},
};

TIMER_CFG timer[TIMER_COUNT] =
{
	[TIMER_1]={.tmr_x = TMR1, .tmr_pr = 1000,  .tmr_div = 0xFFFF, .tmr_cnt_dir = TMR_COUNT_UP, .tmr_interrupt = TMR_OVF_INT,
	.new_state = TRUE },
//	[TIMER_8]={.tmr_x = TMR8, .tmr_pr = 1000,  .tmr_div = 0xFFFF, .tmr_cnt_dir = TMR_COUNT_UP, .tmr_interrupt = TMR_OVF_INT,
//	.new_state = TRUE },
};

USART_CFG usart[USART_COUNT]=
{
	[USART_1]={.usart_x = USART1, .baud_rate = 115200, .data_bit = USART_DATA_8BITS, .stop_bit = USART_STOP_1_BIT, .status_transmit = ENABLE,
	.status_received = ENABLE, .status_half_duplex = ENABLE, .status_enable = ENABLE, .TX = bsp_USART_GPIO_TX},
};

GPIO_CFG gpio_usart[USART_COUNT] =
{
	[bsp_USART_GPIO_TX]={.gpio_port_x = GPIOA, .gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER, .gpio_out_type = GPIO_OUTPUT_OPEN_DRAIN,
	.gpio_mode = GPIO_MODE_MUX, .gpio_pins = GPIO_PINS_9, .gpio_pull = GPIO_PULL_NONE},
};

GPIO_CFG gpio_i2c[COUNT_I2C_GPIO] =
{
	[bsp_I2C_SCL]={.gpio_port_x = GPIOB, .gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE, .gpio_out_type = GPIO_OUTPUT_OPEN_DRAIN,
	.gpio_mode = GPIO_MODE_OUTPUT, .gpio_pins = GPIO_PINS_6, .gpio_pull = GPIO_PULL_UP},
	[bsp_I2C_SDA]={.gpio_port_x = GPIOB, .gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE, .gpio_out_type = GPIO_OUTPUT_OPEN_DRAIN,
	.gpio_mode = GPIO_MODE_OUTPUT, .gpio_pins = GPIO_PINS_7, .gpio_pull = GPIO_PULL_UP}
};

GPIO_CFG ds18b20_pins[COUNT_DS18B20_GPIO]=
{
//	[bsp_ds_pin]={.gpio_port_x = GPIOA, .gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER,
//	.gpio_mode = GPIO_MODE_INPUT, .gpio_pins = GPIO_PINS_0, .gpio_pull = GPIO_PULL_UP},
};








