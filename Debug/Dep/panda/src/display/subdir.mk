################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/display/config_display.cxx \
../Dep/panda/src/display/displayInformation.cxx \
../Dep/panda/src/display/displayRegion.cxx \
../Dep/panda/src/display/displayRegionCullCallbackData.cxx \
../Dep/panda/src/display/displayRegionDrawCallbackData.cxx \
../Dep/panda/src/display/displaySearchParameters.cxx \
../Dep/panda/src/display/display_composite.cxx \
../Dep/panda/src/display/display_composite1.cxx \
../Dep/panda/src/display/display_composite2.cxx \
../Dep/panda/src/display/drawableRegion.cxx \
../Dep/panda/src/display/frameBufferProperties.cxx \
../Dep/panda/src/display/graphicsBuffer.cxx \
../Dep/panda/src/display/graphicsDevice.cxx \
../Dep/panda/src/display/graphicsEngine.cxx \
../Dep/panda/src/display/graphicsOutput.cxx \
../Dep/panda/src/display/graphicsPipe.cxx \
../Dep/panda/src/display/graphicsPipeSelection.cxx \
../Dep/panda/src/display/graphicsStateGuardian.cxx \
../Dep/panda/src/display/graphicsThreadingModel.cxx \
../Dep/panda/src/display/graphicsWindow.cxx \
../Dep/panda/src/display/graphicsWindowInputDevice.cxx \
../Dep/panda/src/display/lru.cxx \
../Dep/panda/src/display/nativeWindowHandle.cxx \
../Dep/panda/src/display/parasiteBuffer.cxx \
../Dep/panda/src/display/standardMunger.cxx \
../Dep/panda/src/display/stencilRenderStates.cxx \
../Dep/panda/src/display/stereoDisplayRegion.cxx \
../Dep/panda/src/display/subprocessWindow.cxx \
../Dep/panda/src/display/subprocessWindowBuffer.cxx \
../Dep/panda/src/display/test_display.cxx \
../Dep/panda/src/display/windowHandle.cxx \
../Dep/panda/src/display/windowProperties.cxx 

OBJS += \
./Dep/panda/src/display/config_display.o \
./Dep/panda/src/display/displayInformation.o \
./Dep/panda/src/display/displayRegion.o \
./Dep/panda/src/display/displayRegionCullCallbackData.o \
./Dep/panda/src/display/displayRegionDrawCallbackData.o \
./Dep/panda/src/display/displaySearchParameters.o \
./Dep/panda/src/display/display_composite.o \
./Dep/panda/src/display/display_composite1.o \
./Dep/panda/src/display/display_composite2.o \
./Dep/panda/src/display/drawableRegion.o \
./Dep/panda/src/display/frameBufferProperties.o \
./Dep/panda/src/display/graphicsBuffer.o \
./Dep/panda/src/display/graphicsDevice.o \
./Dep/panda/src/display/graphicsEngine.o \
./Dep/panda/src/display/graphicsOutput.o \
./Dep/panda/src/display/graphicsPipe.o \
./Dep/panda/src/display/graphicsPipeSelection.o \
./Dep/panda/src/display/graphicsStateGuardian.o \
./Dep/panda/src/display/graphicsThreadingModel.o \
./Dep/panda/src/display/graphicsWindow.o \
./Dep/panda/src/display/graphicsWindowInputDevice.o \
./Dep/panda/src/display/lru.o \
./Dep/panda/src/display/nativeWindowHandle.o \
./Dep/panda/src/display/parasiteBuffer.o \
./Dep/panda/src/display/standardMunger.o \
./Dep/panda/src/display/stencilRenderStates.o \
./Dep/panda/src/display/stereoDisplayRegion.o \
./Dep/panda/src/display/subprocessWindow.o \
./Dep/panda/src/display/subprocessWindowBuffer.o \
./Dep/panda/src/display/test_display.o \
./Dep/panda/src/display/windowHandle.o \
./Dep/panda/src/display/windowProperties.o 

CXX_DEPS += \
./Dep/panda/src/display/config_display.d \
./Dep/panda/src/display/displayInformation.d \
./Dep/panda/src/display/displayRegion.d \
./Dep/panda/src/display/displayRegionCullCallbackData.d \
./Dep/panda/src/display/displayRegionDrawCallbackData.d \
./Dep/panda/src/display/displaySearchParameters.d \
./Dep/panda/src/display/display_composite.d \
./Dep/panda/src/display/display_composite1.d \
./Dep/panda/src/display/display_composite2.d \
./Dep/panda/src/display/drawableRegion.d \
./Dep/panda/src/display/frameBufferProperties.d \
./Dep/panda/src/display/graphicsBuffer.d \
./Dep/panda/src/display/graphicsDevice.d \
./Dep/panda/src/display/graphicsEngine.d \
./Dep/panda/src/display/graphicsOutput.d \
./Dep/panda/src/display/graphicsPipe.d \
./Dep/panda/src/display/graphicsPipeSelection.d \
./Dep/panda/src/display/graphicsStateGuardian.d \
./Dep/panda/src/display/graphicsThreadingModel.d \
./Dep/panda/src/display/graphicsWindow.d \
./Dep/panda/src/display/graphicsWindowInputDevice.d \
./Dep/panda/src/display/lru.d \
./Dep/panda/src/display/nativeWindowHandle.d \
./Dep/panda/src/display/parasiteBuffer.d \
./Dep/panda/src/display/standardMunger.d \
./Dep/panda/src/display/stencilRenderStates.d \
./Dep/panda/src/display/stereoDisplayRegion.d \
./Dep/panda/src/display/subprocessWindow.d \
./Dep/panda/src/display/subprocessWindowBuffer.d \
./Dep/panda/src/display/test_display.d \
./Dep/panda/src/display/windowHandle.d \
./Dep/panda/src/display/windowProperties.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/display/%.o: ../Dep/panda/src/display/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


