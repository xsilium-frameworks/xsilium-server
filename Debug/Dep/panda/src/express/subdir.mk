################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dep/panda/src/express/ca_bundle_data_src.c 

CXX_SRCS += \
../Dep/panda/src/express/buffer.cxx \
../Dep/panda/src/express/checksumHashGenerator.cxx \
../Dep/panda/src/express/compress_string.cxx \
../Dep/panda/src/express/config_express.cxx \
../Dep/panda/src/express/copy_stream.cxx \
../Dep/panda/src/express/datagram.cxx \
../Dep/panda/src/express/datagramGenerator.cxx \
../Dep/panda/src/express/datagramIterator.cxx \
../Dep/panda/src/express/datagramSink.cxx \
../Dep/panda/src/express/dcast.cxx \
../Dep/panda/src/express/encrypt_string.cxx \
../Dep/panda/src/express/error_utils.cxx \
../Dep/panda/src/express/express_composite.cxx \
../Dep/panda/src/express/express_composite1.cxx \
../Dep/panda/src/express/express_composite2.cxx \
../Dep/panda/src/express/hashGeneratorBase.cxx \
../Dep/panda/src/express/hashVal.cxx \
../Dep/panda/src/express/make_ca_bundle.cxx \
../Dep/panda/src/express/memoryInfo.cxx \
../Dep/panda/src/express/memoryUsage.cxx \
../Dep/panda/src/express/memoryUsagePointerCounts.cxx \
../Dep/panda/src/express/memoryUsagePointers.cxx \
../Dep/panda/src/express/multifile.cxx \
../Dep/panda/src/express/namable.cxx \
../Dep/panda/src/express/nodePointerTo.cxx \
../Dep/panda/src/express/nodePointerToBase.cxx \
../Dep/panda/src/express/nodeReferenceCount.cxx \
../Dep/panda/src/express/openSSLWrapper.cxx \
../Dep/panda/src/express/ordered_vector.cxx \
../Dep/panda/src/express/pStatCollectorForwardBase.cxx \
../Dep/panda/src/express/password_hash.cxx \
../Dep/panda/src/express/patchfile.cxx \
../Dep/panda/src/express/pointerTo.cxx \
../Dep/panda/src/express/pointerToArray.cxx \
../Dep/panda/src/express/pointerToArrayBase.cxx \
../Dep/panda/src/express/pointerToBase.cxx \
../Dep/panda/src/express/pointerToVoid.cxx \
../Dep/panda/src/express/profileTimer.cxx \
../Dep/panda/src/express/pta_float.cxx \
../Dep/panda/src/express/pta_int.cxx \
../Dep/panda/src/express/pta_uchar.cxx \
../Dep/panda/src/express/ramfile.cxx \
../Dep/panda/src/express/referenceCount.cxx \
../Dep/panda/src/express/stringDecoder.cxx \
../Dep/panda/src/express/subStream.cxx \
../Dep/panda/src/express/subStreamBuf.cxx \
../Dep/panda/src/express/test_ordered_vector.cxx \
../Dep/panda/src/express/test_types.cxx \
../Dep/panda/src/express/test_zstream.cxx \
../Dep/panda/src/express/textEncoder.cxx \
../Dep/panda/src/express/threadSafePointerTo.cxx \
../Dep/panda/src/express/threadSafePointerToBase.cxx \
../Dep/panda/src/express/trueClock.cxx \
../Dep/panda/src/express/typedReferenceCount.cxx \
../Dep/panda/src/express/unicodeLatinMap.cxx \
../Dep/panda/src/express/vector_float.cxx \
../Dep/panda/src/express/vector_uchar.cxx \
../Dep/panda/src/express/virtualFile.cxx \
../Dep/panda/src/express/virtualFileComposite.cxx \
../Dep/panda/src/express/virtualFileList.cxx \
../Dep/panda/src/express/virtualFileMount.cxx \
../Dep/panda/src/express/virtualFileMountMultifile.cxx \
../Dep/panda/src/express/virtualFileMountSystem.cxx \
../Dep/panda/src/express/virtualFileSimple.cxx \
../Dep/panda/src/express/virtualFileSystem.cxx \
../Dep/panda/src/express/weakPointerCallback.cxx \
../Dep/panda/src/express/weakPointerTo.cxx \
../Dep/panda/src/express/weakPointerToBase.cxx \
../Dep/panda/src/express/weakPointerToVoid.cxx \
../Dep/panda/src/express/weakReferenceList.cxx \
../Dep/panda/src/express/windowsRegistry.cxx \
../Dep/panda/src/express/zStream.cxx \
../Dep/panda/src/express/zStreamBuf.cxx 

