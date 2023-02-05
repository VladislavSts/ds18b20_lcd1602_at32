#pragma once

#include "at32f403a_407_tmr.h"
#include "../INC/bsp_configuration_enum.h"


typedef struct
{
	tmr_type                            *tmr_x;			// номер таймера
	uint32_t							tmr_pr; 		// периодическое значение счетчика
	uint32_t							tmr_div; 		// коэффициент частоного деления (PSC)
	tmr_count_mode_type					tmr_cnt_dir;	// режим счета (вверх, вниз)
	uint32_t							tmr_interrupt;	// указывает тип разрешенных прерываний, включая обновление
														// прерывания, прерывание запуска и прерывание захвата ввода
	confirm_state						new_state;		// разрешить / запретить
} TIMER_CFG;

void TIM_Init(TIMER_CFG* timer_init_type);
void TIMER_Init_general(void);

extern TIMER_CFG timer[TIMER_COUNT];

