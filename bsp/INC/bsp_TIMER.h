#pragma once

#include "at32f403a_407_tmr.h"
#include "../INC/bsp_configuration_enum.h"


typedef struct
{
	tmr_type                            *tmr_x;			// ����� �������
	uint32_t							tmr_pr; 		// ������������� �������� ��������
	uint32_t							tmr_div; 		// ����������� ��������� ������� (PSC)
	tmr_count_mode_type					tmr_cnt_dir;	// ����� ����� (�����, ����)
	uint32_t							tmr_interrupt;	// ��������� ��� ����������� ����������, ������� ����������
														// ����������, ���������� ������� � ���������� ������� �����
	confirm_state						new_state;		// ��������� / ���������
} TIMER_CFG;

void TIM_Init(TIMER_CFG* timer_init_type);
void TIMER_Init_general(void);

extern TIMER_CFG timer[TIMER_COUNT];

