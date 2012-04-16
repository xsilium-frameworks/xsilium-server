################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/event/asyncTask.cxx \
../Dep/panda/src/event/asyncTaskChain.cxx \
../Dep/panda/src/event/asyncTaskCollection.cxx \
../Dep/panda/src/event/asyncTaskManager.cxx \
../Dep/panda/src/event/asyncTaskPause.cxx \
../Dep/panda/src/event/asyncTaskSequence.cxx \
../Dep/panda/src/event/buttonEvent.cxx \
../Dep/panda/src/event/buttonEventList.cxx \
../Dep/panda/src/event/config_event.cxx \
../Dep/panda/src/event/event.cxx \
../Dep/panda/src/event/eventHandler.cxx \
../Dep/panda/src/event/eventParameter.cxx \
../Dep/panda/src/event/eventQueue.cxx \
../Dep/panda/src/event/eventReceiver.cxx \
../Dep/panda/src/event/event_composite.cxx \
../Dep/panda/src/event/event_composite1.cxx \
../Dep/panda/src/event/event_composite2.cxx \
../Dep/panda/src/event/genericAsyncTask.cxx \
../Dep/panda/src/event/pointerEvent.cxx \
../Dep/panda/src/event/pointerEventList.cxx \
../Dep/panda/src/event/pt_Event.cxx \
../Dep/panda/src/event/pythonTask.cxx \
../Dep/panda/src/event/test_task.cxx 

OBJS += \
./Dep/panda/src/event/asyncTask.o \
./Dep/panda/src/event/asyncTaskChain.o \
./Dep/panda/src/event/asyncTaskCollection.o \
./Dep/panda/src/event/asyncTaskManager.o \
./Dep/panda/src/event/asyncTaskPause.o \
./Dep/panda/src/event/asyncTaskSequence.o \
./Dep/panda/src/event/buttonEvent.o \
./Dep/panda/src/event/buttonEventList.o \
./Dep/panda/src/event/config_event.o \
./Dep/panda/src/event/event.o \
./Dep/panda/src/event/eventHandler.o \
./Dep/panda/src/event/eventParameter.o \
./Dep/panda/src/event/eventQueue.o \
./Dep/panda/src/event/eventReceiver.o \
./Dep/panda/src/event/event_composite.o \
./Dep/panda/src/event/event_composite1.o \
./Dep/panda/src/event/event_composite2.o \
./Dep/panda/src/event/genericAsyncTask.o \
./Dep/panda/src/event/pointerEvent.o \
./Dep/panda/src/event/pointerEventList.o \
./Dep/panda/src/event/pt_Event.o \
./Dep/panda/src/event/pythonTask.o \
./Dep/panda/src/event/test_task.o 

CXX_DEPS += \
./Dep/panda/src/event/asyncTask.d \
./Dep/panda/src/event/asyncTaskChain.d \
./Dep/panda/src/event/asyncTaskCollection.d \
./Dep/panda/src/event/asyncTaskManager.d \
./Dep/panda/src/event/asyncTaskPause.d \
./Dep/panda/src/event/asyncTaskSequence.d \
./Dep/panda/src/event/buttonEvent.d \
./Dep/panda/src/event/buttonEventList.d \
./Dep/panda/src/event/config_event.d \
./Dep/panda/src/event/event.d \
./Dep/panda/src/event/eventHandler.d \
./Dep/panda/src/event/eventParameter.d \
./Dep/panda/src/event/eventQueue.d \
./Dep/panda/src/event/eventReceiver.d \
./Dep/panda/src/event/event_composite.d \
./Dep/panda/src/event/event_composite1.d \
./Dep/panda/src/event/event_composite2.d \
./Dep/panda/src/event/genericAsyncTask.d \
./Dep/panda/src/event/pointerEvent.d \
./Dep/panda/src/event/pointerEventList.d \
./Dep/panda/src/event/pt_Event.d \
./Dep/panda/src/event/pythonTask.d \
./Dep/panda/src/event/test_task.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/event/%.o: ../Dep/panda/src/event/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


