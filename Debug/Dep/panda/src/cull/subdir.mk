################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/cull/binCullHandler.cxx \
../Dep/panda/src/cull/config_cull.cxx \
../Dep/panda/src/cull/cullBinBackToFront.cxx \
../Dep/panda/src/cull/cullBinFixed.cxx \
../Dep/panda/src/cull/cullBinFrontToBack.cxx \
../Dep/panda/src/cull/cullBinStateSorted.cxx \
../Dep/panda/src/cull/cullBinUnsorted.cxx \
../Dep/panda/src/cull/cull_composite.cxx \
../Dep/panda/src/cull/cull_composite1.cxx \
../Dep/panda/src/cull/cull_composite2.cxx \
../Dep/panda/src/cull/drawCullHandler.cxx 

OBJS += \
./Dep/panda/src/cull/binCullHandler.o \
./Dep/panda/src/cull/config_cull.o \
./Dep/panda/src/cull/cullBinBackToFront.o \
./Dep/panda/src/cull/cullBinFixed.o \
./Dep/panda/src/cull/cullBinFrontToBack.o \
./Dep/panda/src/cull/cullBinStateSorted.o \
./Dep/panda/src/cull/cullBinUnsorted.o \
./Dep/panda/src/cull/cull_composite.o \
./Dep/panda/src/cull/cull_composite1.o \
./Dep/panda/src/cull/cull_composite2.o \
./Dep/panda/src/cull/drawCullHandler.o 

CXX_DEPS += \
./Dep/panda/src/cull/binCullHandler.d \
./Dep/panda/src/cull/config_cull.d \
./Dep/panda/src/cull/cullBinBackToFront.d \
./Dep/panda/src/cull/cullBinFixed.d \
./Dep/panda/src/cull/cullBinFrontToBack.d \
./Dep/panda/src/cull/cullBinStateSorted.d \
./Dep/panda/src/cull/cullBinUnsorted.d \
./Dep/panda/src/cull/cull_composite.d \
./Dep/panda/src/cull/cull_composite1.d \
./Dep/panda/src/cull/cull_composite2.d \
./Dep/panda/src/cull/drawCullHandler.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/cull/%.o: ../Dep/panda/src/cull/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


