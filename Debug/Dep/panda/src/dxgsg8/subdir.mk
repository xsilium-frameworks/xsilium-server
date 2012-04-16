################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/dxgsg8/config_dxgsg8.cxx \
../Dep/panda/src/dxgsg8/dxGeomMunger8.cxx \
../Dep/panda/src/dxgsg8/dxGraphicsDevice8.cxx \
../Dep/panda/src/dxgsg8/dxGraphicsStateGuardian8.cxx \
../Dep/panda/src/dxgsg8/dxIndexBufferContext8.cxx \
../Dep/panda/src/dxgsg8/dxInput8.cxx \
../Dep/panda/src/dxgsg8/dxTextureContext8.cxx \
../Dep/panda/src/dxgsg8/dxVertexBufferContext8.cxx \
../Dep/panda/src/dxgsg8/dxgsg8_composite.cxx \
../Dep/panda/src/dxgsg8/dxgsg8_composite1.cxx \
../Dep/panda/src/dxgsg8/wdxGraphicsBuffer8.cxx \
../Dep/panda/src/dxgsg8/wdxGraphicsPipe8.cxx \
../Dep/panda/src/dxgsg8/wdxGraphicsWindow8.cxx 

OBJS += \
./Dep/panda/src/dxgsg8/config_dxgsg8.o \
./Dep/panda/src/dxgsg8/dxGeomMunger8.o \
./Dep/panda/src/dxgsg8/dxGraphicsDevice8.o \
./Dep/panda/src/dxgsg8/dxGraphicsStateGuardian8.o \
./Dep/panda/src/dxgsg8/dxIndexBufferContext8.o \
./Dep/panda/src/dxgsg8/dxInput8.o \
./Dep/panda/src/dxgsg8/dxTextureContext8.o \
./Dep/panda/src/dxgsg8/dxVertexBufferContext8.o \
./Dep/panda/src/dxgsg8/dxgsg8_composite.o \
./Dep/panda/src/dxgsg8/dxgsg8_composite1.o \
./Dep/panda/src/dxgsg8/wdxGraphicsBuffer8.o \
./Dep/panda/src/dxgsg8/wdxGraphicsPipe8.o \
./Dep/panda/src/dxgsg8/wdxGraphicsWindow8.o 

CXX_DEPS += \
./Dep/panda/src/dxgsg8/config_dxgsg8.d \
./Dep/panda/src/dxgsg8/dxGeomMunger8.d \
./Dep/panda/src/dxgsg8/dxGraphicsDevice8.d \
./Dep/panda/src/dxgsg8/dxGraphicsStateGuardian8.d \
./Dep/panda/src/dxgsg8/dxIndexBufferContext8.d \
./Dep/panda/src/dxgsg8/dxInput8.d \
./Dep/panda/src/dxgsg8/dxTextureContext8.d \
./Dep/panda/src/dxgsg8/dxVertexBufferContext8.d \
./Dep/panda/src/dxgsg8/dxgsg8_composite.d \
./Dep/panda/src/dxgsg8/dxgsg8_composite1.d \
./Dep/panda/src/dxgsg8/wdxGraphicsBuffer8.d \
./Dep/panda/src/dxgsg8/wdxGraphicsPipe8.d \
./Dep/panda/src/dxgsg8/wdxGraphicsWindow8.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/dxgsg8/%.o: ../Dep/panda/src/dxgsg8/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


