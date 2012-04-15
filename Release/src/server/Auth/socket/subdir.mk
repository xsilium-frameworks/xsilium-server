################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/server/Auth/socket/AuthSocket.cpp 

OBJS += \
./src/server/Auth/socket/AuthSocket.o 

CPP_DEPS += \
./src/server/Auth/socket/AuthSocket.d 


# Each subdirectory must supply rules for building sources it contributes
src/server/Auth/socket/%.o: ../src/server/Auth/socket/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep/Raknet" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


