################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/tform/buttonThrower.cxx \
../Dep/panda/src/tform/config_tform.cxx \
../Dep/panda/src/tform/driveInterface.cxx \
../Dep/panda/src/tform/mouseInterfaceNode.cxx \
../Dep/panda/src/tform/mouseSubregion.cxx \
../Dep/panda/src/tform/mouseWatcher.cxx \
../Dep/panda/src/tform/mouseWatcherGroup.cxx \
../Dep/panda/src/tform/mouseWatcherParameter.cxx \
../Dep/panda/src/tform/mouseWatcherRegion.cxx \
../Dep/panda/src/tform/tform_composite.cxx \
../Dep/panda/src/tform/tform_composite1.cxx \
../Dep/panda/src/tform/tform_composite2.cxx \
../Dep/panda/src/tform/trackball.cxx \
../Dep/panda/src/tform/transform2sg.cxx 

OBJS += \
./Dep/panda/src/tform/buttonThrower.o \
./Dep/panda/src/tform/config_tform.o \
./Dep/panda/src/tform/driveInterface.o \
./Dep/panda/src/tform/mouseInterfaceNode.o \
./Dep/panda/src/tform/mouseSubregion.o \
./Dep/panda/src/tform/mouseWatcher.o \
./Dep/panda/src/tform/mouseWatcherGroup.o \
./Dep/panda/src/tform/mouseWatcherParameter.o \
./Dep/panda/src/tform/mouseWatcherRegion.o \
./Dep/panda/src/tform/tform_composite.o \
./Dep/panda/src/tform/tform_composite1.o \
./Dep/panda/src/tform/tform_composite2.o \
./Dep/panda/src/tform/trackball.o \
./Dep/panda/src/tform/transform2sg.o 

CXX_DEPS += \
./Dep/panda/src/tform/buttonThrower.d \
./Dep/panda/src/tform/config_tform.d \
./Dep/panda/src/tform/driveInterface.d \
./Dep/panda/src/tform/mouseInterfaceNode.d \
./Dep/panda/src/tform/mouseSubregion.d \
./Dep/panda/src/tform/mouseWatcher.d \
./Dep/panda/src/tform/mouseWatcherGroup.d \
./Dep/panda/src/tform/mouseWatcherParameter.d \
./Dep/panda/src/tform/mouseWatcherRegion.d \
./Dep/panda/src/tform/tform_composite.d \
./Dep/panda/src/tform/tform_composite1.d \
./Dep/panda/src/tform/tform_composite2.d \
./Dep/panda/src/tform/trackball.d \
./Dep/panda/src/tform/transform2sg.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/tform/%.o: ../Dep/panda/src/tform/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


