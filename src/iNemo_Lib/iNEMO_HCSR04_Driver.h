/*
 * iNEMO_HCSR04_Driver.h
 *
 *  Created on: 28/ott/2014
 *      Author: Mirko
 */

#ifndef INEMO_HCSR04_DRIVER_H_
#define INEMO_HCSR04_DRIVER_H_

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"
#include <stdio.h>

#define SYSCLK						72000000

#define HCSR04_GPIO					GPIOA
#define HCSR04_RCC_GPIO				RCC_APB2Periph_GPIOA
#define HCSR04_Trigger_Pin			GPIO_Pin_6
#define HCSR04_Echo_Pin				GPIO_Pin_4

void iNEMO_HCSR04_Init();
int iNEMO_HCSR04_getDistance();

void iNEMO_HCSR04_Delay(uint32_t nTime);


#endif /* INEMO_HCSR04_DRIVER_H_ */
