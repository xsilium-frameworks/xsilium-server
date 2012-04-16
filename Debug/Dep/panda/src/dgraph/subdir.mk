################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/dgraph/config_dgraph.cxx \
../Dep/panda/src/dgraph/dataGraphTraverser.cxx \
../Dep/panda/src/dgraph/dataNode.cxx \
../Dep/panda/src/dgraph/dataNodeTransmit.cxx \
../Dep/panda/src/dgraph/dgraph_composite.cxx \
../Dep/panda/src/dgraph/dgraph_composite1.cxx \
../Dep/panda/src/dgraph/dgraph_composite2.cxx 

OBJS += \
./Dep/panda/src/dgraph/config_dgraph.o \
./Dep/panda/src/dgraph/dataGraphTraverser.o \
./Dep/panda/src/dgraph/dataNode.o \
./Dep/panda/src/dgraph/dataNodeTransmit.o \
./Dep/panda/src/dgraph/dgraph_composite.o \
./Dep/panda/src/dgraph/dgraph_composite1.o \
./Dep/panda/src/dgraph/dgraph_composite2.o 

CXX_DEPS += \
./Dep/panda/src/dgraph/config_dgraph.d \
./Dep/panda/src/dgraph/dataGraphTraverser.d \
./Dep/panda/src/dgraph/dataNode.d \
./Dep/panda/src/dgraph/dataNodeTransmit.d \
./Dep/panda/src/dgraph/dgraph_composite.d \
./Dep/panda/src/dgraph/dgraph_composite1.d \
./Dep/panda/src/dgraph/dgraph_composite2.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/dgraph/%.o: ../Dep/panda/src/dgraph/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


