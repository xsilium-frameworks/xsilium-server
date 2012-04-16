################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/pnmtext/config_pnmtext.cxx \
../Dep/panda/src/pnmtext/freetypeFace.cxx \
../Dep/panda/src/pnmtext/freetypeFont.cxx \
../Dep/panda/src/pnmtext/pnmTextGlyph.cxx \
../Dep/panda/src/pnmtext/pnmTextMaker.cxx \
../Dep/panda/src/pnmtext/pnmtext_composite.cxx \
../Dep/panda/src/pnmtext/pnmtext_composite1.cxx 

OBJS += \
./Dep/panda/src/pnmtext/config_pnmtext.o \
./Dep/panda/src/pnmtext/freetypeFace.o \
./Dep/panda/src/pnmtext/freetypeFont.o \
./Dep/panda/src/pnmtext/pnmTextGlyph.o \
./Dep/panda/src/pnmtext/pnmTextMaker.o \
./Dep/panda/src/pnmtext/pnmtext_composite.o \
./Dep/panda/src/pnmtext/pnmtext_composite1.o 

CXX_DEPS += \
./Dep/panda/src/pnmtext/config_pnmtext.d \
./Dep/panda/src/pnmtext/freetypeFace.d \
./Dep/panda/src/pnmtext/freetypeFont.d \
./Dep/panda/src/pnmtext/pnmTextGlyph.d \
./Dep/panda/src/pnmtext/pnmTextMaker.d \
./Dep/panda/src/pnmtext/pnmtext_composite.d \
./Dep/panda/src/pnmtext/pnmtext_composite1.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/pnmtext/%.o: ../Dep/panda/src/pnmtext/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


