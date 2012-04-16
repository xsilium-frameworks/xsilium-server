################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/effects/config_effects.cxx \
../Dep/panda/src/effects/effects_composite.cxx \
../Dep/panda/src/effects/effects_composite1.cxx \
../Dep/panda/src/effects/lensFlareNode.cxx 

OBJS += \
./Dep/panda/src/effects/config_effects.o \
./Dep/panda/src/effects/effects_composite.o \
./Dep/panda/src/effects/effects_composite1.o \
./Dep/panda/src/effects/lensFlareNode.o 

CXX_DEPS += \
./Dep/panda/src/effects/config_effects.d \
./Dep/panda/src/effects/effects_composite.d \
./Dep/panda/src/effects/effects_composite1.d \
./Dep/panda/src/effects/lensFlareNode.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/effects/%.o: ../Dep/panda/src/effects/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


