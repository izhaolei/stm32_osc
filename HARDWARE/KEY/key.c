#include"key.h"
#include"stm32f10x.h"
#include "stm32f10x_exti.h"

/*
 * 函数名：NVIC_Configuration
 * 描述  ：配置嵌套向量中断控制器NVIC
 * 输入  ：无
 * 输出  ：无
 * 调用  ：内部调用
 */
 extern int xdiv,ydiv;
 u8 sw;
void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* Configure one bit for preemption priority */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  
  /* 配置P[A|B|C|D|E]0为中断源 */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);



   NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);



    NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);



    NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);



    NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);


}

/*
 * 函数名：EXTI_PB0_Config
 * 描述  ：配置 PB0 为线中断口，并设置中断优先级
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 */
void EXTI_PB0_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure;

	/* config the extiline(PB0) clock and AFIO clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO,ENABLE);

	/* config the NVIC(PB0) */
	NVIC_Configuration();

	/* EXTI line gpio config(PB0) */	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;       
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // 上拉输入
  GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* EXTI line(PB0) mode config */
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource0);
  EXTI_InitStructure.EXTI_Line = EXTI_Line0;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿中断
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure); 

  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource1);
  EXTI_InitStructure.EXTI_Line = EXTI_Line1;
    EXTI_Init(&EXTI_InitStructure);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource2);
		  EXTI_InitStructure.EXTI_Line = EXTI_Line2;
    EXTI_Init(&EXTI_InitStructure);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource3);
    EXTI_InitStructure.EXTI_Line = EXTI_Line3;
    EXTI_Init(&EXTI_InitStructure);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource4);
    EXTI_InitStructure.EXTI_Line = EXTI_Line4;
    EXTI_Init(&EXTI_InitStructure); 
  
}

void EXTI0_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line0) != RESET) //确保是否产生了EXTI Line中断
  {
	 if(xdiv<2)xdiv++;
	 else xdiv=0;

    EXTI_ClearITPendingBit(EXTI_Line0);     //清除中断标志位
  }  
}


void EXTI1_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line1) != RESET) //确保是否产生了EXTI Line中断
  {
	 if(xdiv>0)xdiv--;
	 else xdiv=2;

    EXTI_ClearITPendingBit(EXTI_Line1);     //清除中断标志位
  }  
}


void EXTI2_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line2) != RESET) //确保是否产生了EXTI Line中断
  {
	 if(ydiv==1)ydiv=0;
	 else ydiv=1;

    EXTI_ClearITPendingBit(EXTI_Line2);     //清除中断标志位
  }  
}


void EXTI3_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line3) != RESET) //确保是否产生了EXTI Line中断
  {
	 if(ydiv==1)ydiv=0;
	 else ydiv=1;

    EXTI_ClearITPendingBit(EXTI_Line3);     //清除中断标志位
  }  
}


void EXTI4_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line4) != RESET) //确保是否产生了EXTI Line中断
  {
  u16 i=10000;
		while(i--){

		};	 

    EXTI_ClearITPendingBit(EXTI_Line4);     //清除中断标志位
  }  
}
void GPIOB_Init(void){
GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE );	  //使能ADC1通道时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_1|GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//模拟输入引脚
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
void switchup(void){
	switch (sw){
		case 0:
			GPIO_ResetBits(GPIOB, GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3);
			GPIO_SetBits(GPIOB, GPIO_Pin_0);
			
			
			break;
			case 1:
				GPIO_ResetBits(GPIOB, GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_3);
			GPIO_SetBits(GPIOB, GPIO_Pin_1);
				
			break;
			case 2:
				GPIO_ResetBits(GPIOB, GPIO_Pin_1|GPIO_Pin_0|GPIO_Pin_3);
			GPIO_SetBits(GPIOB, GPIO_Pin_2);
				
			break;
			case 3:
				GPIO_ResetBits(GPIOB, GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_0);
			GPIO_SetBits(GPIOB, GPIO_Pin_3);
				
			break;
	}
	
}
