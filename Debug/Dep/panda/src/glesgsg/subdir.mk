################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/glesgsg/config_glesgsg.cxx \
../Dep/panda/src/glesgsg/glesgsg.cxx \
../Dep/panda/src/glesgsg/glesgsg_composite.cxx \
../Dep/panda/src/glesgsg/glesgsg_composite1.cxx 

OBJS += \
./Dep/panda/src/glesgsg/config_glesgsg.o \
./Dep/panda/src/glesgsg/glesgsg.o \
./Dep/panda/src/glesgsg/glesgsg_composite.o \
./Dep/panda/src/glesgsg/glesgsg_composite1.o 

CXX_DEPS += \
./Dep/panda/src/glesgsg/config_glesgsg.d \
./Dep/panda/src/glesgsg/glesgsg.d \
./Dep/panda/src/glesgsg/glesgsg_composite.d \
./Dep/panda/src/glesgsg/glesgsg_composite1.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/glesgsg/%.o: ../Dep/panda/src/glesgsg/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


