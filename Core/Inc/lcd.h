#ifndef __LCD_H
#define __LCD_H

#include "spi.h"
#include "stdint.h"

#define USE_HORIZONTAL 3  //���ú�������������ʾ 0��1Ϊ���� 2��3Ϊ����

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 80
#define LCD_H 160

#else
#define LCD_W 160
#define LCD_H 80
#endif

//-----------------LCD�˿ڶ���---------------- 
#define SPI_LCD hspi1

#define LCD_RES_Clr() {HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET);}
#define LCD_RES_Set() {HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);}

#define LCD_DC_Clr() {HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET);}
#define LCD_DC_Set() {HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET);}
 		     
#define LCD_BLK_Clr()  {HAL_GPIO_WritePin(LCD_BLK_GPIO_Port, LCD_BLK_Pin, GPIO_PIN_SET);}
#define LCD_BLK_Set()  {HAL_GPIO_WritePin(LCD_BLK_GPIO_Port, LCD_BLK_Pin, GPIO_PIN_RESET);}

#define LCD_CS_Clr()  {HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);}
#define LCD_CS_Set()  {HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);}

#define LCD_CMD  0	//д����
#define LCD_DATA 1	//д����

void Lcd_Init(void);
void Lcd_Clear(uint16_t Color);
void Lcd_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
uint16_t swap_uint16(uint16_t data);

void Lcd_WR_DATA8(unsigned char data); //��������-8λ����
void Lcd_WR_DATA(uint16_t data);
void Lcd_WR_REG(unsigned char data);

void Lcd_Clear(uint16_t Color);
void Lcd_DrawPoint(uint16_t x, uint16_t y, uint16_t color);
void Draw_Circle(uint16_t x0,uint16_t y0,uint16_t r, uint16_t color);
void Lcd_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void Lcd_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);		   
void Lcd_Fill(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color);
void Lcd_ShowChar(uint16_t x, uint16_t y, uint16_t num, uint16_t color);				
void Lcd_ShowString(uint16_t x,uint16_t y,const uint8_t *p, uint16_t color);		
void Lcd_print(uint16_t x,uint16_t y,uint16_t colar,const char *fmt,...);
void Lcd_ShowPicture(uint16_t x,uint16_t y,uint16_t length,uint16_t width,const uint8_t pic[]);

//������ɫ
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			       		0XCFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40 //��ɫ
#define BRRED 			     0XFC07 //�غ�ɫ
#define GRAY  			     0X8430 //��ɫ
#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
#define LIGHTGREEN     	 0X841F //ǳ��ɫ
#define LGRAY 			     0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ
#define LGRAYBLUE        0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE           0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)

#endif




