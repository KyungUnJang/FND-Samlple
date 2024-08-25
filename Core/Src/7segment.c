
#include "7segment.h"
#if 1 
uint8_t scan = 0;

uint8_t error_code_1=0;
uint8_t error_code_10=0;
uint32_t Error_Code = 0; 
uint32_t Error_check = 0;
uint32_t Error_Code_dly = 0;
uint32_t Error_num = 0 ;
void FND_init();
void FND_number(uint8_t number);

void fnd_send(uint8_t FND_1st, uint8_t FND_2nd)
{
    scan++;
    if(scan > 4) scan = 1;
    FND_init();
    #if 0 
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_RESET); // 1의자리
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); 
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); 
    //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); //중간
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_15, GPIO_PIN_SET); 
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8, GPIO_PIN_SET);
    #endif 
    #if 1 
    switch(scan)
    {
        case 1: // always E   PB12	PB15  PC6	PC7	PC8
        {
            /* RESET ON*/
            HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_RESET); // 1의자리
            /* SET E */
            FND_number(10);
        }
        break;
        case 2:
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); //중간
            FND_number(FND_1st);
            
        }
        break;
        case 3:
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); 
            FND_number(FND_2nd);
        }
        break;

    }
    #endif 
}

void FND_init()
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8, GPIO_PIN_RESET);
}

void FND_number(uint8_t number)
{
    switch(number)
    {
        case 0: 
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_SET);
        }
        break;

        case 1: 
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_SET);
        }
        break;

        case 2:
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6|GPIO_PIN_8, GPIO_PIN_SET);
        }
        break;

        case 3:
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
        }
        break;

        case 4:
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7|GPIO_PIN_8, GPIO_PIN_SET);
        }
        break;
        case 5:
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7|GPIO_PIN_8, GPIO_PIN_SET);
        }
        break;

        case 6:
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8, GPIO_PIN_SET);
        }
        break;

        case 7:
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_SET);
            
        }
        break;

        case 8:
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8, GPIO_PIN_SET);
        }
        break;

        case 9:
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7|GPIO_PIN_8, GPIO_PIN_SET);
        }   
        break;

        case 10:
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_15, GPIO_PIN_SET); 
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8, GPIO_PIN_SET);
        }
        break;

    }
}







void Error_code_Number()
{

    switch (Error_num)
    {
        case ERR_CODE_IDLE:
        {
            if (Error_Code == 0 )
            {
                error_code_1=0;
                error_code_10=0;
                FND_init();
            }
            else 
            {
                Error_num = ERR_DRIVE_DONE;
                Error_Code_dly = 1500;
            }
            
        }
        break;
        case ERR_DRIVE_DONE:
        {
            if (Error_Code & ERR_DRIVE_DONE)
            {
                error_code_1=1;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_FLASH_READ;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_FLASH_READ;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_FLASH_READ:
        {
            if (Error_Code & ERR_FLASH_READ)
            {
                error_code_1=2;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_OUT_ROAD;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_OUT_ROAD;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_OUT_ROAD:
        {
            if (Error_Code & ERR_OUT_ROAD)
            {
                error_code_1=3;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_MEMORY_OVER;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_MEMORY_OVER;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_MEMORY_OVER:
        {
            if (Error_Code & ERR_MEMORY_OVER)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_REMOCON;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_REMOCON;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_REMOCON:
        {
            if (Error_Code & ERR_REMOCON)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_collision;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_collision;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_collision:
        {
            if (Error_Code & ERR_collision)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_LOW_BAT;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_LOW_BAT;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_LOW_BAT:
        {
            if (Error_Code & ERR_LOW_BAT)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_IMU_COMM_ERR;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_IMU_COMM_ERR;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_IMU_COMM_ERR:
        {
            if (Error_Code & ERR_IMU_COMM_ERR)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_HEADING_ERR;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_HEADING_ERR;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_HEADING_ERR:
        {
            if (Error_Code & ERR_HEADING_ERR)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_START_DIS_ERR;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_START_DIS_ERR;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_START_DIS_ERR:
        {
            if (Error_Code & ERR_START_DIS_ERR)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_FIND_COURSE_ERR;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_FIND_COURSE_ERR;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_FIND_COURSE_ERR:
        {
            if (Error_Code & ERR_FIND_COURSE_ERR)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_COURSE_CHG_ERR;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_COURSE_CHG_ERR;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_COURSE_CHG_ERR:
        {
            if (Error_Code & ERR_COURSE_CHG_ERR)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_CENTER_SWITCH_ERR;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_CENTER_SWITCH_ERR;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_CENTER_SWITCH_ERR:
        {
            if (Error_Code & ERR_CENTER_SWITCH_ERR)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_IMU_ACK_ERR;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_IMU_ACK_ERR;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_IMU_ACK_ERR:
        {
            if (Error_Code & ERR_IMU_ACK_ERR)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_RTK_MCU_CAN;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_RTK_MCU_CAN;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_RTK_MCU_CAN:
        {
            if (Error_Code & ERR_RTK_MCU_CAN)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_IMU_MCU_CAN;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_IMU_MCU_CAN;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_IMU_MCU_CAN:
        {
            if (Error_Code & ERR_IMU_MCU_CAN)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_CAR_MCU_CAN;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_CAR_MCU_CAN;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_CAR_MCU_CAN:
        {
            if (Error_Code & ERR_CAR_MCU_CAN)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_FIND_COURSE_OK;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_FIND_COURSE_OK;
                Error_Code_dly = 1500;
            }
        }
        break;
        case ERR_FIND_COURSE_OK:
        {
            if (Error_Code & ERR_FIND_COURSE_OK)
            {
                error_code_1=4;
                error_code_10=0;
                if ( Error_Code_dly > 0)break;
                Error_num = ERR_CODE_IDLE;
                Error_Code_dly = 1500;
            }
            else 
            {
                Error_num = ERR_CODE_IDLE;
                Error_Code_dly = 1500;
            }
        }
        break;

        default:
        {

        }
        break;
    }
    #endif 
}




void Error_code_dispay()
{
    #if 0 /* 임시 테스트 */
    if ( Error_Code != 0 )
    {
        fnd_send(error_code_10,error_code_1);
    }
    #endif 
    fnd_send(2,5);
    //Error_code_Number();
    
}