OBJS += \
./Dep/panda/src/express/buffer.o \
./Dep/panda/src/express/ca_bundle_data_src.o \
./Dep/panda/src/express/checksumHashGenerator.o \
./Dep/panda/src/express/compress_string.o \
./Dep/panda/src/express/config_express.o \
./Dep/panda/src/express/copy_stream.o \
./Dep/panda/src/express/datagram.o \
./Dep/panda/src/express/datagramGenerator.o \
./Dep/panda/src/express/datagramIterator.o \
./Dep/panda/src/express/datagramSink.o \
./Dep/panda/src/express/dcast.o \
./Dep/panda/src/express/encrypt_string.o \
./Dep/panda/src/express/error_utils.o \
./Dep/panda/src/express/express_composite.o \
./Dep/panda/src/express/express_composite1.o \
./Dep/panda/src/express/express_composite2.o \
./Dep/panda/src/express/hashGeneratorBase.o \
./Dep/panda/src/express/hashVal.o \
./Dep/panda/src/express/make_ca_bundle.o \
./Dep/panda/src/express/memoryInfo.o \
./Dep/panda/src/express/memoryUsage.o \
./Dep/panda/src/express/memoryUsagePointerCounts.o \
./Dep/panda/src/express/memoryUsagePointers.o \
./Dep/panda/src/express/multifile.o \
./Dep/panda/src/express/namable.o \
./Dep/panda/src/express/nodePointerTo.o \
./Dep/panda/src/express/nodePointerToBase.o \
./Dep/panda/src/express/nodeReferenceCount.o \
./Dep/panda/src/express/openSSLWrapper.o \
./Dep/panda/src/express/ordered_vector.o \
./Dep/panda/src/express/pStatCollectorForwardBase.o \
./Dep/panda/src/express/password_hash.o \
./Dep/panda/src/express/patchfile.o \
./Dep/panda/src/express/pointerTo.o \
./Dep/panda/src/express/pointerToArray.o \
./Dep/panda/src/express/pointerToArrayBase.o \
./Dep/panda/src/express/pointerToBase.o \
./Dep/panda/src/express/pointerToVoid.o \
./Dep/panda/src/express/profileTimer.o \
./Dep/panda/src/express/pta_float.o \
./Dep/panda/src/express/pta_int.o \
./Dep/panda/src/express/pta_uchar.o \
./Dep/panda/src/express/ramfile.o \
./Dep/panda/src/express/referenceCount.o \
./Dep/panda/src/express/stringDecoder.o \
./Dep/panda/src/express/subStream.o \
./Dep/panda/src/express/subStreamBuf.o \
./Dep/panda/src/express/test_ordered_vector.o \
./Dep/panda/src/express/test_types.o \
./Dep/panda/src/express/test_zstream.o \
./Dep/panda/src/express/textEncoder.o \
./Dep/panda/src/express/threadSafePointerTo.o \
./Dep/panda/src/express/threadSafePointerToBase.o \
./Dep/panda/src/express/trueClock.o \
./Dep/panda/src/express/typedReferenceCount.o \
./Dep/panda/src/express/unicodeLatinMap.o \
./Dep/panda/src/express/vector_float.o \
./Dep/panda/src/express/vector_uchar.o \
./Dep/panda/src/express/virtualFile.o \
./Dep/panda/src/express/virtualFileComposite.o \
./Dep/panda/src/express/virtualFileList.o \
./Dep/panda/src/express/virtualFileMount.o \
./Dep/panda/src/express/virtualFileMountMultifile.o \
./Dep/panda/src/express/virtualFileMountSystem.o \
./Dep/panda/src/express/virtualFileSimple.o \
./Dep/panda/src/express/virtualFileSystem.o \
./Dep/panda/src/express/weakPointerCallback.o \
./Dep/panda/src/express/weakPointerTo.o \
./Dep/panda/src/express/weakPointerToBase.o \
./Dep/panda/src/express/weakPointerToVoid.o \
./Dep/panda/src/express/weakReferenceList.o \
./Dep/panda/src/express/windowsRegistry.o \
./Dep/panda/src/express/zStream.o \
./Dep/panda/src/express/zStreamBuf.o 

