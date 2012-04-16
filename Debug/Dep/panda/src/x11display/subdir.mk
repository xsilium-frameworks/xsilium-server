################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/x11display/config_x11display.cxx \
../Dep/panda/src/x11display/x11GraphicsPipe.cxx \
../Dep/panda/src/x11display/x11GraphicsWindow.cxx \
../Dep/panda/src/x11display/x11display_composite.cxx \
../Dep/panda/src/x11display/x11display_composite1.cxx 

OBJS += \
./Dep/panda/src/x11display/config_x11display.o \
./Dep/panda/src/x11display/x11GraphicsPipe.o \
./Dep/panda/src/x11display/x11GraphicsWindow.o \
./Dep/panda/src/x11display/x11display_composite.o \
./Dep/panda/src/x11display/x11display_composite1.o 

CXX_DEPS += \
./Dep/panda/src/x11display/config_x11display.d \
./Dep/panda/src/x11display/x11GraphicsPipe.d \
./Dep/panda/src/x11display/x11GraphicsWindow.d \
./Dep/panda/src/x11display/x11display_composite.d \
./Dep/panda/src/x11display/x11display_composite1.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/x11display/%.o: ../Dep/panda/src/x11display/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


