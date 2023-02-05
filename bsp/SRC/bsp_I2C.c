#include "../INC/bsp_I2C.h"
#include "../INC/soft_i2c.h"

void I2C_Init_general(void)
{
	crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
	crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);
	crm_periph_clock_enable(CRM_I2C1_PERIPH_CLOCK, TRUE);

	I2C_SDA_HIGH();
	I2C_SCL_HIGH();

	for (bsp_I2C i2c_count = 0; i2c_count < COUNT_I2C_GPIO; i2c_count++)
	  {
		  GPIO_Init(&gpio_i2c[i2c_count]);
	  }
}
