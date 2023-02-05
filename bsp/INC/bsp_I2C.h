#pragma once

#include "../INC/bsp_GPIO.h"

#define I2C_SCL_HIGH()                   gpio_bits_set(I2Cx_SCL_GPIO_PORT, I2Cx_SCL_PIN)
#define I2C_SCL_LOW()                    gpio_bits_reset(I2Cx_SCL_GPIO_PORT, I2Cx_SCL_PIN)

#define I2C_SDA_HIGH()                   gpio_bits_set(I2Cx_SDA_GPIO_PORT, I2Cx_SDA_PIN)
#define I2C_SDA_LOW()                    gpio_bits_reset(I2Cx_SDA_GPIO_PORT, I2Cx_SDA_PIN)


extern GPIO_CFG gpio_i2c[I2C_COUNT];

void I2C_Init_general(void);
