#pragma once

#include "at32f403a_407.h"

#define DS18B20_PORT 	GPIOA
#define DS18B20_PIN 	GPIO_PINS_0

void Display_Temp (float Temp);
void Set_Pin_Output(void);
void Set_Pin_Input (void);
uint8_t DS18B20_Start (void);
void DS18B20_Write (uint8_t data);
uint8_t DS18B20_Read (void);
