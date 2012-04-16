################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/distort/config_distort.cxx \
../Dep/panda/src/distort/cylindricalLens.cxx \
../Dep/panda/src/distort/distort_composite.cxx \
../Dep/panda/src/distort/distort_composite1.cxx \
../Dep/panda/src/distort/fisheyeLens.cxx \
../Dep/panda/src/distort/nonlinearImager.cxx \
../Dep/panda/src/distort/pSphereLens.cxx \
../Dep/panda/src/distort/projectionScreen.cxx 

OBJS += \
./Dep/panda/src/distort/config_distort.o \
./Dep/panda/src/distort/cylindricalLens.o \
./Dep/panda/src/distort/distort_composite.o \
./Dep/panda/src/distort/distort_composite1.o \
./Dep/panda/src/distort/fisheyeLens.o \
./Dep/panda/src/distort/nonlinearImager.o \
./Dep/panda/src/distort/pSphereLens.o \
./Dep/panda/src/distort/projectionScreen.o 

CXX_DEPS += \
./Dep/panda/src/distort/config_distort.d \
./Dep/panda/src/distort/cylindricalLens.d \
./Dep/panda/src/distort/distort_composite.d \
./Dep/panda/src/distort/distort_composite1.d \
./Dep/panda/src/distort/fisheyeLens.d \
./Dep/panda/src/distort/nonlinearImager.d \
./Dep/panda/src/distort/pSphereLens.d \
./Dep/panda/src/distort/projectionScreen.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/distort/%.o: ../Dep/panda/src/distort/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


