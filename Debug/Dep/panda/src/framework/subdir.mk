################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dep/panda/src/framework/rock_floor.rgb.c \
../Dep/panda/src/framework/shuttle_controls.bam.c 

CXX_SRCS += \
../Dep/panda/src/framework/config_framework.cxx \
../Dep/panda/src/framework/framework_composite.cxx \
../Dep/panda/src/framework/framework_composite1.cxx \
../Dep/panda/src/framework/pandaFramework.cxx \
../Dep/panda/src/framework/windowFramework.cxx 

OBJS += \
./Dep/panda/src/framework/config_framework.o \
./Dep/panda/src/framework/framework_composite.o \
./Dep/panda/src/framework/framework_composite1.o \
./Dep/panda/src/framework/pandaFramework.o \
./Dep/panda/src/framework/rock_floor.rgb.o \
./Dep/panda/src/framework/shuttle_controls.bam.o \
./Dep/panda/src/framework/windowFramework.o 

C_DEPS += \
./Dep/panda/src/framework/rock_floor.rgb.d \
./Dep/panda/src/framework/shuttle_controls.bam.d 

CXX_DEPS += \
./Dep/panda/src/framework/config_framework.d \
./Dep/panda/src/framework/framework_composite.d \
./Dep/panda/src/framework/framework_composite1.d \
./Dep/panda/src/framework/pandaFramework.d \
./Dep/panda/src/framework/windowFramework.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/framework/%.o: ../Dep/panda/src/framework/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Dep/panda/src/framework/%.o: ../Dep/panda/src/framework/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


