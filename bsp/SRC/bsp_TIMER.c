#include "../INC/bsp_TIMER.h"
#include "at32f403a_407_conf.h"
#include "at32f403a_407_exint.h"
#include "../INC/bsp_configuration_enum.h"
#include <stdio.h>


void TIMER_Init_general(void)
{

  for (bsp_timer_e timer_count = 0; timer_count < TIMER_COUNT; timer_count++)
  {
	  TIM_Init(&timer[timer_count]);
  }

  nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);
  nvic_irq_enable(TMR1_OVF_TMR10_IRQn, 0, 0);
  nvic_irq_enable(TMR8_OVF_TMR13_IRQn, 0, 0);

  tmr_counter_enable(TMR1, TRUE);
  tmr_counter_enable(TMR8, TRUE);

}

//************************************************************************************************

void TIM_Init(TIMER_CFG* timer_init_type)
{
	do
	{
		if (timer_init_type->tmr_x == NULL)
			return;

		if (timer_init_type->tmr_x == TMR1)
		{
			crm_periph_clock_enable(CRM_TMR1_PERIPH_CLOCK, TRUE);
			break;
		}

		if (timer_init_type->tmr_x == TMR8)
		{
			crm_periph_clock_enable(CRM_TMR8_PERIPH_CLOCK, TRUE);
			break;
		}

		// to be continue...

	} while (0);

	/* set the pr value */
	timer_init_type->tmr_x->pr = timer_init_type->tmr_pr;

	/* set the div value */
	timer_init_type->tmr_x->div = timer_init_type->tmr_div;

	/* trigger the overflow event to immediately reload pr value and div value */
	timer_init_type->tmr_x->swevt_bit.ovfswtr = TRUE;

	 /* set the cnt direct */
	timer_init_type->tmr_x->ctrl1_bit.cnt_dir = timer_init_type->tmr_cnt_dir;

	/* overflow interrupt enable */
	if(timer_init_type->new_state == TRUE)
	{
		timer_init_type->tmr_x->iden |= timer_init_type->tmr_interrupt;
	}
	else if(timer_init_type->new_state == FALSE)
	{
		timer_init_type->tmr_x->iden &= ~timer_init_type->tmr_interrupt;
	}
}




//#define TMR1                             ((tmr_type *) TMR1_BASE)
//#define TMR2                             ((tmr_type *) TMR2_BASE)
//#define TMR3                             ((tmr_type *) TMR3_BASE)
//#define TMR4                             ((tmr_type *) TMR4_BASE)
//#define TMR5                             ((tmr_type *) TMR5_BASE)
//#define TMR6                             ((tmr_type *) TMR6_BASE)
//#define TMR7                             ((tmr_type *) TMR7_BASE)
//#define TMR8                             ((tmr_type *) TMR8_BASE)
//#define TMR9                             ((tmr_type *) TMR9_BASE)
//#define TMR10                            ((tmr_type *) TMR10_BASE)
//#define TMR11                            ((tmr_type *) TMR11_BASE)
//#define TMR12                            ((tmr_type *) TMR12_BASE)
//#define TMR13                            ((tmr_type *) TMR13_BASE)
//#define TMR14                            ((tmr_type *) TMR14_BASE)



































//void TIMER_Init(void)
//{
//	crm_periph_clock_enable(CRM_TMR2_PERIPH_CLOCK, TRUE);	// clock enable
//
//	tmr_output_config_type *tmr_output_struct;
//
//	tmr_base_init(TMR1, 0xFFFF, 0xFFFF);					// ?
//	tmr_cnt_dir_set(TMR1, TMR_COUNT_UP);					// ?
//	tmr_32_bit_function_enable(TMR1, TRUE);					// ?
//	tmr_clock_source_div_set(TMR1, TMR_CLOCK_DIV1);			// PSC
//	tmr_repetition_counter_set(TMR1, 0xFF);					// ?
//
//	tmr_interrupt_enable(TMR1, TMR_OVF_INT, TRUE);			// generation interrupt
//	nvic_irq_enable(TMR1_OVF_TMR10_IRQn, 0, 0);
//
//	  tmr_output_struct->oc_mode = TMR_OUTPUT_CONTROL_OFF;
//	  tmr_output_struct->oc_idle_state = FALSE;
//	  tmr_output_struct->occ_idle_state = FALSE;
//	  tmr_output_struct->oc_polarity = TMR_OUTPUT_ACTIVE_HIGH;
//	  tmr_output_struct->occ_polarity = TMR_OUTPUT_ACTIVE_HIGH;
//	  tmr_output_struct->oc_output_state = FALSE;
//	  tmr_output_struct->occ_output_state = FALSE;
//
//	  tmr_counter_enable(TMR1, TRUE);
//
//
//}
