################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/egldisplay/config_egldisplay.cxx \
../Dep/panda/src/egldisplay/eglGraphicsBuffer.cxx \
../Dep/panda/src/egldisplay/eglGraphicsPipe.cxx \
../Dep/panda/src/egldisplay/eglGraphicsPixmap.cxx \
../Dep/panda/src/egldisplay/eglGraphicsStateGuardian.cxx \
../Dep/panda/src/egldisplay/eglGraphicsWindow.cxx \
../Dep/panda/src/egldisplay/egldisplay_composite1.cxx 

OBJS += \
./Dep/panda/src/egldisplay/config_egldisplay.o \
./Dep/panda/src/egldisplay/eglGraphicsBuffer.o \
./Dep/panda/src/egldisplay/eglGraphicsPipe.o \
./Dep/panda/src/egldisplay/eglGraphicsPixmap.o \
./Dep/panda/src/egldisplay/eglGraphicsStateGuardian.o \
./Dep/panda/src/egldisplay/eglGraphicsWindow.o \
./Dep/panda/src/egldisplay/egldisplay_composite1.o 

CXX_DEPS += \
./Dep/panda/src/egldisplay/config_egldisplay.d \
./Dep/panda/src/egldisplay/eglGraphicsBuffer.d \
./Dep/panda/src/egldisplay/eglGraphicsPipe.d \
./Dep/panda/src/egldisplay/eglGraphicsPixmap.d \
./Dep/panda/src/egldisplay/eglGraphicsStateGuardian.d \
./Dep/panda/src/egldisplay/eglGraphicsWindow.d \
./Dep/panda/src/egldisplay/egldisplay_composite1.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/egldisplay/%.o: ../Dep/panda/src/egldisplay/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


