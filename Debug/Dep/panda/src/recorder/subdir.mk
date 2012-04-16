################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/recorder/config_recorder.cxx \
../Dep/panda/src/recorder/mouseRecorder.cxx \
../Dep/panda/src/recorder/recorderBase.cxx \
../Dep/panda/src/recorder/recorderController.cxx \
../Dep/panda/src/recorder/recorderFrame.cxx \
../Dep/panda/src/recorder/recorderHeader.cxx \
../Dep/panda/src/recorder/recorderTable.cxx \
../Dep/panda/src/recorder/recorder_composite.cxx \
../Dep/panda/src/recorder/recorder_composite1.cxx \
../Dep/panda/src/recorder/recorder_composite2.cxx \
../Dep/panda/src/recorder/socketStreamRecorder.cxx 

OBJS += \
./Dep/panda/src/recorder/config_recorder.o \
./Dep/panda/src/recorder/mouseRecorder.o \
./Dep/panda/src/recorder/recorderBase.o \
./Dep/panda/src/recorder/recorderController.o \
./Dep/panda/src/recorder/recorderFrame.o \
./Dep/panda/src/recorder/recorderHeader.o \
./Dep/panda/src/recorder/recorderTable.o \
./Dep/panda/src/recorder/recorder_composite.o \
./Dep/panda/src/recorder/recorder_composite1.o \
./Dep/panda/src/recorder/recorder_composite2.o \
./Dep/panda/src/recorder/socketStreamRecorder.o 

CXX_DEPS += \
./Dep/panda/src/recorder/config_recorder.d \
./Dep/panda/src/recorder/mouseRecorder.d \
./Dep/panda/src/recorder/recorderBase.d \
./Dep/panda/src/recorder/recorderController.d \
./Dep/panda/src/recorder/recorderFrame.d \
./Dep/panda/src/recorder/recorderHeader.d \
./Dep/panda/src/recorder/recorderTable.d \
./Dep/panda/src/recorder/recorder_composite.d \
./Dep/panda/src/recorder/recorder_composite1.d \
./Dep/panda/src/recorder/recorder_composite2.d \
./Dep/panda/src/recorder/socketStreamRecorder.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/recorder/%.o: ../Dep/panda/src/recorder/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


