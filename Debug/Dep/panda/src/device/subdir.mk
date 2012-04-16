################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/device/analogNode.cxx \
../Dep/panda/src/device/buttonNode.cxx \
../Dep/panda/src/device/clientAnalogDevice.cxx \
../Dep/panda/src/device/clientBase.cxx \
../Dep/panda/src/device/clientButtonDevice.cxx \
../Dep/panda/src/device/clientDevice.cxx \
../Dep/panda/src/device/clientDialDevice.cxx \
../Dep/panda/src/device/clientTrackerDevice.cxx \
../Dep/panda/src/device/config_device.cxx \
../Dep/panda/src/device/device_composite.cxx \
../Dep/panda/src/device/device_composite1.cxx \
../Dep/panda/src/device/device_composite2.cxx \
../Dep/panda/src/device/dialNode.cxx \
../Dep/panda/src/device/mouseAndKeyboard.cxx \
../Dep/panda/src/device/trackerData.cxx \
../Dep/panda/src/device/trackerNode.cxx \
../Dep/panda/src/device/virtualMouse.cxx 

OBJS += \
./Dep/panda/src/device/analogNode.o \
./Dep/panda/src/device/buttonNode.o \
./Dep/panda/src/device/clientAnalogDevice.o \
./Dep/panda/src/device/clientBase.o \
./Dep/panda/src/device/clientButtonDevice.o \
./Dep/panda/src/device/clientDevice.o \
./Dep/panda/src/device/clientDialDevice.o \
./Dep/panda/src/device/clientTrackerDevice.o \
./Dep/panda/src/device/config_device.o \
./Dep/panda/src/device/device_composite.o \
./Dep/panda/src/device/device_composite1.o \
./Dep/panda/src/device/device_composite2.o \
./Dep/panda/src/device/dialNode.o \
./Dep/panda/src/device/mouseAndKeyboard.o \
./Dep/panda/src/device/trackerData.o \
./Dep/panda/src/device/trackerNode.o \
./Dep/panda/src/device/virtualMouse.o 

CXX_DEPS += \
./Dep/panda/src/device/analogNode.d \
./Dep/panda/src/device/buttonNode.d \
./Dep/panda/src/device/clientAnalogDevice.d \
./Dep/panda/src/device/clientBase.d \
./Dep/panda/src/device/clientButtonDevice.d \
./Dep/panda/src/device/clientDevice.d \
./Dep/panda/src/device/clientDialDevice.d \
./Dep/panda/src/device/clientTrackerDevice.d \
./Dep/panda/src/device/config_device.d \
./Dep/panda/src/device/device_composite.d \
./Dep/panda/src/device/device_composite1.d \
./Dep/panda/src/device/device_composite2.d \
./Dep/panda/src/device/dialNode.d \
./Dep/panda/src/device/mouseAndKeyboard.d \
./Dep/panda/src/device/trackerData.d \
./Dep/panda/src/device/trackerNode.d \
./Dep/panda/src/device/virtualMouse.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/device/%.o: ../Dep/panda/src/device/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


