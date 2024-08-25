#ifndef _TASK_H_
#define _TASK_H_
#include "main.h"


#define TIM_10ms			(1 << 1)
#define TIM_30ms			(1 << 2)
#define TIM_50ms			(1 << 3)
#define TIM_100ms			(1 << 4)
#define TIM_200ms			(1 << 5)
#define TIM_500ms			(1 << 6)
#define TIM_1Sec			(1 << 7)
#define TIM_2Sec    		(1 << 8)

extern uint32_t ms_cnt;
extern uint16_t uTimerFlag;
extern void Timer_Event();


#endif 