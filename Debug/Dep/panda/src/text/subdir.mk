################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dep/panda/src/text/cmss12.bam.c \
../Dep/panda/src/text/cmss12.bam.pz.c \
../Dep/panda/src/text/persans.ttf.c 

CXX_SRCS += \
../Dep/panda/src/text/config_text.cxx \
../Dep/panda/src/text/default_font.cxx \
../Dep/panda/src/text/dynamicTextFont.cxx \
../Dep/panda/src/text/dynamicTextGlyph.cxx \
../Dep/panda/src/text/dynamicTextPage.cxx \
../Dep/panda/src/text/fontPool.cxx \
../Dep/panda/src/text/geomTextGlyph.cxx \
../Dep/panda/src/text/staticTextFont.cxx \
../Dep/panda/src/text/textAssembler.cxx \
../Dep/panda/src/text/textFont.cxx \
../Dep/panda/src/text/textGlyph.cxx \
../Dep/panda/src/text/textGraphic.cxx \
../Dep/panda/src/text/textNode.cxx \
../Dep/panda/src/text/textProperties.cxx \
../Dep/panda/src/text/textPropertiesManager.cxx \
../Dep/panda/src/text/text_composite.cxx \
../Dep/panda/src/text/text_composite1.cxx \
../Dep/panda/src/text/text_composite2.cxx 

OBJS += \
./Dep/panda/src/text/cmss12.bam.o \
./Dep/panda/src/text/cmss12.bam.pz.o \
./Dep/panda/src/text/config_text.o \
./Dep/panda/src/text/default_font.o \
./Dep/panda/src/text/dynamicTextFont.o \
./Dep/panda/src/text/dynamicTextGlyph.o \
./Dep/panda/src/text/dynamicTextPage.o \
./Dep/panda/src/text/fontPool.o \
./Dep/panda/src/text/geomTextGlyph.o \
./Dep/panda/src/text/persans.ttf.o \
./Dep/panda/src/text/staticTextFont.o \
./Dep/panda/src/text/textAssembler.o \
./Dep/panda/src/text/textFont.o \
./Dep/panda/src/text/textGlyph.o \
./Dep/panda/src/text/textGraphic.o \
./Dep/panda/src/text/textNode.o \
./Dep/panda/src/text/textProperties.o \
./Dep/panda/src/text/textPropertiesManager.o \
./Dep/panda/src/text/text_composite.o \
./Dep/panda/src/text/text_composite1.o \
./Dep/panda/src/text/text_composite2.o 

C_DEPS += \
./Dep/panda/src/text/cmss12.bam.d \
./Dep/panda/src/text/cmss12.bam.pz.d \
./Dep/panda/src/text/persans.ttf.d 

CXX_DEPS += \
./Dep/panda/src/text/config_text.d \
./Dep/panda/src/text/default_font.d \
./Dep/panda/src/text/dynamicTextFont.d \
./Dep/panda/src/text/dynamicTextGlyph.d \
./Dep/panda/src/text/dynamicTextPage.d \
./Dep/panda/src/text/fontPool.d \
./Dep/panda/src/text/geomTextGlyph.d \
./Dep/panda/src/text/staticTextFont.d \
./Dep/panda/src/text/textAssembler.d \
./Dep/panda/src/text/textFont.d \
./Dep/panda/src/text/textGlyph.d \
./Dep/panda/src/text/textGraphic.d \
./Dep/panda/src/text/textNode.d \
./Dep/panda/src/text/textProperties.d \
./Dep/panda/src/text/textPropertiesManager.d \
./Dep/panda/src/text/text_composite.d \
./Dep/panda/src/text/text_composite1.d \
./Dep/panda/src/text/text_composite2.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/text/%.o: ../Dep/panda/src/text/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Dep/panda/src/text/%.o: ../Dep/panda/src/text/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


