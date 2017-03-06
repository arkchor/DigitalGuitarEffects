################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

EMPTY := 
SPACE := $(EMPTY) $(EMPTY)

ORDERED_OBJS += \
$(GEN_CMDS_QUOTED) \
"./usbstk5515_led.obj" \
"./usbstk5515_i2c.obj" \
"./usbstk5515_gpio.obj" \
"./usbstk5515.obj" \
"./usbstk5505_led.obj" \
"./usbstk5505_i2c.obj" \
"./usbstk5505_gpio.obj" \
"./usbstk5505.obj" \
"./tremolo.obj" \
"./stereo.obj" \
"./sinewaves.obj" \
"./reverberation.obj" \
"./pushbuttons5515.obj" \
"./oled5515.obj" \
"./main.obj" \
"./echo.obj" \
"./distortion.obj" \
"./delay.obj" \
"./bargraph5515.obj" \
"./aic3204_init.obj" \
"./aic3204.obj" \
"./PLL.obj" \
"./LEDFlasher.obj" \
-l"rts55h.lib" \
"../55xdsph.lib" \
"../CSLc55x5h.lib" \
"../lnkx.cmd" \

-include ../makefile.init

RM := DEL /F

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: poniedzialek.out

# Tool invocations
poniedzialek.out: $(GEN_CMDS) $(CMD_SRCS) $(LIB_SRCS) $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --diag_warning=225 --ptrdiff_size=32 --memory_model=huge -z -m"poniedzialek.map" --warn_sections -i"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/lib" -i"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --reread_libs --rom_model -o "poniedzialek.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C5500_EXECUTABLE_OUTPUTS__QTD) "poniedzialek.out"
	-$(RM) ".\LEDFlasher.obj" ".\PLL.obj" ".\aic3204.obj" ".\aic3204_init.obj" ".\bargraph5515.obj" ".\delay.obj" ".\distortion.obj" ".\echo.obj" ".\main.obj" ".\oled5515.obj" ".\pushbuttons5515.obj" ".\reverberation.obj" ".\sinewaves.obj" ".\stereo.obj" ".\tremolo.obj" ".\usbstk5505.obj" ".\usbstk5505_gpio.obj" ".\usbstk5505_i2c.obj" ".\usbstk5505_led.obj" ".\usbstk5515.obj" ".\usbstk5515_gpio.obj" ".\usbstk5515_i2c.obj" ".\usbstk5515_led.obj" 
	-$(RM) ".\LEDFlasher.pp" ".\PLL.pp" ".\aic3204.pp" ".\aic3204_init.pp" ".\bargraph5515.pp" ".\delay.pp" ".\distortion.pp" ".\echo.pp" ".\main.pp" ".\oled5515.pp" ".\pushbuttons5515.pp" ".\reverberation.pp" ".\sinewaves.pp" ".\stereo.pp" ".\tremolo.pp" ".\usbstk5505.pp" ".\usbstk5505_gpio.pp" ".\usbstk5505_i2c.pp" ".\usbstk5505_led.pp" ".\usbstk5515.pp" ".\usbstk5515_gpio.pp" ".\usbstk5515_i2c.pp" ".\usbstk5515_led.pp" 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
