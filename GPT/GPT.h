#ifndef GPT_H
#define GPT_H
#include "Std_Types.h"


#define TIM 	  ((volatile GPT*)(0x40000000))


void GPT_init(void);

void GPT_StartTimer(uint32 OverFlowTicks);

uint8 GPT_CheckTimeIsElapsed(void);

uint32 GPT_GetElapsedTime(void);

uint32 GPT_GetRemainingTime(void);



#endif
