################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bsp/SRC/at32f403a_407_board.c \
../bsp/SRC/bsp_CONFIGURATION_array.c \
../bsp/SRC/bsp_GPIO.c \
../bsp/SRC/bsp_I2C.c \
../bsp/SRC/bsp_TIMER.c \
../bsp/SRC/bsp_USART.c \
../bsp/SRC/bsp_delay.c \
../bsp/SRC/bsp_led.c \
../bsp/SRC/soft_i2c.c 

OBJS += \
./bsp/SRC/at32f403a_407_board.o \
./bsp/SRC/bsp_CONFIGURATION_array.o \
./bsp/SRC/bsp_GPIO.o \
./bsp/SRC/bsp_I2C.o \
./bsp/SRC/bsp_TIMER.o \
./bsp/SRC/bsp_USART.o \
./bsp/SRC/bsp_delay.o \
./bsp/SRC/bsp_led.o \
./bsp/SRC/soft_i2c.o 

C_DEPS += \
./bsp/SRC/at32f403a_407_board.d \
./bsp/SRC/bsp_CONFIGURATION_array.d \
./bsp/SRC/bsp_GPIO.d \
./bsp/SRC/bsp_I2C.d \
./bsp/SRC/bsp_TIMER.d \
./bsp/SRC/bsp_USART.d \
./bsp/SRC/bsp_delay.d \
./bsp/SRC/bsp_led.d \
./bsp/SRC/soft_i2c.d 


# Each subdirectory must supply rules for building sources it contributes
bsp/SRC/%.o: ../bsp/SRC/%.c bsp/SRC/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -ffunction-sections  -g -DAT_START_F407_V1 -DTRACE -DOS_USE_TRACE_ITM -DAT32F407VGT7 -DUSE_STDPERIPH_DRIVER -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include" -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include\libraries\cmsis\cm4\core_support" -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include\libraries\cmsis\cm4\device_support" -I"C:\Workspace_artery\ds18b20_lcd1602_at32f407\include\libraries\drivers\inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


