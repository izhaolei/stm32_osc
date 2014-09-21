#include"osc.h"
#include"lcd.h"
#include"delay.h"
extern float xbujin,ybujin;
extern u16	TIM5CH1_CAPTURE_VAL;
extern u32 fft[1024];
u32 max;
void OSC_Gui(u8 xdata,u8 ydata)
	{
	
	LCD_Clear(WHITE);
	delay_ms(1);	
	//这里需要修改
	LCD_ShowString(50,10,300,16,16,"X :   us/DIV Y :  V/DIV");
	switch(xdata)
		{
		 	case 0:
				LCD_ShowString(74,10,32,16,16,"2");
				xbujin=10;
				break;
			case 1:
				LCD_ShowString(74,10,32,16,16,"200");
				xbujin=0.1;
				break;
			default:
				LCD_ShowString(74,10,80,16,16,"20m ");
				xbujin=0.001;
				break;	
		}
		switch(ydata)
		{
		 	case 0:
				LCD_ShowString(170,10,32,16,16,"1");
				ybujin=10;
				break;
			case 1:
				LCD_ShowString(170,10,32,16,16,"0.1");
				ybujin=100;
				break;	
		}
	 //截止区
	 LCD_ShowString(50,220,100,16,16,"T:        ms");
	LCD_ShowxNum(68,220,TIM5CH1_CAPTURE_VAL,6,16,0);
	LCD_DrawVitalLine(20,30,20,210);	
	LCD_DrawVitalLine(40,30,40,210);
	LCD_DrawVitalLine(60,30,60,210);
	LCD_DrawVitalLine(80,30,80,210);
	LCD_DrawVitalLine(100,30,100,210);
	LCD_DrawVitalLine(120,30,120,210);
	LCD_DrawVitalLine(140,30,140,210);
	LCD_DrawLine(160,30,160,210);
	LCD_DrawVitalLine(180,30,180,210);
	LCD_DrawVitalLine(200,30,200,210);
	LCD_DrawVitalLine(220,30,220,210);
	LCD_DrawVitalLine(240,30,240,210);
	LCD_DrawVitalLine(260,30,260,210);
	LCD_DrawVitalLine(280,30,280,210);
	LCD_DrawVitalLine(300,30,300,210);
	LCD_DrawVitalLine(0,30,319,30);
	LCD_DrawVitalLine(0,50,319,50);
	LCD_DrawVitalLine(0,70,319,70);
	LCD_DrawVitalLine(0,90,319,90);
	LCD_DrawVitalLine(0,110,319,110);
	LCD_DrawLine(0,130,319,130);
	LCD_DrawVitalLine(0,150,319,150);
	LCD_DrawVitalLine(0,170,319,170);
	LCD_DrawVitalLine(0,190,319,190);
	LCD_DrawVitalLine(0,210,319,210); 

	}


void changeArray(u32 *data1,u32 *data2){
	int i;
	max=*data2;
	for(i=0;i<1024;i++)
	{
			*(data1+i*2)=*(data2+i);
			*(data1+2*i+1)=0;
			if(*(data2+i)>max)
				max=*(data2+i);
			
	}

}

 void pingPu(u32 *data){
	for(;;){	
		LCD_SetCursor(0x00,0x0000);	//设置光标位置 
		LCD_WriteRAM_Prepare();     //开始写入GRAM	 	  
		for(;;)
		{
			LCD->LCD_RAM=BLUE;	   
		}

	}
}

