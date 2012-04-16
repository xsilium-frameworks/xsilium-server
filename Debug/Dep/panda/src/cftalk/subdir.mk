################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/cftalk/cfChannel.cxx \
../Dep/panda/src/cftalk/cfCommand.cxx \
../Dep/panda/src/cftalk/cftalk_composite1.cxx \
../Dep/panda/src/cftalk/cftalk_composite2.cxx \
../Dep/panda/src/cftalk/config_cftalk.cxx 

OBJS += \
./Dep/panda/src/cftalk/cfChannel.o \
./Dep/panda/src/cftalk/cfCommand.o \
./Dep/panda/src/cftalk/cftalk_composite1.o \
./Dep/panda/src/cftalk/cftalk_composite2.o \
./Dep/panda/src/cftalk/config_cftalk.o 

CXX_DEPS += \
./Dep/panda/src/cftalk/cfChannel.d \
./Dep/panda/src/cftalk/cfCommand.d \
./Dep/panda/src/cftalk/cftalk_composite1.d \
./Dep/panda/src/cftalk/cftalk_composite2.d \
./Dep/panda/src/cftalk/config_cftalk.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/cftalk/%.o: ../Dep/panda/src/cftalk/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


