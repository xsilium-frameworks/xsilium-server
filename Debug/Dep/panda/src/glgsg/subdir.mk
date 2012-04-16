################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/glgsg/config_glgsg.cxx \
../Dep/panda/src/glgsg/glgsg.cxx \
../Dep/panda/src/glgsg/glgsg_composite.cxx \
../Dep/panda/src/glgsg/glgsg_composite1.cxx 

OBJS += \
./Dep/panda/src/glgsg/config_glgsg.o \
./Dep/panda/src/glgsg/glgsg.o \
./Dep/panda/src/glgsg/glgsg_composite.o \
./Dep/panda/src/glgsg/glgsg_composite1.o 

CXX_DEPS += \
./Dep/panda/src/glgsg/config_glgsg.d \
./Dep/panda/src/glgsg/glgsg.d \
./Dep/panda/src/glgsg/glgsg_composite.d \
./Dep/panda/src/glgsg/glgsg_composite1.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/glgsg/%.o: ../Dep/panda/src/glgsg/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


