################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/skel/basicSkel.cxx \
../Dep/panda/src/skel/config_skel.cxx \
../Dep/panda/src/skel/skel_composite.cxx \
../Dep/panda/src/skel/skel_composite1.cxx \
../Dep/panda/src/skel/typedSkel.cxx 

OBJS += \
./Dep/panda/src/skel/basicSkel.o \
./Dep/panda/src/skel/config_skel.o \
./Dep/panda/src/skel/skel_composite.o \
./Dep/panda/src/skel/skel_composite1.o \
./Dep/panda/src/skel/typedSkel.o 

CXX_DEPS += \
./Dep/panda/src/skel/basicSkel.d \
./Dep/panda/src/skel/config_skel.d \
./Dep/panda/src/skel/skel_composite.d \
./Dep/panda/src/skel/skel_composite1.d \
./Dep/panda/src/skel/typedSkel.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/skel/%.o: ../Dep/panda/src/skel/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


