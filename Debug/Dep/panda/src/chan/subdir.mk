################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/chan/animBundle.cxx \
../Dep/panda/src/chan/animBundleNode.cxx \
../Dep/panda/src/chan/animChannel.cxx \
../Dep/panda/src/chan/animChannelBase.cxx \
../Dep/panda/src/chan/animChannelMatrixDynamic.cxx \
../Dep/panda/src/chan/animChannelMatrixFixed.cxx \
../Dep/panda/src/chan/animChannelMatrixXfmTable.cxx \
../Dep/panda/src/chan/animChannelScalarDynamic.cxx \
../Dep/panda/src/chan/animChannelScalarTable.cxx \
../Dep/panda/src/chan/animControl.cxx \
../Dep/panda/src/chan/animControlCollection.cxx \
../Dep/panda/src/chan/animGroup.cxx \
../Dep/panda/src/chan/animPreloadTable.cxx \
../Dep/panda/src/chan/auto_bind.cxx \
../Dep/panda/src/chan/bindAnimRequest.cxx \
../Dep/panda/src/chan/chan_composite.cxx \
../Dep/panda/src/chan/chan_composite1.cxx \
../Dep/panda/src/chan/chan_composite2.cxx \
../Dep/panda/src/chan/config_chan.cxx \
../Dep/panda/src/chan/movingPartBase.cxx \
../Dep/panda/src/chan/movingPartMatrix.cxx \
../Dep/panda/src/chan/movingPartScalar.cxx \
../Dep/panda/src/chan/partBundle.cxx \
../Dep/panda/src/chan/partBundleHandle.cxx \
../Dep/panda/src/chan/partBundleNode.cxx \
../Dep/panda/src/chan/partGroup.cxx \
../Dep/panda/src/chan/partSubset.cxx \
../Dep/panda/src/chan/vector_PartGroupStar.cxx 

OBJS += \
./Dep/panda/src/chan/animBundle.o \
./Dep/panda/src/chan/animBundleNode.o \
./Dep/panda/src/chan/animChannel.o \
./Dep/panda/src/chan/animChannelBase.o \
./Dep/panda/src/chan/animChannelMatrixDynamic.o \
./Dep/panda/src/chan/animChannelMatrixFixed.o \
./Dep/panda/src/chan/animChannelMatrixXfmTable.o \
./Dep/panda/src/chan/animChannelScalarDynamic.o \
./Dep/panda/src/chan/animChannelScalarTable.o \
./Dep/panda/src/chan/animControl.o \
./Dep/panda/src/chan/animControlCollection.o \
./Dep/panda/src/chan/animGroup.o \
./Dep/panda/src/chan/animPreloadTable.o \
./Dep/panda/src/chan/auto_bind.o \
./Dep/panda/src/chan/bindAnimRequest.o \
./Dep/panda/src/chan/chan_composite.o \
./Dep/panda/src/chan/chan_composite1.o \
./Dep/panda/src/chan/chan_composite2.o \
./Dep/panda/src/chan/config_chan.o \
./Dep/panda/src/chan/movingPartBase.o \
./Dep/panda/src/chan/movingPartMatrix.o \
./Dep/panda/src/chan/movingPartScalar.o \
./Dep/panda/src/chan/partBundle.o \
./Dep/panda/src/chan/partBundleHandle.o \
./Dep/panda/src/chan/partBundleNode.o \
./Dep/panda/src/chan/partGroup.o \
./Dep/panda/src/chan/partSubset.o \
./Dep/panda/src/chan/vector_PartGroupStar.o 

CXX_DEPS += \
./Dep/panda/src/chan/animBundle.d \
./Dep/panda/src/chan/animBundleNode.d \
./Dep/panda/src/chan/animChannel.d \
./Dep/panda/src/chan/animChannelBase.d \
./Dep/panda/src/chan/animChannelMatrixDynamic.d \
./Dep/panda/src/chan/animChannelMatrixFixed.d \
./Dep/panda/src/chan/animChannelMatrixXfmTable.d \
./Dep/panda/src/chan/animChannelScalarDynamic.d \
./Dep/panda/src/chan/animChannelScalarTable.d \
./Dep/panda/src/chan/animControl.d \
./Dep/panda/src/chan/animControlCollection.d \
./Dep/panda/src/chan/animGroup.d \
./Dep/panda/src/chan/animPreloadTable.d \
./Dep/panda/src/chan/auto_bind.d \
./Dep/panda/src/chan/bindAnimRequest.d \
./Dep/panda/src/chan/chan_composite.d \
./Dep/panda/src/chan/chan_composite1.d \
./Dep/panda/src/chan/chan_composite2.d \
./Dep/panda/src/chan/config_chan.d \
./Dep/panda/src/chan/movingPartBase.d \
./Dep/panda/src/chan/movingPartMatrix.d \
./Dep/panda/src/chan/movingPartScalar.d \
./Dep/panda/src/chan/partBundle.d \
./Dep/panda/src/chan/partBundleHandle.d \
./Dep/panda/src/chan/partBundleNode.d \
./Dep/panda/src/chan/partGroup.d \
./Dep/panda/src/chan/partSubset.d \
./Dep/panda/src/chan/vector_PartGroupStar.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/chan/%.o: ../Dep/panda/src/chan/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


