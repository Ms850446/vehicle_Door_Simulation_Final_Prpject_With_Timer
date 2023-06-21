#include"GPT.h"
uint32 overFlowTime;
typedef struct{
	union{
		struct{
			uint32 CEN:1;
			uint32 UDIS:1;
			uint32 URS:1;
			uint32 OPM:1;
			uint32 res:3;
			uint32 ARPE:1;
		}CR1;
	uint32 CR1_value;
	};
	uint32 CR2;
	uint32 SMCR;
	uint32 DIER;
	union{
		struct{
			uint32 UIF:1;
		}SR;
	uint32 SR_value;
	};
	union{
		struct{
			uint32 UG:1;
		}EGR;
	uint32 EGR_value;
	};

	uint32 CCMR1;
	uint32 reserved;
	uint32 CCER;
	uint32 CNT;
	uint32 PSC;
	uint32 ARR;
}GPT;


void GPT_init(void){
	TIM->CR1.OPM=1; //setting OPM bit for making it only one time timer

	TIM->PSC=15999; // setting prescaler  to make the frequency of timer as 1KHZ
					// calculated as F_clk_PSC =16MHZ

}


void apply_Update(){
	TIM->CR1.URS=1;	//setting bit URS for making request

	TIM->EGR.UG=1;	//setting bit UG for applying all updates

	TIM->CR1.URS=0;	//clearing bit URS
}


void GPT_StartTimer(uint32 overFlowTicks){

	overFlowTime=overFlowTicks;
	TIM->ARR=overFlowTicks;	// setting overflow ticks

	TIM->CNT=0x00000000;  	// initializing the counter to be 0

	apply_Update();			// this function used to update
							// values of prescaler and ARR and other registers
	TIM->SR.UIF=0;			// clearing the UIF flag to be ready to read any other value

	TIM->CR1.CEN=1;			// enabling the counter of the GPT

}


uint8 GPT_CheckTimeIsElapsed(void){

	if(TIM->SR.UIF)	// checking if bit 0 UIF is 1 or not for overflow
		return 1; 	// overflow occurred

	return 0; 		// no overflow occurred
}


uint32 GPT_GetElapsedTime(void){	// need checking

	if(TIM->SR.UIF)	// checking if overflow is occurred
		return 0xffffffff;

	if((TIM->CR1.CEN))	//checking if timer is enabled which means that GPT_StartTime is called
		return TIM->CNT ;

	return 0;
}


uint32 GPT_GetRemainingTime(void){

	if(TIM->SR.UIF)//checking if overflow is occurred
		return 0;

	if((TIM->CR1.CEN))//checking if timer is enabled which means that GPT_StartTime is called
		return overFlowTime-TIM->CNT;

	return 0xffffffff;
}

