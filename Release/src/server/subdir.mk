################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/server/mainServer.cpp 

OBJS += \
./src/server/mainServer.o 

CPP_DEPS += \
./src/server/mainServer.d 


# Each subdirectory must supply rules for building sources it contributes
src/server/%.o: ../src/server/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep/Raknet" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


