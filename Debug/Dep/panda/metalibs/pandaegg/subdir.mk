################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/metalibs/pandaegg/pandaegg.cxx \
../Dep/panda/metalibs/pandaegg/pandaeggnopg.cxx 

OBJS += \
./Dep/panda/metalibs/pandaegg/pandaegg.o \
./Dep/panda/metalibs/pandaegg/pandaeggnopg.o 

CXX_DEPS += \
./Dep/panda/metalibs/pandaegg/pandaegg.d \
./Dep/panda/metalibs/pandaegg/pandaeggnopg.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/metalibs/pandaegg/%.o: ../Dep/panda/metalibs/pandaegg/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


