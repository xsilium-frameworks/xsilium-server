################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/pnmimage/config_pnmimage.cxx \
../Dep/panda/src/pnmimage/pnm-image-filter-core.cxx \
../Dep/panda/src/pnmimage/pnm-image-filter.cxx \
../Dep/panda/src/pnmimage/pnmBrush.cxx \
../Dep/panda/src/pnmimage/pnmFileType.cxx \
../Dep/panda/src/pnmimage/pnmFileTypeRegistry.cxx \
../Dep/panda/src/pnmimage/pnmImage.cxx \
../Dep/panda/src/pnmimage/pnmImageHeader.cxx \
../Dep/panda/src/pnmimage/pnmPainter.cxx \
../Dep/panda/src/pnmimage/pnmReader.cxx \
../Dep/panda/src/pnmimage/pnmWriter.cxx \
../Dep/panda/src/pnmimage/pnmbitio.cxx \
../Dep/panda/src/pnmimage/pnmimage_base.cxx \
../Dep/panda/src/pnmimage/pnmimage_composite.cxx \
../Dep/panda/src/pnmimage/pnmimage_composite1.cxx \
../Dep/panda/src/pnmimage/pnmimage_composite2.cxx \
../Dep/panda/src/pnmimage/ppmcmap.cxx 

OBJS += \
./Dep/panda/src/pnmimage/config_pnmimage.o \
./Dep/panda/src/pnmimage/pnm-image-filter-core.o \
./Dep/panda/src/pnmimage/pnm-image-filter.o \
./Dep/panda/src/pnmimage/pnmBrush.o \
./Dep/panda/src/pnmimage/pnmFileType.o \
./Dep/panda/src/pnmimage/pnmFileTypeRegistry.o \
./Dep/panda/src/pnmimage/pnmImage.o \
./Dep/panda/src/pnmimage/pnmImageHeader.o \
./Dep/panda/src/pnmimage/pnmPainter.o \
./Dep/panda/src/pnmimage/pnmReader.o \
./Dep/panda/src/pnmimage/pnmWriter.o \
./Dep/panda/src/pnmimage/pnmbitio.o \
./Dep/panda/src/pnmimage/pnmimage_base.o \
./Dep/panda/src/pnmimage/pnmimage_composite.o \
./Dep/panda/src/pnmimage/pnmimage_composite1.o \
./Dep/panda/src/pnmimage/pnmimage_composite2.o \
./Dep/panda/src/pnmimage/ppmcmap.o 

CXX_DEPS += \
./Dep/panda/src/pnmimage/config_pnmimage.d \
./Dep/panda/src/pnmimage/pnm-image-filter-core.d \
./Dep/panda/src/pnmimage/pnm-image-filter.d \
./Dep/panda/src/pnmimage/pnmBrush.d \
./Dep/panda/src/pnmimage/pnmFileType.d \
./Dep/panda/src/pnmimage/pnmFileTypeRegistry.d \
./Dep/panda/src/pnmimage/pnmImage.d \
./Dep/panda/src/pnmimage/pnmImageHeader.d \
./Dep/panda/src/pnmimage/pnmPainter.d \
./Dep/panda/src/pnmimage/pnmReader.d \
./Dep/panda/src/pnmimage/pnmWriter.d \
./Dep/panda/src/pnmimage/pnmbitio.d \
./Dep/panda/src/pnmimage/pnmimage_base.d \
./Dep/panda/src/pnmimage/pnmimage_composite.d \
./Dep/panda/src/pnmimage/pnmimage_composite1.d \
./Dep/panda/src/pnmimage/pnmimage_composite2.d \
./Dep/panda/src/pnmimage/ppmcmap.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/pnmimage/%.o: ../Dep/panda/src/pnmimage/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


