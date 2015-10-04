/*
 * iNEMO_HCSR04_Driver.c
 *
 *  Created on: 28/ott/2014
 *      Author: Mirko
 */

#include "iNEMO_HCSR04_Driver.h"


void iNEMO_HCSR04_Init(){
	TIM_DeInit(TIM2);

	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef timerInitStructure;

	RCC_APB2PeriphClockCmd(HCSR04_RCC_GPIO, ENABLE);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = HCSR04_Trigger_Pin;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = HCSR04_Echo_Pin;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	timerInitStructure.TIM_Prescaler = 0;
	timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	timerInitStructure.TIM_Period = 0xffff;
	timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV4;
	timerInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &timerInitStructure);

	TIM_Cmd(TIM2, ENABLE);
}

int iNEMO_HCSR04_getDistance(){
	int distance = 0;
	int start_echo = 0;
	int end_echo = 0;



	GPIO_SetBits(HCSR04_GPIO, HCSR04_Trigger_Pin);
	iNEMO_HCSR04_Delay(30);
	GPIO_ResetBits(HCSR04_GPIO, HCSR04_Trigger_Pin);

	while(GPIO_ReadInputDataBit(HCSR04_GPIO, HCSR04_Echo_Pin) == RESET){
	}

	TIM_SetCounter(TIM2, 0);

	while(GPIO_ReadInputDataBit(HCSR04_GPIO, HCSR04_Echo_Pin) != RESET){
	}

	end_echo = TIM_GetCounter(TIM2);

	printf("Start: %d\n", start_echo);
	printf("End: %d\n", end_echo);
	distance = (end_echo - start_echo);
//	distance = ((end_echo - start_echo)/SYSCLK)/58;

	return distance;
}

void iNEMO_HCSR04_Delay(uint32_t nTime){
	uint8_t i;

	while (nTime--)  // delay n us
	{
		i = 1;
		while (i--)
			; // delay 1 us
	}
}
