#ifndef __DMA_H
#define	__DMA_H	   
#include "sys.h"
#include"stm32F10x_dma.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//DMA 代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/8
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////
							    					    

void MYDMA_Config(u16 *cmar,u16 cndtr);//配置DMA1_CHx

void MYDMA_Enable(void);//使能DMA1_CHx
		   
#endif




