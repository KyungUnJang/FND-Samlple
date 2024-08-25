#ifndef _BSP_CAN_H_
#define _BSP_CAN_H_
#include "main.h"
#include "stm32f103xe.h"


extern void bsp_can_init();
extern void can_data_decoder();
extern uint8_t CAN_RxData_Error[8];







typedef struct 
{
    uint32_t StdId; 
    uint32_t ExtId; 
    uint8_t IDE;    
    uint8_t RTR;    
    uint8_t DLC;    
    uint8_t Data[8];
}CanTxMsg;


typedef struct 
{
    uint32_t StdId; 
    uint32_t ExtId; 
    uint8_t IDE;    
    uint8_t RTR;    
    uint8_t DLC;    
    uint8_t Data[8];
    uint8_t FMI;
}CanRxMsg;

#endif 

