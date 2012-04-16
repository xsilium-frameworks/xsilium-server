################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/gles2gsg/config_gles2gsg.cxx \
../Dep/panda/src/gles2gsg/gles2gsg.cxx \
../Dep/panda/src/gles2gsg/gles2gsg_composite.cxx \
../Dep/panda/src/gles2gsg/gles2gsg_composite1.cxx 

OBJS += \
./Dep/panda/src/gles2gsg/config_gles2gsg.o \
./Dep/panda/src/gles2gsg/gles2gsg.o \
./Dep/panda/src/gles2gsg/gles2gsg_composite.o \
./Dep/panda/src/gles2gsg/gles2gsg_composite1.o 

CXX_DEPS += \
./Dep/panda/src/gles2gsg/config_gles2gsg.d \
./Dep/panda/src/gles2gsg/gles2gsg.d \
./Dep/panda/src/gles2gsg/gles2gsg_composite.d \
./Dep/panda/src/gles2gsg/gles2gsg_composite1.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/gles2gsg/%.o: ../Dep/panda/src/gles2gsg/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


