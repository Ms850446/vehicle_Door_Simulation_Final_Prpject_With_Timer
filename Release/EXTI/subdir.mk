################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EXTI/EXTI.c 

OBJS += \
./EXTI/EXTI.o 

C_DEPS += \
./EXTI/EXTI.d 


# Each subdirectory must supply rules for building sources it contributes
EXTI/%.o: ../EXTI/%.c EXTI/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"C:\Users\HP.SXM10\eclipse-workspace\Embedded-Arm\final_project\Lib" -I"C:\Users\HP.SXM10\eclipse-workspace\Embedded-Arm\final_project\Rcc" -I"C:\Users\HP.SXM10\eclipse-workspace\Embedded-Arm\final_project\Gpio" -I"C:\Users\HP.SXM10\eclipse-workspace\Embedded-Arm\final_project\EXTI" -I"C:\Users\HP.SXM10\eclipse-workspace\Embedded-Arm\final_project\GPT" -I"C:\Users\HP.SXM10\eclipse-workspace\Embedded-Arm\final_project\doorFunctions" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


