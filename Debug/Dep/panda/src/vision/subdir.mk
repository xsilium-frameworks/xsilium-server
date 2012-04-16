################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/vision/arToolKit.cxx \
../Dep/panda/src/vision/config_vision.cxx \
../Dep/panda/src/vision/openCVTexture.cxx \
../Dep/panda/src/vision/vision_composite1.cxx \
../Dep/panda/src/vision/webcamVideo.cxx \
../Dep/panda/src/vision/webcamVideoCursorOpenCV.cxx \
../Dep/panda/src/vision/webcamVideoCursorV4L.cxx \
../Dep/panda/src/vision/webcamVideoDS.cxx \
../Dep/panda/src/vision/webcamVideoOpenCV.cxx \
../Dep/panda/src/vision/webcamVideoV4L.cxx 

OBJS += \
./Dep/panda/src/vision/arToolKit.o \
./Dep/panda/src/vision/config_vision.o \
./Dep/panda/src/vision/openCVTexture.o \
./Dep/panda/src/vision/vision_composite1.o \
./Dep/panda/src/vision/webcamVideo.o \
./Dep/panda/src/vision/webcamVideoCursorOpenCV.o \
./Dep/panda/src/vision/webcamVideoCursorV4L.o \
./Dep/panda/src/vision/webcamVideoDS.o \
./Dep/panda/src/vision/webcamVideoOpenCV.o \
./Dep/panda/src/vision/webcamVideoV4L.o 

CXX_DEPS += \
./Dep/panda/src/vision/arToolKit.d \
./Dep/panda/src/vision/config_vision.d \
./Dep/panda/src/vision/openCVTexture.d \
./Dep/panda/src/vision/vision_composite1.d \
./Dep/panda/src/vision/webcamVideo.d \
./Dep/panda/src/vision/webcamVideoCursorOpenCV.d \
./Dep/panda/src/vision/webcamVideoCursorV4L.d \
./Dep/panda/src/vision/webcamVideoDS.d \
./Dep/panda/src/vision/webcamVideoOpenCV.d \
./Dep/panda/src/vision/webcamVideoV4L.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/vision/%.o: ../Dep/panda/src/vision/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


