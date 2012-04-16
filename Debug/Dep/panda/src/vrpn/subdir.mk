################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/vrpn/config_vrpn.cxx \
../Dep/panda/src/vrpn/vrpnAnalog.cxx \
../Dep/panda/src/vrpn/vrpnAnalogDevice.cxx \
../Dep/panda/src/vrpn/vrpnButton.cxx \
../Dep/panda/src/vrpn/vrpnButtonDevice.cxx \
../Dep/panda/src/vrpn/vrpnClient.cxx \
../Dep/panda/src/vrpn/vrpnDial.cxx \
../Dep/panda/src/vrpn/vrpnDialDevice.cxx \
../Dep/panda/src/vrpn/vrpnTracker.cxx \
../Dep/panda/src/vrpn/vrpnTrackerDevice.cxx \
../Dep/panda/src/vrpn/vrpn_composite.cxx \
../Dep/panda/src/vrpn/vrpn_composite1.cxx 

OBJS += \
./Dep/panda/src/vrpn/config_vrpn.o \
./Dep/panda/src/vrpn/vrpnAnalog.o \
./Dep/panda/src/vrpn/vrpnAnalogDevice.o \
./Dep/panda/src/vrpn/vrpnButton.o \
./Dep/panda/src/vrpn/vrpnButtonDevice.o \
./Dep/panda/src/vrpn/vrpnClient.o \
./Dep/panda/src/vrpn/vrpnDial.o \
./Dep/panda/src/vrpn/vrpnDialDevice.o \
./Dep/panda/src/vrpn/vrpnTracker.o \
./Dep/panda/src/vrpn/vrpnTrackerDevice.o \
./Dep/panda/src/vrpn/vrpn_composite.o \
./Dep/panda/src/vrpn/vrpn_composite1.o 

CXX_DEPS += \
./Dep/panda/src/vrpn/config_vrpn.d \
./Dep/panda/src/vrpn/vrpnAnalog.d \
./Dep/panda/src/vrpn/vrpnAnalogDevice.d \
./Dep/panda/src/vrpn/vrpnButton.d \
./Dep/panda/src/vrpn/vrpnButtonDevice.d \
./Dep/panda/src/vrpn/vrpnClient.d \
./Dep/panda/src/vrpn/vrpnDial.d \
./Dep/panda/src/vrpn/vrpnDialDevice.d \
./Dep/panda/src/vrpn/vrpnTracker.d \
./Dep/panda/src/vrpn/vrpnTrackerDevice.d \
./Dep/panda/src/vrpn/vrpn_composite.d \
./Dep/panda/src/vrpn/vrpn_composite1.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/vrpn/%.o: ../Dep/panda/src/vrpn/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


