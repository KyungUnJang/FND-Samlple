#include "bsp_can.h"
#include "7segment.h"
uint8_t CAN_RxData_Error[8];

extern CAN_HandleTypeDef hcan;
CAN_TxHeaderTypeDef txHeader; //CAN Bus Receive Header
CAN_FilterTypeDef sFilterConfig; //declare CAN filter structure




void bsp_can_init()
{
    #if 0
    TxMessage.Data[0] = 0x11; 
    TxMessage.Data[1] = 0;
    TxMessage.Data[2] = 0;
    TxMessage.Data[3] = 0x44;
    #endif 
    txHeader.DLC = 8;
    txHeader.IDE = CAN_ID_STD;
    txHeader.RTR = CAN_RTR_DATA;
    txHeader.StdId = 0x737;
    txHeader.TransmitGlobalTime = DISABLE;
    

    
	
  	sFilterConfig.FilterFIFOAssignment=CAN_FILTER_FIFO0; //set fifo assignment
	sFilterConfig.FilterIdHigh=0x737; //the ID that the filter looks for (switch this for the other microcontroller)
	sFilterConfig.FilterIdLow=0;
	sFilterConfig.FilterMaskIdHigh=0;
	sFilterConfig.FilterMaskIdLow=0;
	sFilterConfig.FilterScale=CAN_FILTERSCALE_32BIT; //set filter scale
	sFilterConfig.FilterActivation=ENABLE;
	
	HAL_CAN_ConfigFilter(&hcan, &sFilterConfig); //configure CAN filter
	HAL_CAN_Start(&hcan); //start CAN
	HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING); //enable interrupts

}
void can_data_decoder()
{
    Error_Code |= CAN_RxData_Error[0];
    Error_Code |= CAN_RxData_Error[1]<<8;
    Error_Code |= CAN_RxData_Error[2]<<16;
    
    
    
}