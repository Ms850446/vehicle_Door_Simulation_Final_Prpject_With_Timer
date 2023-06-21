################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/diag/trace-impl.c \
../system/src/diag/trace.c 

OBJS += \
./system/src/diag/trace-impl.o \
./system/src/diag/trace.o 

C_DEPS += \
./system/src/diag/trace-impl.d \
./system/src/diag/trace.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/diag/%.o: ../system/src/diag/%.c system/src/diag/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"C:\Users\HP.SXM10\eclipse-workspace\Embedded-Arm\final_project\Lib" -I"C:\Users\HP.SXM10\eclipse-workspace\Embedded-Arm\final_project\Rcc" -I"C:\Users\HP.SXM10\eclipse-workspace\Embedded-Arm\final_project\Gpio" -I"C:\Users\HP.SXM10\eclipse-workspace\Embedded-Arm\final_project\EXTI" -I"C:\Users\HP.SXM10\eclipse-workspace\Embedded-Arm\final_project\GPT" -I"C:\Users\HP.SXM10\eclipse-workspace\Embedded-Arm\final_project\doorFunctions" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


