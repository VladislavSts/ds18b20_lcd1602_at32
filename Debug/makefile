################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include user/subdir.mk
-include firmware/subdir.mk
-include cmsis/subdir.mk
-include bsp/lcd_library/subdir.mk
-include bsp/ds18b20/subdir.mk
-include bsp/bsp_system/subdir.mk
-include bsp/SRC/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ds18b20_lcd1602_at32f407
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
ds18b20_lcd1602_at32f407.hex \

SECONDARY_SIZE += \
ds18b20_lcd1602_at32f407.siz \


# All Target
all: main-build

# Main-build Target
main-build: ds18b20_lcd1602_at32f407.elf secondary-outputs

# Tool invocations
ds18b20_lcd1602_at32f407.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU Arm Cross C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -ffunction-sections  -g -T "C:\Workspace_artery\ds18b20_lcd1602_at32f407/ldscripts/AT32F407xG_FLASH.ld" -Xlinker --gc-sections -Wl,-Map,"ds18b20_lcd1602_at32f407.map" --specs=nano.specs -u _printf_float --specs=nosys.specs -o "ds18b20_lcd1602_at32f407.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ds18b20_lcd1602_at32f407.hex: ds18b20_lcd1602_at32f407.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU Arm Cross Create Flash Image'
	arm-none-eabi-objcopy -O ihex "ds18b20_lcd1602_at32f407.elf"  "ds18b20_lcd1602_at32f407.hex"
	@echo 'Finished building: $@'
	@echo ' '

ds18b20_lcd1602_at32f407.siz: ds18b20_lcd1602_at32f407.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU Arm Cross Print Size'
	arm-none-eabi-size --format=berkeley "ds18b20_lcd1602_at32f407.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) ds18b20_lcd1602_at32f407.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
