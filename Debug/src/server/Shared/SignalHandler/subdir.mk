################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/server/Shared/SignalHandler/SignalHandler.cpp 

OBJS += \
./src/server/Shared/SignalHandler/SignalHandler.o 

CPP_DEPS += \
./src/server/Shared/SignalHandler/SignalHandler.d 


# Each subdirectory must supply rules for building sources it contributes
src/server/Shared/SignalHandler/%.o: ../src/server/Shared/SignalHandler/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda/workspace/xsilium/Dep/Raknet" -I"/Users/joda/workspace/xsilium/Dep" -I"/Users/joda/workspace/xsilium/src/server/Shared" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


