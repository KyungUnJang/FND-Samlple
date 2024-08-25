#ifndef _7SEG_H_
#define _7SEG_H_
#include "main.h"



#define FND_0 0
#define FND_1 1
#define FND_2 2
#define FND_3 3
#define FND_4 4
#define FND_5 5
#define FND_6 6
#define FND_7 7
#define FND_8 8
#define FND_9 9
#define FND_E 10

#define ERR_CODE_IDLE               0
#define ERR_DRIVE_DONE  		(1 << 0)	
#define ERR_FLASH_READ 		    (1 << 1)	
#define ERR_OUT_ROAD 		    (1 << 2)	
#define ERR_MEMORY_OVER  	    (1 << 3)	
#define ERR_REMOCON             (1 << 4)
#define ERR_collision			(1 << 5)	
#define ERR_LOW_BAT     	    (1 << 6)	
#define ERR_IMU_COMM_ERR        (1 << 7)	
#define ERR_HEADING_ERR  		(1 << 8)	
#define ERR_START_DIS_ERR 		(1 << 9)	
#define ERR_FIND_COURSE_ERR		(1 << 10)	
#define ERR_COURSE_CHG_ERR		(1 << 11)	
#define ERR_CENTER_SWITCH_ERR   (1 << 12)
#define ERR_IMU_ACK_ERR			(1 << 13)	
#define ERR_RTK_MCU_CAN     	(1 << 14)	
#define ERR_IMU_MCU_CAN			(1 << 15)	
#define ERR_CAR_MCU_CAN  		(1 << 16)	
#define ERR_FIND_COURSE_OK 		(1 << 17)	

extern uint8_t error_code_1;
extern uint8_t error_code_10;
extern uint32_t Error_Code; 
extern uint32_t Error_Code_dly;
extern void fnd_send(uint8_t FND_1st, uint8_t FND_2nd);
extern void Error_code_dispay();

#endif 