#ifndef __DMA_H
#define	__DMA_H	   
#include "sys.h"
#include"stm32F10x_dma.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//DMA ����	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/8
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////
							    					    

void MYDMA_Config(u16 *cmar,u16 cndtr);//����DMA1_CHx

void MYDMA_Enable(void);//ʹ��DMA1_CHx
		   
#endif




