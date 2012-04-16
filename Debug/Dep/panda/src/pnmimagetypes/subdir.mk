################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dep/panda/src/pnmimagetypes/colrops.c 

CXX_SRCS += \
../Dep/panda/src/pnmimagetypes/config_pnmimagetypes.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypeBMP.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypeBMPReader.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypeBMPWriter.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypeIMG.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypeJPG.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypeJPGReader.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypeJPGWriter.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypePNG.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypePNM.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypeSGI.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypeSGIReader.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypeSGIWriter.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypeSoftImage.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypeTGA.cxx \
../Dep/panda/src/pnmimagetypes/pnmFileTypeTIFF.cxx \
../Dep/panda/src/pnmimagetypes/pnmimagetypes_composite.cxx \
../Dep/panda/src/pnmimagetypes/pnmimagetypes_composite1.cxx \
../Dep/panda/src/pnmimagetypes/pnmimagetypes_composite2.cxx 

OBJS += \
./Dep/panda/src/pnmimagetypes/colrops.o \
./Dep/panda/src/pnmimagetypes/config_pnmimagetypes.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypeBMP.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypeBMPReader.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypeBMPWriter.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypeIMG.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypeJPG.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypeJPGReader.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypeJPGWriter.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypePNG.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypePNM.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypeSGI.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypeSGIReader.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypeSGIWriter.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypeSoftImage.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypeTGA.o \
./Dep/panda/src/pnmimagetypes/pnmFileTypeTIFF.o \
./Dep/panda/src/pnmimagetypes/pnmimagetypes_composite.o \
./Dep/panda/src/pnmimagetypes/pnmimagetypes_composite1.o \
./Dep/panda/src/pnmimagetypes/pnmimagetypes_composite2.o 

C_DEPS += \
./Dep/panda/src/pnmimagetypes/colrops.d 

CXX_DEPS += \
./Dep/panda/src/pnmimagetypes/config_pnmimagetypes.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypeBMP.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypeBMPReader.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypeBMPWriter.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypeIMG.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypeJPG.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypeJPGReader.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypeJPGWriter.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypePNG.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypePNM.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypeSGI.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypeSGIReader.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypeSGIWriter.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypeSoftImage.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypeTGA.d \
./Dep/panda/src/pnmimagetypes/pnmFileTypeTIFF.d \
./Dep/panda/src/pnmimagetypes/pnmimagetypes_composite.d \
./Dep/panda/src/pnmimagetypes/pnmimagetypes_composite1.d \
./Dep/panda/src/pnmimagetypes/pnmimagetypes_composite2.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/pnmimagetypes/%.o: ../Dep/panda/src/pnmimagetypes/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Dep/panda/src/pnmimagetypes/%.o: ../Dep/panda/src/pnmimagetypes/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


