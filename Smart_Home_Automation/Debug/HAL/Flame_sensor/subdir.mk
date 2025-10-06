################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Flame_sensor/FLAME.c 

OBJS += \
./HAL/Flame_sensor/FLAME.o 

C_DEPS += \
./HAL/Flame_sensor/FLAME.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Flame_sensor/%.o: ../HAL/Flame_sensor/%.c HAL/Flame_sensor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


