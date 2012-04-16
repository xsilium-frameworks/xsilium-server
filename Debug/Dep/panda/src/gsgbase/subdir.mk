################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/gsgbase/config_gsgbase.cxx \
../Dep/panda/src/gsgbase/displayRegionBase.cxx \
../Dep/panda/src/gsgbase/graphicsOutputBase.cxx \
../Dep/panda/src/gsgbase/graphicsStateGuardianBase.cxx \
../Dep/panda/src/gsgbase/gsgbase_composite.cxx \
../Dep/panda/src/gsgbase/gsgbase_composite1.cxx \
../Dep/panda/src/gsgbase/test_gsgbase.cxx 

OBJS += \
./Dep/panda/src/gsgbase/config_gsgbase.o \
./Dep/panda/src/gsgbase/displayRegionBase.o \
./Dep/panda/src/gsgbase/graphicsOutputBase.o \
./Dep/panda/src/gsgbase/graphicsStateGuardianBase.o \
./Dep/panda/src/gsgbase/gsgbase_composite.o \
./Dep/panda/src/gsgbase/gsgbase_composite1.o \
./Dep/panda/src/gsgbase/test_gsgbase.o 

CXX_DEPS += \
./Dep/panda/src/gsgbase/config_gsgbase.d \
./Dep/panda/src/gsgbase/displayRegionBase.d \
./Dep/panda/src/gsgbase/graphicsOutputBase.d \
./Dep/panda/src/gsgbase/graphicsStateGuardianBase.d \
./Dep/panda/src/gsgbase/gsgbase_composite.d \
./Dep/panda/src/gsgbase/gsgbase_composite1.d \
./Dep/panda/src/gsgbase/test_gsgbase.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/gsgbase/%.o: ../Dep/panda/src/gsgbase/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


