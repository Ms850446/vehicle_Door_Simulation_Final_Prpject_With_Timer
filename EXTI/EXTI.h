/*
---------------------------------Designed by Mohamed Salah-------------------------------
*/
#ifndef EXTI_H
#define EXTI_H

#define EXTI ((ExtiType *)0x40013C00)
#define NVIC_ISER0 (*(uint32 *)0xE000E100)
#define SYSCFG_EXTI_address 0x40013800+0x08
#define EXTI_FALLING_EDGE 0
#define EXTI_RISING_EDGE 1

void EXTI_init(uint8 portName,uint8 pinNumber ,uint8 interruptState);
void EXTI_enable(uint8 pinNumber);
void EXTI_disable(uint8 pinNumber);
void EXTI_pendingFlag_set();


#endif
