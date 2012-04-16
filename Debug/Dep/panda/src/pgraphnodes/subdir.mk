################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/pgraphnodes/ambientLight.cxx \
../Dep/panda/src/pgraphnodes/callbackNode.cxx \
../Dep/panda/src/pgraphnodes/config_pgraphnodes.cxx \
../Dep/panda/src/pgraphnodes/directionalLight.cxx \
../Dep/panda/src/pgraphnodes/fadeLodNode.cxx \
../Dep/panda/src/pgraphnodes/fadeLodNodeData.cxx \
../Dep/panda/src/pgraphnodes/lightLensNode.cxx \
../Dep/panda/src/pgraphnodes/lightNode.cxx \
../Dep/panda/src/pgraphnodes/lodNode.cxx \
../Dep/panda/src/pgraphnodes/lodNodeType.cxx \
../Dep/panda/src/pgraphnodes/nodeCullCallbackData.cxx \
../Dep/panda/src/pgraphnodes/pgraphnodes_composite.cxx \
../Dep/panda/src/pgraphnodes/pgraphnodes_composite1.cxx \
../Dep/panda/src/pgraphnodes/pgraphnodes_composite2.cxx \
../Dep/panda/src/pgraphnodes/pointLight.cxx \
../Dep/panda/src/pgraphnodes/sceneGraphAnalyzer.cxx \
../Dep/panda/src/pgraphnodes/selectiveChildNode.cxx \
../Dep/panda/src/pgraphnodes/sequenceNode.cxx \
../Dep/panda/src/pgraphnodes/shaderGenerator.cxx \
../Dep/panda/src/pgraphnodes/spotlight.cxx \
../Dep/panda/src/pgraphnodes/switchNode.cxx 

OBJS += \
./Dep/panda/src/pgraphnodes/ambientLight.o \
./Dep/panda/src/pgraphnodes/callbackNode.o \
./Dep/panda/src/pgraphnodes/config_pgraphnodes.o \
./Dep/panda/src/pgraphnodes/directionalLight.o \
./Dep/panda/src/pgraphnodes/fadeLodNode.o \
./Dep/panda/src/pgraphnodes/fadeLodNodeData.o \
./Dep/panda/src/pgraphnodes/lightLensNode.o \
./Dep/panda/src/pgraphnodes/lightNode.o \
./Dep/panda/src/pgraphnodes/lodNode.o \
./Dep/panda/src/pgraphnodes/lodNodeType.o \
./Dep/panda/src/pgraphnodes/nodeCullCallbackData.o \
./Dep/panda/src/pgraphnodes/pgraphnodes_composite.o \
./Dep/panda/src/pgraphnodes/pgraphnodes_composite1.o \
./Dep/panda/src/pgraphnodes/pgraphnodes_composite2.o \
./Dep/panda/src/pgraphnodes/pointLight.o \
./Dep/panda/src/pgraphnodes/sceneGraphAnalyzer.o \
./Dep/panda/src/pgraphnodes/selectiveChildNode.o \
./Dep/panda/src/pgraphnodes/sequenceNode.o \
./Dep/panda/src/pgraphnodes/shaderGenerator.o \
./Dep/panda/src/pgraphnodes/spotlight.o \
./Dep/panda/src/pgraphnodes/switchNode.o 

CXX_DEPS += \
./Dep/panda/src/pgraphnodes/ambientLight.d \
./Dep/panda/src/pgraphnodes/callbackNode.d \
./Dep/panda/src/pgraphnodes/config_pgraphnodes.d \
./Dep/panda/src/pgraphnodes/directionalLight.d \
./Dep/panda/src/pgraphnodes/fadeLodNode.d \
./Dep/panda/src/pgraphnodes/fadeLodNodeData.d \
./Dep/panda/src/pgraphnodes/lightLensNode.d \
./Dep/panda/src/pgraphnodes/lightNode.d \
./Dep/panda/src/pgraphnodes/lodNode.d \
./Dep/panda/src/pgraphnodes/lodNodeType.d \
./Dep/panda/src/pgraphnodes/nodeCullCallbackData.d \
./Dep/panda/src/pgraphnodes/pgraphnodes_composite.d \
./Dep/panda/src/pgraphnodes/pgraphnodes_composite1.d \
./Dep/panda/src/pgraphnodes/pgraphnodes_composite2.d \
./Dep/panda/src/pgraphnodes/pointLight.d \
./Dep/panda/src/pgraphnodes/sceneGraphAnalyzer.d \
./Dep/panda/src/pgraphnodes/selectiveChildNode.d \
./Dep/panda/src/pgraphnodes/sequenceNode.d \
./Dep/panda/src/pgraphnodes/shaderGenerator.d \
./Dep/panda/src/pgraphnodes/spotlight.d \
./Dep/panda/src/pgraphnodes/switchNode.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/pgraphnodes/%.o: ../Dep/panda/src/pgraphnodes/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


