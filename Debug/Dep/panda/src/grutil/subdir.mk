################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/grutil/cardMaker.cxx \
../Dep/panda/src/grutil/config_grutil.cxx \
../Dep/panda/src/grutil/ffmpegTexture.cxx \
../Dep/panda/src/grutil/fisheyeMaker.cxx \
../Dep/panda/src/grutil/frameRateMeter.cxx \
../Dep/panda/src/grutil/geoMipTerrain.cxx \
../Dep/panda/src/grutil/grutil_composite.cxx \
../Dep/panda/src/grutil/grutil_composite1.cxx \
../Dep/panda/src/grutil/grutil_composite2.cxx \
../Dep/panda/src/grutil/heightfieldTesselator.cxx \
../Dep/panda/src/grutil/lineSegs.cxx \
../Dep/panda/src/grutil/meshDrawer.cxx \
../Dep/panda/src/grutil/meshDrawer2D.cxx \
../Dep/panda/src/grutil/movieTexture.cxx \
../Dep/panda/src/grutil/multitexReducer.cxx \
../Dep/panda/src/grutil/nodeVertexTransform.cxx \
../Dep/panda/src/grutil/pipeOcclusionCullTraverser.cxx \
../Dep/panda/src/grutil/rigidBodyCombiner.cxx \
../Dep/panda/src/grutil/sceneGraphAnalyzerMeter.cxx 

OBJS += \
./Dep/panda/src/grutil/cardMaker.o \
./Dep/panda/src/grutil/config_grutil.o \
./Dep/panda/src/grutil/ffmpegTexture.o \
./Dep/panda/src/grutil/fisheyeMaker.o \
./Dep/panda/src/grutil/frameRateMeter.o \
./Dep/panda/src/grutil/geoMipTerrain.o \
./Dep/panda/src/grutil/grutil_composite.o \
./Dep/panda/src/grutil/grutil_composite1.o \
./Dep/panda/src/grutil/grutil_composite2.o \
./Dep/panda/src/grutil/heightfieldTesselator.o \
./Dep/panda/src/grutil/lineSegs.o \
./Dep/panda/src/grutil/meshDrawer.o \
./Dep/panda/src/grutil/meshDrawer2D.o \
./Dep/panda/src/grutil/movieTexture.o \
./Dep/panda/src/grutil/multitexReducer.o \
./Dep/panda/src/grutil/nodeVertexTransform.o \
./Dep/panda/src/grutil/pipeOcclusionCullTraverser.o \
./Dep/panda/src/grutil/rigidBodyCombiner.o \
./Dep/panda/src/grutil/sceneGraphAnalyzerMeter.o 

CXX_DEPS += \
./Dep/panda/src/grutil/cardMaker.d \
./Dep/panda/src/grutil/config_grutil.d \
./Dep/panda/src/grutil/ffmpegTexture.d \
./Dep/panda/src/grutil/fisheyeMaker.d \
./Dep/panda/src/grutil/frameRateMeter.d \
./Dep/panda/src/grutil/geoMipTerrain.d \
./Dep/panda/src/grutil/grutil_composite.d \
./Dep/panda/src/grutil/grutil_composite1.d \
./Dep/panda/src/grutil/grutil_composite2.d \
./Dep/panda/src/grutil/heightfieldTesselator.d \
./Dep/panda/src/grutil/lineSegs.d \
./Dep/panda/src/grutil/meshDrawer.d \
./Dep/panda/src/grutil/meshDrawer2D.d \
./Dep/panda/src/grutil/movieTexture.d \
./Dep/panda/src/grutil/multitexReducer.d \
./Dep/panda/src/grutil/nodeVertexTransform.d \
./Dep/panda/src/grutil/pipeOcclusionCullTraverser.d \
./Dep/panda/src/grutil/rigidBodyCombiner.d \
./Dep/panda/src/grutil/sceneGraphAnalyzerMeter.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/grutil/%.o: ../Dep/panda/src/grutil/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


