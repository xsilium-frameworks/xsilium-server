################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/awesomium/AwMouseAndKeyboard.cxx \
../Dep/panda/src/awesomium/WebBrowserTexture.cxx \
../Dep/panda/src/awesomium/awWebCore.cxx \
../Dep/panda/src/awesomium/awWebView.cxx \
../Dep/panda/src/awesomium/awWebViewListener.cxx \
../Dep/panda/src/awesomium/config_awesomium.cxx \
../Dep/panda/src/awesomium/pandaawesomium_composite1.cxx 

OBJS += \
./Dep/panda/src/awesomium/AwMouseAndKeyboard.o \
./Dep/panda/src/awesomium/WebBrowserTexture.o \
./Dep/panda/src/awesomium/awWebCore.o \
./Dep/panda/src/awesomium/awWebView.o \
./Dep/panda/src/awesomium/awWebViewListener.o \
./Dep/panda/src/awesomium/config_awesomium.o \
./Dep/panda/src/awesomium/pandaawesomium_composite1.o 

CXX_DEPS += \
./Dep/panda/src/awesomium/AwMouseAndKeyboard.d \
./Dep/panda/src/awesomium/WebBrowserTexture.d \
./Dep/panda/src/awesomium/awWebCore.d \
./Dep/panda/src/awesomium/awWebView.d \
./Dep/panda/src/awesomium/awWebViewListener.d \
./Dep/panda/src/awesomium/config_awesomium.d \
./Dep/panda/src/awesomium/pandaawesomium_composite1.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/awesomium/%.o: ../Dep/panda/src/awesomium/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


