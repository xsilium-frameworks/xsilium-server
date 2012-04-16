################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/glxdisplay/config_glxdisplay.cxx \
../Dep/panda/src/glxdisplay/glxGraphicsBuffer.cxx \
../Dep/panda/src/glxdisplay/glxGraphicsPipe.cxx \
../Dep/panda/src/glxdisplay/glxGraphicsPixmap.cxx \
../Dep/panda/src/glxdisplay/glxGraphicsStateGuardian.cxx \
../Dep/panda/src/glxdisplay/glxGraphicsWindow.cxx \
../Dep/panda/src/glxdisplay/glxdisplay_composite.cxx \
../Dep/panda/src/glxdisplay/glxdisplay_composite1.cxx 

OBJS += \
./Dep/panda/src/glxdisplay/config_glxdisplay.o \
./Dep/panda/src/glxdisplay/glxGraphicsBuffer.o \
./Dep/panda/src/glxdisplay/glxGraphicsPipe.o \
./Dep/panda/src/glxdisplay/glxGraphicsPixmap.o \
./Dep/panda/src/glxdisplay/glxGraphicsStateGuardian.o \
./Dep/panda/src/glxdisplay/glxGraphicsWindow.o \
./Dep/panda/src/glxdisplay/glxdisplay_composite.o \
./Dep/panda/src/glxdisplay/glxdisplay_composite1.o 

CXX_DEPS += \
./Dep/panda/src/glxdisplay/config_glxdisplay.d \
./Dep/panda/src/glxdisplay/glxGraphicsBuffer.d \
./Dep/panda/src/glxdisplay/glxGraphicsPipe.d \
./Dep/panda/src/glxdisplay/glxGraphicsPixmap.d \
./Dep/panda/src/glxdisplay/glxGraphicsStateGuardian.d \
./Dep/panda/src/glxdisplay/glxGraphicsWindow.d \
./Dep/panda/src/glxdisplay/glxdisplay_composite.d \
./Dep/panda/src/glxdisplay/glxdisplay_composite1.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/glxdisplay/%.o: ../Dep/panda/src/glxdisplay/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


