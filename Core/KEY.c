#include "KEY.h"

uint8_t key[4][4];
// key[h][s]
extern uint32_t freqshownext[3];
extern uint8_t unit_choose;
extern uint8_t channal_choose; 
uint8_t zkb[3];
void keyscan(void){

	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,1);
	HAL_Delay(2);
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0))    key[0][0] = 1;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1))    key[1][0] = 1;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2))    key[2][0] = 1;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3))    key[3][0] = 1;
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,0);
	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,1);
	HAL_Delay(2);
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0))    key[0][1] = 1;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1))    key[1][1] = 1;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2))    key[2][1] = 1;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3))    key[3][1] = 1;
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,0);
	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1);
	HAL_Delay(2);
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0))    key[0][2] = 1;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1))    key[1][2] = 1;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2))    key[2][2] = 1;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3))    key[3][2] = 1;
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0);
	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,1);
	HAL_Delay(2);
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0))    key[0][3] = 1;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1))    key[1][3] = 1;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2))    key[2][3] = 1;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3))    key[3][3] = 1;
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,0);
	HAL_Delay(2);

}
	

void key_handle(void){
if(key[3][3] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose] *10 + 1;
		key[3][3] = 0;
}
if(key[2][3] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose] *10 + 2;
		key[2][3] = 0;
}
if(key[1][3] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose] *10 + 3;
		key[1][3] = 0;
}
if(key[0][3] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose] /10;
		key[0][3] = 0;
}
if(key[3][2] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose] *10 + 4;
		key[3][2] = 0;
}
if(key[2][2] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose] *10 + 5;
		key[2][2] = 0;
}
if(key[1][2] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose] *10 + 6;
		key[1][2] = 0;
}
if(key[0][2] == 1){
		freqshownext[channal_choose] = 0;
		key[0][2] = 0;
}
if(key[3][1] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose] *10 + 7;
		key[3][1] = 0;
}
if(key[2][1] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose] *10 + 8;
		key[2][1] = 0;
}
if(key[1][1] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose] *10 + 9;
		key[1][1] = 0;
}
if(key[0][1] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose] *10 + 0;
		key[0][1] = 0;
}

if(key[3][0] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose] +1;
		key[3][0] = 0;
}
if(key[2][0] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose]-1;
		key[2][0] = 0;
}
if(key[1][0] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose] *1000;
		key[1][0] = 0;
}
if(key[0][0] == 1){
		freqshownext[channal_choose] = freqshownext[channal_choose] *1000000;
		key[0][0] = 0;
}


HAL_Delay(300);

}


int keytime = 0;
uint8_t sw_status[3];

void sw_handle(void){
	if( HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10) == 0){
		
	if(channal_choose == 0)   channal_choose = 1;
	else if(channal_choose == 1)   channal_choose = 2;
	else if(channal_choose == 2)   channal_choose = 0;
		
	while(1){
			if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10)){
			break;
			}
		}
	}
	
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_11) == 0){
		
		if(unit_choose == 0)
				unit_choose = 1;
		else 
			unit_choose = 0;
	while(1){
			if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_11)){
			break;
			}
		}
	}
	
	
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7) == 0)  //SW_CH1 is working
	{
	sw_status[0] = 1;
	}
	else{
	sw_status[0] = 0;
	}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6) == 0)  //SW_CH2 is working
	{
	sw_status[1] = 1;
	}
	else{
	sw_status[1] = 0;
	}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5) == 0)  //SW_CH3 is working
	{
	sw_status[2] = 1;
	}	
	else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5) == 1){
	sw_status[2] = 0;
	}
	if(sw_status[0] == 1)     zkb[0] = 50;
	else                      zkb[0] = 0;
	if(sw_status[1] == 1)     zkb[1] = 50;
	else                      zkb[1] = 0;
	if(sw_status[2] == 1)     zkb[2] = 50;
	else                      zkb[2] = 0;	
	
	
}



