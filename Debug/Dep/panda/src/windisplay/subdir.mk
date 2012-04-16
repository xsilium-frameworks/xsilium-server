################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/windisplay/config_windisplay.cxx \
../Dep/panda/src/windisplay/winDetectDx8.cxx \
../Dep/panda/src/windisplay/winDetectDx9.cxx \
../Dep/panda/src/windisplay/winGraphicsPipe.cxx \
../Dep/panda/src/windisplay/winGraphicsWindow.cxx \
../Dep/panda/src/windisplay/windisplay_composite.cxx \
../Dep/panda/src/windisplay/windisplay_composite1.cxx 

OBJS += \
./Dep/panda/src/windisplay/config_windisplay.o \
./Dep/panda/src/windisplay/winDetectDx8.o \
./Dep/panda/src/windisplay/winDetectDx9.o \
./Dep/panda/src/windisplay/winGraphicsPipe.o \
./Dep/panda/src/windisplay/winGraphicsWindow.o \
./Dep/panda/src/windisplay/windisplay_composite.o \
./Dep/panda/src/windisplay/windisplay_composite1.o 

CXX_DEPS += \
./Dep/panda/src/windisplay/config_windisplay.d \
./Dep/panda/src/windisplay/winDetectDx8.d \
./Dep/panda/src/windisplay/winDetectDx9.d \
./Dep/panda/src/windisplay/winGraphicsPipe.d \
./Dep/panda/src/windisplay/winGraphicsWindow.d \
./Dep/panda/src/windisplay/windisplay_composite.d \
./Dep/panda/src/windisplay/windisplay_composite1.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/windisplay/%.o: ../Dep/panda/src/windisplay/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


