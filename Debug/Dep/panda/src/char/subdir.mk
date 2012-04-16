################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/char/char_composite.cxx \
../Dep/panda/src/char/char_composite1.cxx \
../Dep/panda/src/char/char_composite2.cxx \
../Dep/panda/src/char/character.cxx \
../Dep/panda/src/char/characterJoint.cxx \
../Dep/panda/src/char/characterJointBundle.cxx \
../Dep/panda/src/char/characterJointEffect.cxx \
../Dep/panda/src/char/characterSlider.cxx \
../Dep/panda/src/char/characterVertexSlider.cxx \
../Dep/panda/src/char/config_char.cxx \
../Dep/panda/src/char/jointVertexTransform.cxx 

OBJS += \
./Dep/panda/src/char/char_composite.o \
./Dep/panda/src/char/char_composite1.o \
./Dep/panda/src/char/char_composite2.o \
./Dep/panda/src/char/character.o \
./Dep/panda/src/char/characterJoint.o \
./Dep/panda/src/char/characterJointBundle.o \
./Dep/panda/src/char/characterJointEffect.o \
./Dep/panda/src/char/characterSlider.o \
./Dep/panda/src/char/characterVertexSlider.o \
./Dep/panda/src/char/config_char.o \
./Dep/panda/src/char/jointVertexTransform.o 

CXX_DEPS += \
./Dep/panda/src/char/char_composite.d \
./Dep/panda/src/char/char_composite1.d \
./Dep/panda/src/char/char_composite2.d \
./Dep/panda/src/char/character.d \
./Dep/panda/src/char/characterJoint.d \
./Dep/panda/src/char/characterJointBundle.d \
./Dep/panda/src/char/characterJointEffect.d \
./Dep/panda/src/char/characterSlider.d \
./Dep/panda/src/char/characterVertexSlider.d \
./Dep/panda/src/char/config_char.d \
./Dep/panda/src/char/jointVertexTransform.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/char/%.o: ../Dep/panda/src/char/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


