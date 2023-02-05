#include "../INC/bsp_GPIO.h"

//*********************************************************
// SET PIN function

void GPIO_SetPin(GPIO_CFG* gpio_init_struct)
{
	gpio_init_struct->gpio_port_x->scr = gpio_init_struct->gpio_pins;
};
//*********************************************************
// RESET PIN function
void GPIO_ResetPin(GPIO_CFG* gpio_init_struct)
{
	gpio_init_struct->gpio_port_x->clr = gpio_init_struct->gpio_pins;
};
//*********************************************************
// TOGGLE PIN function
void GPIO_TogglePin(GPIO_CFG* gpio_init_struct)
{
	gpio_init_struct->gpio_port_x->odt ^= gpio_init_struct->gpio_pins;
};
//*********************************************************
// READ PIN function

GPIO_PinState GPIO_ReadPin(GPIO_CFG* gpio_init_struct)
{
	GPIO_PinState status = GPIO_PIN_RESET;

	if (gpio_init_struct->gpio_pins != (gpio_init_struct->gpio_pins & gpio_init_struct->gpio_port_x->idt))
	{
		status = GPIO_PIN_RESET;
	}
	else
	{
		status = GPIO_PIN_SET;
	}
	return status;
};

//*********************************************************
// WRITE PIN function
void GPIO_WritePin(GPIO_CFG* gpio_init_struct, GPIO_PinState pin_status)
{
	if (pin_status != GPIO_PIN_RESET)
	{
		gpio_init_struct->gpio_port_x->scr = gpio_init_struct->gpio_pins;
	}
	else
	{
		gpio_init_struct->gpio_port_x->clr = gpio_init_struct->gpio_pins;
	}

};
//*********************************************************
// DEINIT function
void GPIO_DeInit(GPIO_CFG *gpio_init_struct)
{
	uint32_t temp;
	uint16_t pinx_value, pin_index;

	pin_index = (uint16_t)gpio_init_struct->gpio_pins;

	  /* pinx_value indecate pin grounp bit[3:0] from modey[1:0] confy[1:0] */
	  /* pin input analog config */

	if(gpio_init_struct->gpio_mode == GPIO_MODE_ANALOG)
	{
	  pinx_value = 0x00;
	}

	/* pin 0~7 config */
	if(((uint32_t)pin_index & ((uint32_t)0x00FF)) != 0x00)
	  {
	    for(temp = 0; temp < 0x08; temp++)
	    {
	      if((1 << temp) & pin_index)
	      {
	    	  gpio_init_struct->gpio_port_x->cfglr &= (uint32_t)~(0x0F << (temp * 4));
	    	  gpio_init_struct->gpio_port_x->cfglr |= (uint32_t)(pinx_value << (temp * 4));
	      }
	    }
	  }

	  /* pin 8~15 config */
	  if(pin_index > 0x00ff)
	  {
	    pin_index = pin_index >> 8;

	    for(temp = 0; temp < 0x8; temp++)
	    {
	      if((1 << temp) & pin_index)
	      {
	    	  gpio_init_struct->gpio_port_x->cfghr &= (uint32_t)~(0xf << (temp * 4));
	    	  gpio_init_struct->gpio_port_x->cfghr |= (uint32_t)(pinx_value << (temp * 4));
	      }
	    }
	  }
}
//*********************************************************
// INIT function
void GPIO_Init(GPIO_CFG *gpio_init_struct)
{
	// choose clock settings
	do
	{
		if (gpio_init_struct->gpio_port_x == NULL)
			return;

		if (gpio_init_struct->gpio_port_x == GPIOA)
			{
				crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
				break;
			}

		if (gpio_init_struct->gpio_port_x == GPIOB)
			{
					crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);
					break;
			}

		if (gpio_init_struct->gpio_port_x == GPIOC)
			{
					crm_periph_clock_enable(CRM_GPIOC_PERIPH_CLOCK, TRUE);
					break;
			}

		if (gpio_init_struct->gpio_port_x == GPIOD)
			{
					crm_periph_clock_enable(CRM_GPIOD_PERIPH_CLOCK, TRUE);
					break;
			}
	} while (0);

  uint32_t temp;
  uint16_t pinx_value, pin_index;

  pin_index = (uint16_t)gpio_init_struct->gpio_pins;

  /* pinx_value indecate pin grounp bit[3:0] from modey[1:0] confy[1:0] */

  /* pin input analog config */
  if(gpio_init_struct->gpio_mode == GPIO_MODE_ANALOG)
  {
    pinx_value = 0x00;
  }
  /* pin input config */
  else if(gpio_init_struct->gpio_mode == GPIO_MODE_INPUT)
  {
    pinx_value = gpio_init_struct->gpio_pull & 0x0F;

    if(gpio_init_struct->gpio_pull == GPIO_PULL_UP)
    {
    	gpio_init_struct->gpio_port_x->scr = pin_index;
    }
    else if(gpio_init_struct->gpio_pull == GPIO_PULL_DOWN)
    {
    	gpio_init_struct->gpio_port_x->clr = pin_index;
    }
  }
  else
  {
    pinx_value = (gpio_init_struct->gpio_mode & 0x08) | (gpio_init_struct->gpio_out_type & 0x04) | \
                 (gpio_init_struct->gpio_drive_strength & 0x03);
  }

  /* pin 0~7 config */
  if(((uint32_t)pin_index & ((uint32_t)0x00FF)) != 0x00)
  {
    for(temp = 0; temp < 0x08; temp++)
    {
      if((1 << temp) & pin_index)
      {
    	  gpio_init_struct->gpio_port_x->cfglr &= (uint32_t)~(0x0F << (temp * 4));
    	  gpio_init_struct->gpio_port_x->cfglr |= (uint32_t)(pinx_value << (temp * 4));
      }
    }
  }

  /* pin 8~15 config */
  if(pin_index > 0x00ff)
  {
    pin_index = pin_index >> 8;

    for(temp = 0; temp < 0x8; temp++)
    {
      if((1 << temp) & pin_index)
      {
    	  gpio_init_struct->gpio_port_x->cfghr &= (uint32_t)~(0xf << (temp * 4));
    	  gpio_init_struct->gpio_port_x->cfghr |= (uint32_t)(pinx_value << (temp * 4));
      }
    }
  }
}


//********************************************************* the end :)




