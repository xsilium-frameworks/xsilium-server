################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/mesadisplay/config_mesadisplay.cxx \
../Dep/panda/src/mesadisplay/mesadisplay_composite.cxx \
../Dep/panda/src/mesadisplay/mesadisplay_composite1.cxx \
../Dep/panda/src/mesadisplay/mesagsg.cxx \
../Dep/panda/src/mesadisplay/osMesaGraphicsBuffer.cxx \
../Dep/panda/src/mesadisplay/osMesaGraphicsPipe.cxx \
../Dep/panda/src/mesadisplay/osMesaGraphicsStateGuardian.cxx 

OBJS += \
./Dep/panda/src/mesadisplay/config_mesadisplay.o \
./Dep/panda/src/mesadisplay/mesadisplay_composite.o \
./Dep/panda/src/mesadisplay/mesadisplay_composite1.o \
./Dep/panda/src/mesadisplay/mesagsg.o \
./Dep/panda/src/mesadisplay/osMesaGraphicsBuffer.o \
./Dep/panda/src/mesadisplay/osMesaGraphicsPipe.o \
./Dep/panda/src/mesadisplay/osMesaGraphicsStateGuardian.o 

CXX_DEPS += \
./Dep/panda/src/mesadisplay/config_mesadisplay.d \
./Dep/panda/src/mesadisplay/mesadisplay_composite.d \
./Dep/panda/src/mesadisplay/mesadisplay_composite1.d \
./Dep/panda/src/mesadisplay/mesagsg.d \
./Dep/panda/src/mesadisplay/osMesaGraphicsBuffer.d \
./Dep/panda/src/mesadisplay/osMesaGraphicsPipe.d \
./Dep/panda/src/mesadisplay/osMesaGraphicsStateGuardian.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/mesadisplay/%.o: ../Dep/panda/src/mesadisplay/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


