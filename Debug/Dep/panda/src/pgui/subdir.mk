################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/pgui/config_pgui.cxx \
../Dep/panda/src/pgui/pgButton.cxx \
../Dep/panda/src/pgui/pgButtonNotify.cxx \
../Dep/panda/src/pgui/pgCullTraverser.cxx \
../Dep/panda/src/pgui/pgEntry.cxx \
../Dep/panda/src/pgui/pgFrameStyle.cxx \
../Dep/panda/src/pgui/pgItem.cxx \
../Dep/panda/src/pgui/pgItemNotify.cxx \
../Dep/panda/src/pgui/pgMouseWatcherBackground.cxx \
../Dep/panda/src/pgui/pgMouseWatcherGroup.cxx \
../Dep/panda/src/pgui/pgMouseWatcherParameter.cxx \
../Dep/panda/src/pgui/pgMouseWatcherRegion.cxx \
../Dep/panda/src/pgui/pgScrollFrame.cxx \
../Dep/panda/src/pgui/pgSliderBar.cxx \
../Dep/panda/src/pgui/pgSliderBarNotify.cxx \
../Dep/panda/src/pgui/pgTop.cxx \
../Dep/panda/src/pgui/pgVirtualFrame.cxx \
../Dep/panda/src/pgui/pgWaitBar.cxx \
../Dep/panda/src/pgui/pgui_composite.cxx \
../Dep/panda/src/pgui/pgui_composite1.cxx \
../Dep/panda/src/pgui/pgui_composite2.cxx \
../Dep/panda/src/pgui/test_pgentry.cxx 

OBJS += \
./Dep/panda/src/pgui/config_pgui.o \
./Dep/panda/src/pgui/pgButton.o \
./Dep/panda/src/pgui/pgButtonNotify.o \
./Dep/panda/src/pgui/pgCullTraverser.o \
./Dep/panda/src/pgui/pgEntry.o \
./Dep/panda/src/pgui/pgFrameStyle.o \
./Dep/panda/src/pgui/pgItem.o \
./Dep/panda/src/pgui/pgItemNotify.o \
./Dep/panda/src/pgui/pgMouseWatcherBackground.o \
./Dep/panda/src/pgui/pgMouseWatcherGroup.o \
./Dep/panda/src/pgui/pgMouseWatcherParameter.o \
./Dep/panda/src/pgui/pgMouseWatcherRegion.o \
./Dep/panda/src/pgui/pgScrollFrame.o \
./Dep/panda/src/pgui/pgSliderBar.o \
./Dep/panda/src/pgui/pgSliderBarNotify.o \
./Dep/panda/src/pgui/pgTop.o \
./Dep/panda/src/pgui/pgVirtualFrame.o \
./Dep/panda/src/pgui/pgWaitBar.o \
./Dep/panda/src/pgui/pgui_composite.o \
./Dep/panda/src/pgui/pgui_composite1.o \
./Dep/panda/src/pgui/pgui_composite2.o \
./Dep/panda/src/pgui/test_pgentry.o 

CXX_DEPS += \
./Dep/panda/src/pgui/config_pgui.d \
./Dep/panda/src/pgui/pgButton.d \
./Dep/panda/src/pgui/pgButtonNotify.d \
./Dep/panda/src/pgui/pgCullTraverser.d \
./Dep/panda/src/pgui/pgEntry.d \
./Dep/panda/src/pgui/pgFrameStyle.d \
./Dep/panda/src/pgui/pgItem.d \
./Dep/panda/src/pgui/pgItemNotify.d \
./Dep/panda/src/pgui/pgMouseWatcherBackground.d \
./Dep/panda/src/pgui/pgMouseWatcherGroup.d \
./Dep/panda/src/pgui/pgMouseWatcherParameter.d \
./Dep/panda/src/pgui/pgMouseWatcherRegion.d \
./Dep/panda/src/pgui/pgScrollFrame.d \
./Dep/panda/src/pgui/pgSliderBar.d \
./Dep/panda/src/pgui/pgSliderBarNotify.d \
./Dep/panda/src/pgui/pgTop.d \
./Dep/panda/src/pgui/pgVirtualFrame.d \
./Dep/panda/src/pgui/pgWaitBar.d \
./Dep/panda/src/pgui/pgui_composite.d \
./Dep/panda/src/pgui/pgui_composite1.d \
./Dep/panda/src/pgui/pgui_composite2.d \
./Dep/panda/src/pgui/test_pgentry.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/pgui/%.o: ../Dep/panda/src/pgui/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


