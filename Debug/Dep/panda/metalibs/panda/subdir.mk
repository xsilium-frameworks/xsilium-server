################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/metalibs/panda/panda.cxx 

OBJS += \
./Dep/panda/metalibs/panda/panda.o 

CXX_DEPS += \
./Dep/panda/metalibs/panda/panda.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/metalibs/panda/%.o: ../Dep/panda/metalibs/panda/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


