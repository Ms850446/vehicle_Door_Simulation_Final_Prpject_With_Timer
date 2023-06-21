/**
 * Gpio.c
 *
 *  Created on: Tue Apr 11 2023
 *  Author    : Abdullah Darwish
 */

#include "Gpio.h"

#include "Gpio_Private.h"
#include "Utils.h"

void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode,
                    uint8 DefaultState) {
  switch (PortName) {
    case GPIO_A:
      GPIOA_MODER &= ~(0x03 << (PinNum * 2));
      GPIOA_MODER |= (PinMode << (PinNum * 2));
      if(PinMode==GPIO_OUTPUT){
      GPIOA_OTYPER &= ~(0x01 << PinNum);
      GPIOA_OTYPER |= (DefaultState << PinNum);
      }
      else if(PinMode==GPIO_INPUT){
    	  GPIOA_PUPDR &=~(0x03<<(PinNum*2));
    	  GPIOA_PUPDR |=(DefaultState<<(PinNum*2));
      }
      break;
    case GPIO_B:
      GPIOB_MODER &= ~(0x03 << (PinNum * 2));
      GPIOB_MODER |= (PinMode << (PinNum * 2));
      if(PinMode==GPIO_OUTPUT){
      GPIOB_OTYPER &= ~(0x01 << PinNum);
      GPIOB_OTYPER |= (DefaultState << PinNum);
      }
      else if(PinMode==GPIO_INPUT){
    	  GPIOB_PUPDR &=~(0x03<<(PinNum*2));
    	  GPIOB_PUPDR |=(DefaultState<<(PinNum*2));
      }

      break;
    case GPIO_C:
    	GPIOC_MODER  &=~(0X03<<(PinNum*2));
    	GPIOC_MODER  |=(PinMode<<(PinNum*2));
    	if(PinMode==GPIO_OUTPUT){
    	GPIOC_OTYPER &=~(0X01<<PinNum);
    	GPIOC_OTYPER |=(DefaultState<<PinNum);
    	}
    	else if(PinMode==GPIO_INPUT){
      	  GPIOC_PUPDR &=~(0x03<<(PinNum*2));
      	  GPIOC_PUPDR |=(DefaultState<<(PinNum*2));
    	}
      // TODO:
      break;
    case GPIO_D:
    	GPIOD_MODER &=~(0x03<<(PinNum*2));
    	GPIOD_MODER |=(PinMode<<(PinNum*2));
    	if(PinMode==GPIO_OUTPUT){
        	GPIOD_OTYPER &=~(0X01<<PinNum);
        	GPIOD_OTYPER |=(DefaultState<<PinNum);
    	}
    	else if(PinMode==GPIO_INPUT){
      	  GPIOD_PUPDR &=~(0x03<<(PinNum*2));
      	  GPIOD_PUPDR |=(DefaultState<<(PinNum*2));
    	}
      // TODO:
      break;
    default:
      break;
  }
}

uint8 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data) {

 //TODO: check if the pin is output
  switch (PortName) {
    case GPIO_A:
      if( ( (GPIOA_MODER>>(PinNum*2))&3) !=1)
    	  return NOK;
      GPIOA_ODR &= ~(0x1 << PinNum);
      GPIOA_ODR |= (Data << PinNum);
      break;
    case GPIO_B:
      if( ( (GPIOB_MODER>>(PinNum*2))&3 )!=1)
      	  return NOK;
      GPIOB_ODR &= ~(0x1 << PinNum);
      GPIOB_ODR |= (Data << PinNum);
      break;
    case GPIO_C:
        if( ( (GPIOC_MODER>>(PinNum*2))&3 )!=1)
        	  return NOK;
        GPIOC_ODR &= ~(0x1 << PinNum);
        GPIOC_ODR |= (Data << PinNum);
      // TODO:
      break;
    case GPIO_D:
        if( ( (GPIOD_MODER>>(PinNum*2))&3 )!=1)
        	  return NOK;
        GPIOD_ODR &= ~(0x1 << PinNum);
        GPIOD_ODR |= (Data << PinNum);
      // TODO:
      break;
    default:
      break;
  }
  return OK; /*condition it is okay and is done */
}


uint8 Gpio_ReadPin(uint8 PortName,uint8 PinNum){
	switch(PortName){
	case GPIO_A:
		return ((GPIOA_IDR>>PinNum)&1);
		break;
	case GPIO_B:
		return ((GPIOB_IDR>>PinNum)&1);
		break;
	case GPIO_C:
		return ((GPIOC_IDR>>PinNum)&1);
		break;
	case GPIO_D:
		return ((GPIOD_IDR>>PinNum)&1);
		break;
	}
return 0;
}

