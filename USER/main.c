//#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "osc.h"
#include "adc.h"
#include "timer.h"
#include "dma.h"
//ALIENTEK战舰STM32开发板实验13
//TFTLCD显示实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
int xdiv=0,ydiv=0;
u32 ADC_Data;
u16	TIM5CH1_CAPTURE_VAL;
float xbujin=11.7,ybujin=12.5; 
u16 fft[320],fft2[320];
 int main(void)
 {
 
 	float temp=0,adc;
 	float x;
		int j;
	SystemInit();
	delay_init();	    	 //延时函数初始化	  
	NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(9600);
	MYDMA_Config((u16*)fft,320);	//串口初始化为9600
	GPIOB_Init();
	//MYDMA_Config((u32)fft,1024); //LED端口初始化
	LCD_Init();
	//	delay_init();	    	 //延时函数初始化	  
//	NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
//	LCD_Init();
	GPIOA_Init();
//	ADC1_Init();
	ADC1_Init();
	TIM2_Int_Init(143,0);
	TIM5_Cap_Init();
	EXTI_PB0_Config();
	MYDMA_Enable();
	delay_ms(1);

	//where need to add

	while(1){
		j=0;
	delay_ms(10);
	LCD_Clear(WHITE);
	POINT_COLOR=RED;
	OSC_Gui(xdiv,ydiv);
	POINT_COLOR=BLACK;
	for(x=0.001;x<320;x+=xbujin){
	adc=129-(ybujin*fft2[j++]*3.3/2048);
	LCD_DrawLine((u16)(x-xbujin),temp,(u16)x,adc);
 	temp=adc; 

}	   	 
	delay_ms(5);

	}
	//stop
}


