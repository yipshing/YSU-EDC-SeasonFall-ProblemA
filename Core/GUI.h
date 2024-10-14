#include "main.h"
#include "lcd.h"
#include "stdio.h"


void sys_refresh(void);
void set_pwm_param(TIM_HandleTypeDef htim, uint32_t Channel, uint32_t freq, uint16_t duty);
