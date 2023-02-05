#pragma once


#include "at32f403a_407_clock.h"
#include "at32f403a_407_board.h"
#include "bsp_GPIO.h"
#include "bsp_system_conf.h"	// include all includes on library
#include "bsp_TIMER.h"
#include "bsp_delay.h"
#include "bsp_USART.h"
#include "bsp_I2C.h"
#include "../bsp/lcd_library/lcd-i2c.h"
#include "../bsp/ds18b20/ds18b20.h"
#include <stdio.h>

void system_printf(void);

