################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../user/at32f403a_407_clock.c \
../user/at32f403a_407_int.c \
../user/main.c 

OBJS += \
./user/at32f403a_407_clock.o \
./user/at32f403a_407_int.o \
./user/main.o 

C_DEPS += \
./user/at32f403a_407_clock.d \
./user/at32f403a_407_int.d \
./user/main.d 


# Each subdirectory must supply rules for building sources it contributes
user/%.o: ../user/%.c user/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -ffunction-sections  -g -DAT_START_F407_V1 -DTRACE -DOS_USE_TRACE_ITM -DAT32F407VGT7 -DUSE_STDPERIPH_DRIVER -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include" -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include\libraries\cmsis\cm4\core_support" -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include\libraries\cmsis\cm4\device_support" -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include\libraries\drivers\inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

user/main.o: ../user/main.c user/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -ffunction-sections  -g -DAT_START_F407_V1 -DTRACE -DOS_USE_TRACE_ITM -DAT32F407VGT7 -DUSE_STDPERIPH_DRIVER -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include" -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include\libraries\cmsis\cm4\core_support" -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include\libraries\cmsis\cm4\device_support" -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include\libraries\drivers\inc" -std=gnu17 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


