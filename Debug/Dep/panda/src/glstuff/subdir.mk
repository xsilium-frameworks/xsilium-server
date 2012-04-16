################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/glstuff/glGeomContext_src.cxx \
../Dep/panda/src/glstuff/glGeomMunger_src.cxx \
../Dep/panda/src/glstuff/glGraphicsBuffer_src.cxx \
../Dep/panda/src/glstuff/glGraphicsStateGuardian_src.cxx \
../Dep/panda/src/glstuff/glImmediateModeSender_src.cxx \
../Dep/panda/src/glstuff/glIndexBufferContext_src.cxx \
../Dep/panda/src/glstuff/glOcclusionQueryContext_src.cxx \
../Dep/panda/src/glstuff/glShaderContext_src.cxx \
../Dep/panda/src/glstuff/glTextureContext_src.cxx \
../Dep/panda/src/glstuff/glVertexBufferContext_src.cxx \
../Dep/panda/src/glstuff/glmisc_src.cxx \
../Dep/panda/src/glstuff/glpure.cxx \
../Dep/panda/src/glstuff/glstuff_src.cxx 

OBJS += \
./Dep/panda/src/glstuff/glGeomContext_src.o \
./Dep/panda/src/glstuff/glGeomMunger_src.o \
./Dep/panda/src/glstuff/glGraphicsBuffer_src.o \
./Dep/panda/src/glstuff/glGraphicsStateGuardian_src.o \
./Dep/panda/src/glstuff/glImmediateModeSender_src.o \
./Dep/panda/src/glstuff/glIndexBufferContext_src.o \
./Dep/panda/src/glstuff/glOcclusionQueryContext_src.o \
./Dep/panda/src/glstuff/glShaderContext_src.o \
./Dep/panda/src/glstuff/glTextureContext_src.o \
./Dep/panda/src/glstuff/glVertexBufferContext_src.o \
./Dep/panda/src/glstuff/glmisc_src.o \
./Dep/panda/src/glstuff/glpure.o \
./Dep/panda/src/glstuff/glstuff_src.o 

CXX_DEPS += \
./Dep/panda/src/glstuff/glGeomContext_src.d \
./Dep/panda/src/glstuff/glGeomMunger_src.d \
./Dep/panda/src/glstuff/glGraphicsBuffer_src.d \
./Dep/panda/src/glstuff/glGraphicsStateGuardian_src.d \
./Dep/panda/src/glstuff/glImmediateModeSender_src.d \
./Dep/panda/src/glstuff/glIndexBufferContext_src.d \
./Dep/panda/src/glstuff/glOcclusionQueryContext_src.d \
./Dep/panda/src/glstuff/glShaderContext_src.d \
./Dep/panda/src/glstuff/glTextureContext_src.d \
./Dep/panda/src/glstuff/glVertexBufferContext_src.d \
./Dep/panda/src/glstuff/glmisc_src.d \
./Dep/panda/src/glstuff/glpure.d \
./Dep/panda/src/glstuff/glstuff_src.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/glstuff/%.o: ../Dep/panda/src/glstuff/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


