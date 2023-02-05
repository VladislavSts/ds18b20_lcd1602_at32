################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bsp/bsp_system/syscalls.c \
../bsp/bsp_system/sysmem.c \
../bsp/bsp_system/system_printf.c 

OBJS += \
./bsp/bsp_system/syscalls.o \
./bsp/bsp_system/sysmem.o \
./bsp/bsp_system/system_printf.o 

C_DEPS += \
./bsp/bsp_system/syscalls.d \
./bsp/bsp_system/sysmem.d \
./bsp/bsp_system/system_printf.d 


# Each subdirectory must supply rules for building sources it contributes
bsp/bsp_system/%.o: ../bsp/bsp_system/%.c bsp/bsp_system/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -ffunction-sections  -g -DAT_START_F407_V1 -DTRACE -DOS_USE_TRACE_ITM -DAT32F407VGT7 -DUSE_STDPERIPH_DRIVER -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include" -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include\libraries\cmsis\cm4\core_support" -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include\libraries\cmsis\cm4\device_support" -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include\libraries\drivers\inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


