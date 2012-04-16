################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/testbed/pgrid.cxx \
../Dep/panda/src/testbed/pview.cxx \
../Dep/panda/src/testbed/test_lod.cxx \
../Dep/panda/src/testbed/test_map.cxx \
../Dep/panda/src/testbed/test_texmem.cxx \
../Dep/panda/src/testbed/text_test.cxx 

OBJS += \
./Dep/panda/src/testbed/pgrid.o \
./Dep/panda/src/testbed/pview.o \
./Dep/panda/src/testbed/test_lod.o \
./Dep/panda/src/testbed/test_map.o \
./Dep/panda/src/testbed/test_texmem.o \
./Dep/panda/src/testbed/text_test.o 

CXX_DEPS += \
./Dep/panda/src/testbed/pgrid.d \
./Dep/panda/src/testbed/pview.d \
./Dep/panda/src/testbed/test_lod.d \
./Dep/panda/src/testbed/test_map.d \
./Dep/panda/src/testbed/test_texmem.d \
./Dep/panda/src/testbed/text_test.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/testbed/%.o: ../Dep/panda/src/testbed/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


