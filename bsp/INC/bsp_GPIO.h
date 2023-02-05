#pragma once

#include "bsp_system_conf.h"
#include "at32f403a_407_gpio.h"
#include <stdio.h>

#include "bsp_configuration_enum.h"
#include "bsp_delay.h"

typedef enum
{
  GPIO_PIN_RESET	= 0,
  GPIO_PIN_SET		= 1,
} GPIO_PinState;

typedef struct
{
  uint32_t                               gpio_pins;           /*!< pins number selection */
  gpio_output_type                       gpio_out_type;       /*!< output type selection */
  gpio_pull_type                         gpio_pull;           /*!< pull type selection */
  gpio_mode_type                         gpio_mode;           /*!< mode selection */
  gpio_drive_type                        gpio_drive_strength; /*!< drive strength selection */
  gpio_type                             *gpio_port_x;		  /*!< line number selection (GPIOA, GPIOB, GPIOC, GPIOD) */
  GPIO_PinState							 ENALBE;
  GPIO_PinState							 DISABLE;
  GPIO_PinState							 OFFLINE;
  GPIO_PinState							 DEFAULT;
} GPIO_CFG;



// functions of GPIO (set, reset, toggle, read, write)
void GPIO_SetPin(GPIO_CFG* gpio_init_struct);
void GPIO_ResetPin(GPIO_CFG* gpio_init_struct);
void GPIO_TogglePin(GPIO_CFG* gpio_init_struct);
void GPIO_WritePin(GPIO_CFG* gpio_init_struct, GPIO_PinState pin_status);
GPIO_PinState GPIO_ReadPin(GPIO_CFG* gpio_init_struct);

// functions of GPIO INIT (init, de_init)
void GPIO_Init(GPIO_CFG *gpio_init_struct);
void GPIO_DeInit(GPIO_CFG *gpio_init_struct);
void delay_init(void);

// functions of LED INIT
void LED_Init_general(void);
void LED_DeInit(void);
void LED_enable(bsp_leds_e led);
void LED_toggle(bsp_leds_e led);
void LED_disable(bsp_leds_e led);


extern GPIO_CFG led_gpio[LED_COUNT];
extern GPIO_CFG button_gpio[BUTTON_COUNT];
extern GPIO_CFG ds18b20_pins[COUNT_DS18B20_GPIO];




