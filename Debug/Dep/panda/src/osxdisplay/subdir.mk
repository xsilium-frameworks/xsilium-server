################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dep/panda/src/osxdisplay/resize_box.rgb.c 

CXX_SRCS += \
../Dep/panda/src/osxdisplay/config_osxdisplay.cxx \
../Dep/panda/src/osxdisplay/osxGraphicsBuffer.cxx \
../Dep/panda/src/osxdisplay/osxGraphicsPipe.cxx \
../Dep/panda/src/osxdisplay/osxGraphicsStateGuardian.cxx \
../Dep/panda/src/osxdisplay/osxdisplay_composite1.cxx 

OBJS += \
./Dep/panda/src/osxdisplay/config_osxdisplay.o \
./Dep/panda/src/osxdisplay/osxGraphicsBuffer.o \
./Dep/panda/src/osxdisplay/osxGraphicsPipe.o \
./Dep/panda/src/osxdisplay/osxGraphicsStateGuardian.o \
./Dep/panda/src/osxdisplay/osxdisplay_composite1.o \
./Dep/panda/src/osxdisplay/resize_box.rgb.o 

C_DEPS += \
./Dep/panda/src/osxdisplay/resize_box.rgb.d 

CXX_DEPS += \
./Dep/panda/src/osxdisplay/config_osxdisplay.d \
./Dep/panda/src/osxdisplay/osxGraphicsBuffer.d \
./Dep/panda/src/osxdisplay/osxGraphicsPipe.d \
./Dep/panda/src/osxdisplay/osxGraphicsStateGuardian.d \
./Dep/panda/src/osxdisplay/osxdisplay_composite1.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/osxdisplay/%.o: ../Dep/panda/src/osxdisplay/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Dep/panda/src/osxdisplay/%.o: ../Dep/panda/src/osxdisplay/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


