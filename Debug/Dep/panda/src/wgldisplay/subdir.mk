################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/wgldisplay/config_wgldisplay.cxx \
../Dep/panda/src/wgldisplay/wglGraphicsBuffer.cxx \
../Dep/panda/src/wgldisplay/wglGraphicsPipe.cxx \
../Dep/panda/src/wgldisplay/wglGraphicsStateGuardian.cxx \
../Dep/panda/src/wgldisplay/wglGraphicsWindow.cxx \
../Dep/panda/src/wgldisplay/wgldisplay_composite.cxx \
../Dep/panda/src/wgldisplay/wgldisplay_composite1.cxx 

OBJS += \
./Dep/panda/src/wgldisplay/config_wgldisplay.o \
./Dep/panda/src/wgldisplay/wglGraphicsBuffer.o \
./Dep/panda/src/wgldisplay/wglGraphicsPipe.o \
./Dep/panda/src/wgldisplay/wglGraphicsStateGuardian.o \
./Dep/panda/src/wgldisplay/wglGraphicsWindow.o \
./Dep/panda/src/wgldisplay/wgldisplay_composite.o \
./Dep/panda/src/wgldisplay/wgldisplay_composite1.o 

CXX_DEPS += \
./Dep/panda/src/wgldisplay/config_wgldisplay.d \
./Dep/panda/src/wgldisplay/wglGraphicsBuffer.d \
./Dep/panda/src/wgldisplay/wglGraphicsPipe.d \
./Dep/panda/src/wgldisplay/wglGraphicsStateGuardian.d \
./Dep/panda/src/wgldisplay/wglGraphicsWindow.d \
./Dep/panda/src/wgldisplay/wgldisplay_composite.d \
./Dep/panda/src/wgldisplay/wgldisplay_composite1.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/wgldisplay/%.o: ../Dep/panda/src/wgldisplay/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


