################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Dep/panda/src/dxml/tinyxml.cpp \
../Dep/panda/src/dxml/tinyxmlerror.cpp \
../Dep/panda/src/dxml/tinyxmlparser.cpp 

CXX_SRCS += \
../Dep/panda/src/dxml/config_dxml.cxx \
../Dep/panda/src/dxml/dxml_composite1.cxx \
../Dep/panda/src/dxml/tinyxml_composite1.cxx 

OBJS += \
./Dep/panda/src/dxml/config_dxml.o \
./Dep/panda/src/dxml/dxml_composite1.o \
./Dep/panda/src/dxml/tinyxml.o \
./Dep/panda/src/dxml/tinyxml_composite1.o \
./Dep/panda/src/dxml/tinyxmlerror.o \
./Dep/panda/src/dxml/tinyxmlparser.o 

CPP_DEPS += \
./Dep/panda/src/dxml/tinyxml.d \
./Dep/panda/src/dxml/tinyxmlerror.d \
./Dep/panda/src/dxml/tinyxmlparser.d 

CXX_DEPS += \
./Dep/panda/src/dxml/config_dxml.d \
./Dep/panda/src/dxml/dxml_composite1.d \
./Dep/panda/src/dxml/tinyxml_composite1.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/dxml/%.o: ../Dep/panda/src/dxml/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Dep/panda/src/dxml/%.o: ../Dep/panda/src/dxml/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


