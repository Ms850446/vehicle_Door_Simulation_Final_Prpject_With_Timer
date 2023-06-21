#ifndef doorFunctions_H
#define doorFunctions_H
#include"STD_Types.h"
#include"Rcc.h"
#include"Gpio.h"
#include"GPT.h"

#define vehicleLight(x)  	(Gpio_WritePin(GPIO_A, 2, x))
#define hazardLight(x)  	(Gpio_WritePin(GPIO_A, 3, x))
#define ambientLight(x)		(Gpio_WritePin(GPIO_A, 4, x))
#define powerLights(x)		(Gpio_WritePin(GPIO_A, 5, x))
#define handleButton 	0
#define doorButton 		1
#define hazardLedPin 	3

typedef struct {
		uint8 isPressed:1;
		uint8 vehicleDoorUnlocked:1;
		uint8 doorIsClosed:1;
		uint8 hazardLedState:1;
		uint8 doorFunctionToHandle:2;
		uint8 doorActionNumber:2;
	}doorFlags;

void door_functions_init();
uint8 check_button_pressed(uint8 button);
void door_unlock(void);
void closing_the_door(void);
void state3(void);

#endif
