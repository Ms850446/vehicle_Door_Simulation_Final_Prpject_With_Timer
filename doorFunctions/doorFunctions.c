#include"doorFunctions.h"
#include"Gpio.h"
#include"GPT.h"
extern doorFlags flags;

void door_functions_init(void){
		Rcc_Init();
		Rcc_Enable(RCC_TIM2);
		Rcc_Enable(RCC_GPIOA);

		GPT_init();

		Gpio_ConfigPin(GPIO_A, 0, GPIO_INPUT, GPIO_PULL_UP);
		Gpio_ConfigPin(GPIO_A, 1, GPIO_INPUT, GPIO_PULL_UP);
		Gpio_ConfigPin(GPIO_A, 2, GPIO_OUTPUT, GPIO_PUSH_PULL);
		Gpio_ConfigPin(GPIO_A, 3, GPIO_OUTPUT, GPIO_PUSH_PULL);
		Gpio_ConfigPin(GPIO_A, 4, GPIO_OUTPUT, GPIO_PUSH_PULL);
		Gpio_ConfigPin(GPIO_A, 5, GPIO_OUTPUT, GPIO_PUSH_PULL);

}
uint8 check_button_pressed(uint8 button){
if(!Gpio_ReadPin(GPIO_A, button)){
	GPT_StartTimer(30);
	while(GPT_CheckTimeIsElapsed());
	if(!flags.isPressed&&!Gpio_ReadPin(GPIO_A, button))
	{
		flags.isPressed=1;
		return 1;
	}
}
else
	flags.isPressed=0;
return 0;

}
void door_unlock(){
	if(!flags.vehicleDoorUnlocked){
		if(check_button_pressed(handleButton)){
			flags.vehicleDoorUnlocked=1;
			flags.doorIsClosed=1;
			vehicleLight(HIGH);
			GPT_StartTimer(500);//waiting for 500ms for making thr hazard light to blink
			hazardLight(HIGH);
			ambientLight(HIGH);
									}}
	else if (GPT_CheckTimeIsElapsed()){
		if(!flags.doorActionNumber){
			GPT_StartTimer(1500);
			hazardLight(LOW);
			flags.doorActionNumber++;
		}
		else {
			ambientLight(LOW);
			flags.doorActionNumber=0;
			flags.doorFunctionToHandle=2;
		}
	}

}
void closing_the_door(void){
	if(!flags.doorIsClosed){
		if(check_button_pressed(doorButton)){
			flags.vehicleDoorUnlocked=1;
			flags.doorIsClosed=1;
			vehicleLight(LOW);
			hazardLight(LOW);
			GPT_StartTimer(1000);
			ambientLight(HIGH);
		}}
	else if(GPT_CheckTimeIsElapsed()) {
		ambientLight(LOW);
		flags.doorFunctionToHandle=2;
	}
}
void state3(){

	if(check_button_pressed(doorButton)){
		ambientLight(HIGH);
		flags.vehicleDoorUnlocked=1;
		flags.doorIsClosed=0;
		flags.doorFunctionToHandle=1;
		flags.hazardLedState=0;
	}

	else if(flags.vehicleDoorUnlocked){
		if(!flags.hazardLedState){
			GPT_StartTimer(10000);
			flags.hazardLedState=1;
		}
		else if(check_button_pressed(handleButton)||GPT_CheckTimeIsElapsed()){
		vehicleLight(LOW);
		ambientLight(LOW);
		GPT_StartTimer(500);
		hazardLight(HIGH);
		flags.vehicleDoorUnlocked=0;
		flags.doorIsClosed=1;
								}}
	else if (GPT_CheckTimeIsElapsed()){
		if(flags.doorActionNumber!=3){
		GPT_StartTimer(500);
		flags.hazardLedState=!flags.hazardLedState;
		hazardLight(flags.hazardLedState);
		flags.doorActionNumber++;
		}
		else{
			flags.doorActionNumber=0;
			flags.doorFunctionToHandle=0;
		}

	}
}
