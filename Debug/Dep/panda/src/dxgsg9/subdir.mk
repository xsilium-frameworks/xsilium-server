################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/dxgsg9/config_dxgsg9.cxx \
../Dep/panda/src/dxgsg9/dxGeomMunger9.cxx \
../Dep/panda/src/dxgsg9/dxGraphicsDevice9.cxx \
../Dep/panda/src/dxgsg9/dxGraphicsStateGuardian9.cxx \
../Dep/panda/src/dxgsg9/dxIndexBufferContext9.cxx \
../Dep/panda/src/dxgsg9/dxInput9.cxx \
../Dep/panda/src/dxgsg9/dxOcclusionQueryContext9.cxx \
../Dep/panda/src/dxgsg9/dxShaderContext9.cxx \
../Dep/panda/src/dxgsg9/dxTextureContext9.cxx \
../Dep/panda/src/dxgsg9/dxVertexBufferContext9.cxx \
../Dep/panda/src/dxgsg9/dxgsg9_composite.cxx \
../Dep/panda/src/dxgsg9/dxgsg9_composite1.cxx \
../Dep/panda/src/dxgsg9/vertexElementArray.cxx \
../Dep/panda/src/dxgsg9/wdxGraphicsBuffer9.cxx \
../Dep/panda/src/dxgsg9/wdxGraphicsPipe9.cxx \
../Dep/panda/src/dxgsg9/wdxGraphicsWindow9.cxx 

OBJS += \
./Dep/panda/src/dxgsg9/config_dxgsg9.o \
./Dep/panda/src/dxgsg9/dxGeomMunger9.o \
./Dep/panda/src/dxgsg9/dxGraphicsDevice9.o \
./Dep/panda/src/dxgsg9/dxGraphicsStateGuardian9.o \
./Dep/panda/src/dxgsg9/dxIndexBufferContext9.o \
./Dep/panda/src/dxgsg9/dxInput9.o \
./Dep/panda/src/dxgsg9/dxOcclusionQueryContext9.o \
./Dep/panda/src/dxgsg9/dxShaderContext9.o \
./Dep/panda/src/dxgsg9/dxTextureContext9.o \
./Dep/panda/src/dxgsg9/dxVertexBufferContext9.o \
./Dep/panda/src/dxgsg9/dxgsg9_composite.o \
./Dep/panda/src/dxgsg9/dxgsg9_composite1.o \
./Dep/panda/src/dxgsg9/vertexElementArray.o \
./Dep/panda/src/dxgsg9/wdxGraphicsBuffer9.o \
./Dep/panda/src/dxgsg9/wdxGraphicsPipe9.o \
./Dep/panda/src/dxgsg9/wdxGraphicsWindow9.o 

CXX_DEPS += \
./Dep/panda/src/dxgsg9/config_dxgsg9.d \
./Dep/panda/src/dxgsg9/dxGeomMunger9.d \
./Dep/panda/src/dxgsg9/dxGraphicsDevice9.d \
./Dep/panda/src/dxgsg9/dxGraphicsStateGuardian9.d \
./Dep/panda/src/dxgsg9/dxIndexBufferContext9.d \
./Dep/panda/src/dxgsg9/dxInput9.d \
./Dep/panda/src/dxgsg9/dxOcclusionQueryContext9.d \
./Dep/panda/src/dxgsg9/dxShaderContext9.d \
./Dep/panda/src/dxgsg9/dxTextureContext9.d \
./Dep/panda/src/dxgsg9/dxVertexBufferContext9.d \
./Dep/panda/src/dxgsg9/dxgsg9_composite.d \
./Dep/panda/src/dxgsg9/dxgsg9_composite1.d \
./Dep/panda/src/dxgsg9/vertexElementArray.d \
./Dep/panda/src/dxgsg9/wdxGraphicsBuffer9.d \
./Dep/panda/src/dxgsg9/wdxGraphicsPipe9.d \
./Dep/panda/src/dxgsg9/wdxGraphicsWindow9.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/dxgsg9/%.o: ../Dep/panda/src/dxgsg9/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


