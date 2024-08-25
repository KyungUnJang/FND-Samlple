
#include "task.h"
#include "7segment.h"
uint32_t ms_cnt = 0;
uint16_t uTimerFlag = 0;
uint8_t count=0;
void Event_30ms();
void Event_200ms();
void Event_500ms();	
void Event_2s();	

void Timer_Event()
{
    if(uTimerFlag & TIM_30ms)	Event_30ms();		
    if(uTimerFlag & TIM_200ms)	Event_200ms();
    if(uTimerFlag & TIM_500ms)	Event_500ms();	
    if(uTimerFlag & TIM_2Sec)	Event_2s();	
}


void Event_30ms()
{
    uTimerFlag &= ~TIM_30ms;
}


void Event_200ms()
{
    uTimerFlag &= ~TIM_200ms;
}


void Event_500ms()
{
    

    uTimerFlag &= ~TIM_500ms;
}

void Event_2s()
{
    count++;
    if ( count > 100)
    {
        count = 0;
    }
    error_code_1= count%10;
    error_code_10=count/10;

    uTimerFlag &= ~TIM_2Sec;
}

