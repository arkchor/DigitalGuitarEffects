################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LIB_SRCS += \
../55xdsph.lib \
../CSLc55x5h.lib 

C_SRCS += \
../LEDFlasher.c \
../PLL.c \
../aic3204.c \
../aic3204_init.c \
../bargraph5515.c \
../delay.c \
../distortion.c \
../echo.c \
../main.c \
../oled5515.c \
../pushbuttons5515.c \
../reverberation.c \
../sinewaves.c \
../stereo.c \
../tremolo.c \
../usbstk5505.c \
../usbstk5505_gpio.c \
../usbstk5505_i2c.c \
../usbstk5505_led.c \
../usbstk5515.c \
../usbstk5515_gpio.c \
../usbstk5515_i2c.c \
../usbstk5515_led.c 

CMD_SRCS += \
../lnkx.cmd 

OBJS += \
./LEDFlasher.obj \
./PLL.obj \
./aic3204.obj \
./aic3204_init.obj \
./bargraph5515.obj \
./delay.obj \
./distortion.obj \
./echo.obj \
./main.obj \
./oled5515.obj \
./pushbuttons5515.obj \
./reverberation.obj \
./sinewaves.obj \
./stereo.obj \
./tremolo.obj \
./usbstk5505.obj \
./usbstk5505_gpio.obj \
./usbstk5505_i2c.obj \
./usbstk5505_led.obj \
./usbstk5515.obj \
./usbstk5515_gpio.obj \
./usbstk5515_i2c.obj \
./usbstk5515_led.obj 

C_DEPS += \
./LEDFlasher.pp \
./PLL.pp \
./aic3204.pp \
./aic3204_init.pp \
./bargraph5515.pp \
./delay.pp \
./distortion.pp \
./echo.pp \
./main.pp \
./oled5515.pp \
./pushbuttons5515.pp \
./reverberation.pp \
./sinewaves.pp \
./stereo.pp \
./tremolo.pp \
./usbstk5505.pp \
./usbstk5505_gpio.pp \
./usbstk5505_i2c.pp \
./usbstk5505_led.pp \
./usbstk5515.pp \
./usbstk5515_gpio.pp \
./usbstk5515_i2c.pp \
./usbstk5515_led.pp 

OBJS__QTD += \
".\LEDFlasher.obj" \
".\PLL.obj" \
".\aic3204.obj" \
".\aic3204_init.obj" \
".\bargraph5515.obj" \
".\delay.obj" \
".\distortion.obj" \
".\echo.obj" \
".\main.obj" \
".\oled5515.obj" \
".\pushbuttons5515.obj" \
".\reverberation.obj" \
".\sinewaves.obj" \
".\stereo.obj" \
".\tremolo.obj" \
".\usbstk5505.obj" \
".\usbstk5505_gpio.obj" \
".\usbstk5505_i2c.obj" \
".\usbstk5505_led.obj" \
".\usbstk5515.obj" \
".\usbstk5515_gpio.obj" \
".\usbstk5515_i2c.obj" \
".\usbstk5515_led.obj" 

C_DEPS__QTD += \
".\LEDFlasher.pp" \
".\PLL.pp" \
".\aic3204.pp" \
".\aic3204_init.pp" \
".\bargraph5515.pp" \
".\delay.pp" \
".\distortion.pp" \
".\echo.pp" \
".\main.pp" \
".\oled5515.pp" \
".\pushbuttons5515.pp" \
".\reverberation.pp" \
".\sinewaves.pp" \
".\stereo.pp" \
".\tremolo.pp" \
".\usbstk5505.pp" \
".\usbstk5505_gpio.pp" \
".\usbstk5505_i2c.pp" \
".\usbstk5505_led.pp" \
".\usbstk5515.pp" \
".\usbstk5515_gpio.pp" \
".\usbstk5515_i2c.pp" \
".\usbstk5515_led.pp" 

C_SRCS_QUOTED += \
"../LEDFlasher.c" \
"../PLL.c" \
"../aic3204.c" \
"../aic3204_init.c" \
"../bargraph5515.c" \
"../delay.c" \
"../distortion.c" \
"../echo.c" \
"../main.c" \
"../oled5515.c" \
"../pushbuttons5515.c" \
"../reverberation.c" \
"../sinewaves.c" \
"../stereo.c" \
"../tremolo.c" \
"../usbstk5505.c" \
"../usbstk5505_gpio.c" \
"../usbstk5505_i2c.c" \
"../usbstk5505_led.c" \
"../usbstk5515.c" \
"../usbstk5515_gpio.c" \
"../usbstk5515_i2c.c" \
"../usbstk5515_led.c" 


# Each subdirectory must supply rules for building sources it contributes
LEDFlasher.obj: ../LEDFlasher.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="LEDFlasher.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

PLL.obj: ../PLL.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="PLL.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

aic3204.obj: ../aic3204.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="aic3204.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

aic3204_init.obj: ../aic3204_init.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="aic3204_init.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

bargraph5515.obj: ../bargraph5515.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="bargraph5515.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

delay.obj: ../delay.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="delay.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

distortion.obj: ../distortion.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="distortion.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

echo.obj: ../echo.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="echo.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

oled5515.obj: ../oled5515.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="oled5515.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

pushbuttons5515.obj: ../pushbuttons5515.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="pushbuttons5515.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

reverberation.obj: ../reverberation.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="reverberation.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

sinewaves.obj: ../sinewaves.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="sinewaves.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

stereo.obj: ../stereo.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="stereo.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

tremolo.obj: ../tremolo.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="tremolo.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

usbstk5505.obj: ../usbstk5505.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="usbstk5505.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

usbstk5505_gpio.obj: ../usbstk5505_gpio.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="usbstk5505_gpio.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

usbstk5505_i2c.obj: ../usbstk5505_i2c.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="usbstk5505_i2c.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

usbstk5505_led.obj: ../usbstk5505_led.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="usbstk5505_led.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

usbstk5515.obj: ../usbstk5515.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="usbstk5515.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

usbstk5515_gpio.obj: ../usbstk5515_gpio.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="usbstk5515_gpio.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

usbstk5515_i2c.obj: ../usbstk5515_i2c.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="usbstk5515_i2c.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

usbstk5515_led.obj: ../usbstk5515_led.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="usbstk5515_led.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


