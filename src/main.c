#include "stm32f10x.h"
#include "iNemo_Lib/iNEMO_Led.h"
#include "iNemo_Lib/iNEMO_Button.h"
#include "iNemo_Lib/iNEMO_HCSR04_Driver.h"
#include <stdio.h>
#include <math.h>

static void Delay(__IO uint32_t nTime);
uint32_t temp = 100;

void setup();
void loop();

int main(void) {
	setup();
	while(1){
		loop();
	}
}

void setup(){
	iNEMO_Button_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
	iNEMO_HCSR04_Init();
}

void loop(){
	if(iNEMO_Button_Get_State(BUTTON_KEY) == 0){
		printf("\nLOOP\n");
		int distance = iNEMO_HCSR04_getDistance();
		float res = (distance / 72000000) / 58;
		printf("Differenza: %d\n", distance);
		printf("Distanza: %.16f\n", res);
		Delay(250);
	}

}

void Delay(__IO uint32_t nTime){
  uint32_t x = nTime * 3600;

  while (x != 0)
	  x--;
}