C_DEPS += \
./Dep/panda/src/express/ca_bundle_data_src.d 

CXX_DEPS += \
./Dep/panda/src/express/buffer.d \
./Dep/panda/src/express/checksumHashGenerator.d \
./Dep/panda/src/express/compress_string.d \
./Dep/panda/src/express/config_express.d \
./Dep/panda/src/express/copy_stream.d \
./Dep/panda/src/express/datagram.d \
./Dep/panda/src/express/datagramGenerator.d \
./Dep/panda/src/express/datagramIterator.d \
./Dep/panda/src/express/datagramSink.d \
./Dep/panda/src/express/dcast.d \
./Dep/panda/src/express/encrypt_string.d \
./Dep/panda/src/express/error_utils.d \
./Dep/panda/src/express/express_composite.d \
./Dep/panda/src/express/express_composite1.d \
./Dep/panda/src/express/express_composite2.d \
./Dep/panda/src/express/hashGeneratorBase.d \
./Dep/panda/src/express/hashVal.d \
./Dep/panda/src/express/make_ca_bundle.d \
./Dep/panda/src/express/memoryInfo.d \
./Dep/panda/src/express/memoryUsage.d \
./Dep/panda/src/express/memoryUsagePointerCounts.d \
./Dep/panda/src/express/memoryUsagePointers.d \
./Dep/panda/src/express/multifile.d \
./Dep/panda/src/express/namable.d \
./Dep/panda/src/express/nodePointerTo.d \
./Dep/panda/src/express/nodePointerToBase.d \
./Dep/panda/src/express/nodeReferenceCount.d \
./Dep/panda/src/express/openSSLWrapper.d \
./Dep/panda/src/express/ordered_vector.d \
./Dep/panda/src/express/pStatCollectorForwardBase.d \
./Dep/panda/src/express/password_hash.d \
./Dep/panda/src/express/patchfile.d \
./Dep/panda/src/express/pointerTo.d \
./Dep/panda/src/express/pointerToArray.d \
./Dep/panda/src/express/pointerToArrayBase.d \
./Dep/panda/src/express/pointerToBase.d \
./Dep/panda/src/express/pointerToVoid.d \
./Dep/panda/src/express/profileTimer.d \
./Dep/panda/src/express/pta_float.d \
./Dep/panda/src/express/pta_int.d \
./Dep/panda/src/express/pta_uchar.d \
./Dep/panda/src/express/ramfile.d \
./Dep/panda/src/express/referenceCount.d \
./Dep/panda/src/express/stringDecoder.d \
./Dep/panda/src/express/subStream.d \
./Dep/panda/src/express/subStreamBuf.d \
./Dep/panda/src/express/test_ordered_vector.d \
./Dep/panda/src/express/test_types.d \
./Dep/panda/src/express/test_zstream.d \
./Dep/panda/src/express/textEncoder.d \
./Dep/panda/src/express/threadSafePointerTo.d \
./Dep/panda/src/express/threadSafePointerToBase.d \
./Dep/panda/src/express/trueClock.d \
./Dep/panda/src/express/typedReferenceCount.d \
./Dep/panda/src/express/unicodeLatinMap.d \
./Dep/panda/src/express/vector_float.d \
./Dep/panda/src/express/vector_uchar.d \
./Dep/panda/src/express/virtualFile.d \
./Dep/panda/src/express/virtualFileComposite.d \
./Dep/panda/src/express/virtualFileList.d \
./Dep/panda/src/express/virtualFileMount.d \
./Dep/panda/src/express/virtualFileMountMultifile.d \
./Dep/panda/src/express/virtualFileMountSystem.d \
./Dep/panda/src/express/virtualFileSimple.d \
./Dep/panda/src/express/virtualFileSystem.d \
./Dep/panda/src/express/weakPointerCallback.d \
./Dep/panda/src/express/weakPointerTo.d \
./Dep/panda/src/express/weakPointerToBase.d \
./Dep/panda/src/express/weakPointerToVoid.d \
./Dep/panda/src/express/weakReferenceList.d \
./Dep/panda/src/express/windowsRegistry.d \
./Dep/panda/src/express/zStream.d \
./Dep/panda/src/express/zStreamBuf.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/express/%.o: ../Dep/panda/src/express/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Dep/panda/src/express/%.o: ../Dep/panda/src/express/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


