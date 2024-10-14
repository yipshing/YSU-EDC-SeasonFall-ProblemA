#include "GUI.h"
#include "stm32g4xx.h"                  // Device header
#include "tim.h"
uint32_t freqshownow[3];
uint32_t freqshownext[3];
uint8_t unit_choose;  // 0 hz  1 khz
uint8_t channal_choose; // 0 ch1  1 ch2  2 ch3
uint8_t unit_chooseN;  // 0 hz  1 khz
uint8_t channal_chooseN; // 0 ch1  1 ch2  2 ch3
char lcdprinter[20];
extern uint8_t zkb[3];
extern uint8_t sw_status[3];

void sys_refresh(void){
	
	if(freqshownext[0] != freqshownow[0] || freqshownext[1] != freqshownow[1] || freqshownext[2] != freqshownow[2] ||  channal_choose != channal_chooseN || unit_chooseN != unit_choose){
		if(freqshownext[0] >= 0 && freqshownext[0] < 10000000 && freqshownext[1] >= 0 && freqshownext[1] < 10000000 && freqshownext[2] >= 0 && freqshownext[2] < 10000000  )
			{
				freqshownow[0] = freqshownext[0] ;
				freqshownow[1] = freqshownext[1] ;
				freqshownow[2] = freqshownext[2] ;
			}
		else{
				freqshownext[0] = freqshownow[0] ;
				freqshownext[1] = freqshownow[1] ;
				freqshownext[2] = freqshownow[2] ;
		}
		unit_chooseN = unit_choose;
		channal_chooseN = channal_choose;
		Lcd_Clear(BLACK);
			if(unit_chooseN == 0){    //hz
					if(channal_chooseN == 0){
						sprintf(lcdprinter ,"> CH1  %08d Hz",freqshownow[0]);
						Lcd_print(16,20, RED, lcdprinter);
						sprintf(lcdprinter ,"CH2  %08d Hz",freqshownow[1]);
						Lcd_print(30,40, LIGHTGREEN, lcdprinter);
						sprintf(lcdprinter ,"CH3  %08d Hz",freqshownow[2]);
						Lcd_print(30,60, LIGHTGREEN, lcdprinter);							
					}
				else if(channal_chooseN == 1){
						sprintf(lcdprinter ,"CH1  %08d Hz",freqshownow[0]);
						Lcd_print(30,20, LIGHTGREEN, lcdprinter);
						sprintf(lcdprinter ,"> CH2  %08d Hz",freqshownow[1]);
						Lcd_print(16,40, RED, lcdprinter);
						sprintf(lcdprinter ,"CH3  %08d Hz",freqshownow[2]);
						Lcd_print(30,60, LIGHTGREEN, lcdprinter);							
				}
				else if(channal_chooseN == 2){
						sprintf(lcdprinter ,"CH1  %08d Hz",freqshownow[0]);
						Lcd_print(30,20, LIGHTGREEN, lcdprinter);
						sprintf(lcdprinter ,"CH2  %08d Hz",freqshownow[1]);
						Lcd_print(30,40, LIGHTGREEN, lcdprinter);
						sprintf(lcdprinter ,"> CH3  %08d Hz",freqshownow[2]);
						Lcd_print(16,60, RED, lcdprinter);						
				}
		
			}
			
			
			if(unit_chooseN == 1){    //khz
				if(channal_chooseN == 0){
					sprintf(lcdprinter ,"> CH1  %05d KHz",(freqshownow[0]/1000));
					Lcd_print(32,20, RED, lcdprinter);
					sprintf(lcdprinter ,"CH2  %05d KHz",(freqshownow[1]/1000));
					Lcd_print(46,40, LIGHTGREEN, lcdprinter);
					sprintf(lcdprinter ,"CH3  %05d KHz",(freqshownow[2]/1000));
					Lcd_print(46,60, LIGHTGREEN, lcdprinter);										
					}
				else if(channal_chooseN == 1){
					sprintf(lcdprinter ,"CH1  %05d KHz",(freqshownow[0]/1000));
					Lcd_print(46,20, LIGHTGREEN, lcdprinter);
					sprintf(lcdprinter ,"> CH2  %05d KHz",(freqshownow[1]/1000));
					Lcd_print(32,40, RED, lcdprinter);
					sprintf(lcdprinter ,"CH3  %05d KHz",(freqshownow[2]/1000));
					Lcd_print(46,60, LIGHTGREEN, lcdprinter);											
				}
				else if(channal_chooseN == 2){
					sprintf(lcdprinter ,"CH1  %05d KHz",(freqshownow[0]/1000));
					Lcd_print(46,20, LIGHTGREEN, lcdprinter);
					sprintf(lcdprinter ,"CH2  %05d KHz",(freqshownow[1]/1000));
					Lcd_print(46,40, LIGHTGREEN, lcdprinter);
					sprintf(lcdprinter ,"> CH3  %05d KHz",(freqshownow[2]/1000));
					Lcd_print(32,60, RED, lcdprinter);					
				}
									
			}
			
		Lcd_print(0,0, GRED, "    SQUARE WAVE    ");	
		set_pwm_param(htim2,TIM_CHANNEL_2,freqshownow[0],zkb[0]);
		set_pwm_param(htim15,TIM_CHANNEL_1,freqshownow[1],zkb[1]);
		set_pwm_param(htim3,TIM_CHANNEL_2,freqshownow[2],zkb[2]);
		
	}
	
}


//通用接口，主频80MHz，预分频值为80-1，设置PWM的脉冲频率freq(0.16-10kHz)、占空比参数 pulse (0-100)
void set_pwm_param(TIM_HandleTypeDef htim, uint32_t Channel, uint32_t freq, uint16_t duty)
{
    uint16_t prescaler = 1-1;
    uint64_t tim_clk_freq = 170000000;
    //计算PWM频率，所对应的自动重装载值   ---> ARR = 主频 / (预分频+1) / 预期PWM频率(Hz) - 1
    float pwm_freq_arr  = (tim_clk_freq * 1.0) / (prescaler+1) / freq * 1.0 - 1; 
    //计算PWM占空比，所对应比较寄存器的值 ---> CCR = 预期占空比 * (自动重装载值+1)
    //占空比则由捕获/比较寄存器（TIMx_CRx）寄存器决定。占空比:duty = Pluse / (ARR+1)
    float pwm_duty_pulse = duty * 1.0 / 100 * (pwm_freq_arr + 1);
    
    //配置PSC预分频值
    __HAL_TIM_SET_PRESCALER(&htim, prescaler);
    //配置PWM频率 ARR
    __HAL_TIM_SetAutoreload(&htim, (uint16_t)pwm_freq_arr);
    //配置PWM占空比
    __HAL_TIM_SetCompare(&htim, Channel, (uint16_t)pwm_duty_pulse);

}
