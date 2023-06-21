#include"Std_Types.h"
#include"doorFunctions.h"

void (*doorFunction[3]) (void)={&door_unlock,&closing_the_door,&state3};

extern doorFlags flags={0,0,1,0,0,0};


int main(){
	door_functions_init();

	powerLights(HIGH);
	while(1){
		doorFunction[flags.doorFunctionToHandle]();
	}

}





