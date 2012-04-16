################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/pstatclient/config_pstats.cxx \
../Dep/panda/src/pstatclient/pStatClient.cxx \
../Dep/panda/src/pstatclient/pStatClientControlMessage.cxx \
../Dep/panda/src/pstatclient/pStatClientImpl.cxx \
../Dep/panda/src/pstatclient/pStatClientVersion.cxx \
../Dep/panda/src/pstatclient/pStatCollectorDef.cxx \
../Dep/panda/src/pstatclient/pStatCollectorForward.cxx \
../Dep/panda/src/pstatclient/pStatFrameData.cxx \
../Dep/panda/src/pstatclient/pStatProperties.cxx \
../Dep/panda/src/pstatclient/pStatServerControlMessage.cxx \
../Dep/panda/src/pstatclient/pStatThread.cxx \
../Dep/panda/src/pstatclient/pstatclient_composite.cxx \
../Dep/panda/src/pstatclient/pstatclient_composite1.cxx \
../Dep/panda/src/pstatclient/pstatclient_composite2.cxx \
../Dep/panda/src/pstatclient/test_client.cxx 

OBJS += \
./Dep/panda/src/pstatclient/config_pstats.o \
./Dep/panda/src/pstatclient/pStatClient.o \
./Dep/panda/src/pstatclient/pStatClientControlMessage.o \
./Dep/panda/src/pstatclient/pStatClientImpl.o \
./Dep/panda/src/pstatclient/pStatClientVersion.o \
./Dep/panda/src/pstatclient/pStatCollectorDef.o \
./Dep/panda/src/pstatclient/pStatCollectorForward.o \
./Dep/panda/src/pstatclient/pStatFrameData.o \
./Dep/panda/src/pstatclient/pStatProperties.o \
./Dep/panda/src/pstatclient/pStatServerControlMessage.o \
./Dep/panda/src/pstatclient/pStatThread.o \
./Dep/panda/src/pstatclient/pstatclient_composite.o \
./Dep/panda/src/pstatclient/pstatclient_composite1.o \
./Dep/panda/src/pstatclient/pstatclient_composite2.o \
./Dep/panda/src/pstatclient/test_client.o 

CXX_DEPS += \
./Dep/panda/src/pstatclient/config_pstats.d \
./Dep/panda/src/pstatclient/pStatClient.d \
./Dep/panda/src/pstatclient/pStatClientControlMessage.d \
./Dep/panda/src/pstatclient/pStatClientImpl.d \
./Dep/panda/src/pstatclient/pStatClientVersion.d \
./Dep/panda/src/pstatclient/pStatCollectorDef.d \
./Dep/panda/src/pstatclient/pStatCollectorForward.d \
./Dep/panda/src/pstatclient/pStatFrameData.d \
./Dep/panda/src/pstatclient/pStatProperties.d \
./Dep/panda/src/pstatclient/pStatServerControlMessage.d \
./Dep/panda/src/pstatclient/pStatThread.d \
./Dep/panda/src/pstatclient/pstatclient_composite.d \
./Dep/panda/src/pstatclient/pstatclient_composite1.d \
./Dep/panda/src/pstatclient/pstatclient_composite2.d \
./Dep/panda/src/pstatclient/test_client.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/pstatclient/%.o: ../Dep/panda/src/pstatclient/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


