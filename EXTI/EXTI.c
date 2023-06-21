/*
---------------------------------Designed by Mohamed Salah-------------------------------
*/
#include"Std_Types.h"
#include"Bit_Operations.h"
#include"Rcc.h"
#include"Gpio.h"
#include"EXTI.h"

typedef struct {
	uint32 IMR;
	uint32 EMR;
	uint32 RTSR;
	uint32 FTSR;
	uint32 SWIER;
	uint32 PR;
} ExtiType;


void EXTI_init(uint8 portName,uint8 pinNumber ,uint8 interruptState){
	uint32 *SYSCFG_reg=SYSCFG_EXTI_address;

	/*for selection of the register and bin of SYSCFG register*/
	SYSCFG_reg +=(pinNumber/4); //moving to the register that's given for EXTI

	uint8 shifting=( (pinNumber%4)*4 );	//finding we will need to shift by what in the register

	*SYSCFG_reg |=(shifting<<15); //clearing by setting the bits to 1111 to be able to write to them using &
	*SYSCFG_reg &=(shifting<<(portName-'A') ); //writing in the register based on the GPIO name

	SET_BIT(EXTI->IMR, pinNumber);  // enable mask bit for EXTI of pinNumber


	SET_BIT(NVIC_ISER0, 6+pinNumber);  // enable line based on the bin number on NVIC

//	SET_BIT(EXTI->FTSR, pinNumber);  // setting to falling edge detection
	if(interruptState==EXTI_FALLING_EDGE)
		SET_BIT(EXTI->FTSR, pinNumber);
	else if (interruptState==EXTI_RISING_EDGE)
		SET_BIT(EXTI->RTSR, pinNumber);
}


void EXTI_enable(uint8 pinNumber){
	SET_BIT(NVIC_ISER0, 6+pinNumber);
}

void EXTI_disable(uint8 pinNumber){
	CLEAR_BIT(NVIC_ISER0, 6+pinNumber);
}


void EXTI_pendingFlag_set(){
	//clear pending flag
	SET_BIT(EXTI->PR, 0);
}

