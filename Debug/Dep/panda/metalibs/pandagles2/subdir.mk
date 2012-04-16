################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/metalibs/pandagles2/pandagles2.cxx 

OBJS += \
./Dep/panda/metalibs/pandagles2/pandagles2.o 

CXX_DEPS += \
./Dep/panda/metalibs/pandagles2/pandagles2.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/metalibs/pandagles2/%.o: ../Dep/panda/metalibs/pandagles2/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


