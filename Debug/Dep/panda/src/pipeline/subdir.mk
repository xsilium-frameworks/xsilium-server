################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dep/panda/src/pipeline/contextSwitch.c \
../Dep/panda/src/pipeline/contextSwitch_longjmp_src.c \
../Dep/panda/src/pipeline/contextSwitch_posix_src.c \
../Dep/panda/src/pipeline/contextSwitch_ucontext_src.c \
../Dep/panda/src/pipeline/contextSwitch_windows_src.c 

CXX_SRCS += \
../Dep/panda/src/pipeline/asyncTaskBase.cxx \
../Dep/panda/src/pipeline/conditionVar.cxx \
../Dep/panda/src/pipeline/conditionVarDebug.cxx \
../Dep/panda/src/pipeline/conditionVarDirect.cxx \
../Dep/panda/src/pipeline/conditionVarDummyImpl.cxx \
../Dep/panda/src/pipeline/conditionVarFull.cxx \
../Dep/panda/src/pipeline/conditionVarFullDebug.cxx \
../Dep/panda/src/pipeline/conditionVarFullDirect.cxx \
../Dep/panda/src/pipeline/conditionVarFullWin32Impl.cxx \
../Dep/panda/src/pipeline/conditionVarPosixImpl.cxx \
../Dep/panda/src/pipeline/conditionVarSimpleImpl.cxx \
../Dep/panda/src/pipeline/conditionVarSpinlockImpl.cxx \
../Dep/panda/src/pipeline/conditionVarWin32Impl.cxx \
../Dep/panda/src/pipeline/config_pipeline.cxx \
../Dep/panda/src/pipeline/cycleData.cxx \
../Dep/panda/src/pipeline/cycleDataLockedReader.cxx \
../Dep/panda/src/pipeline/cycleDataLockedStageReader.cxx \
../Dep/panda/src/pipeline/cycleDataReader.cxx \
../Dep/panda/src/pipeline/cycleDataStageReader.cxx \
../Dep/panda/src/pipeline/cycleDataStageWriter.cxx \
../Dep/panda/src/pipeline/cycleDataWriter.cxx \
../Dep/panda/src/pipeline/cyclerHolder.cxx \
../Dep/panda/src/pipeline/externalThread.cxx \
../Dep/panda/src/pipeline/lightMutex.cxx \
../Dep/panda/src/pipeline/lightMutexDirect.cxx \
../Dep/panda/src/pipeline/lightMutexHolder.cxx \
../Dep/panda/src/pipeline/lightReMutex.cxx \
../Dep/panda/src/pipeline/lightReMutexDirect.cxx \
../Dep/panda/src/pipeline/lightReMutexHolder.cxx \
../Dep/panda/src/pipeline/mainThread.cxx \
../Dep/panda/src/pipeline/mutexDebug.cxx \
../Dep/panda/src/pipeline/mutexDirect.cxx \
../Dep/panda/src/pipeline/mutexHolder.cxx \
../Dep/panda/src/pipeline/mutexSimpleImpl.cxx \
../Dep/panda/src/pipeline/pipeline.cxx \
../Dep/panda/src/pipeline/pipelineCycler.cxx \
../Dep/panda/src/pipeline/pipelineCyclerDummyImpl.cxx \
../Dep/panda/src/pipeline/pipelineCyclerTrivialImpl.cxx \
../Dep/panda/src/pipeline/pipelineCyclerTrueImpl.cxx \
../Dep/panda/src/pipeline/pipeline_composite.cxx \
../Dep/panda/src/pipeline/pipeline_composite1.cxx \
../Dep/panda/src/pipeline/pipeline_composite2.cxx \
../Dep/panda/src/pipeline/pmutex.cxx \
../Dep/panda/src/pipeline/psemaphore.cxx \
../Dep/panda/src/pipeline/pythonThread.cxx \
../Dep/panda/src/pipeline/reMutex.cxx \
../Dep/panda/src/pipeline/reMutexDirect.cxx \
../Dep/panda/src/pipeline/reMutexHolder.cxx \
../Dep/panda/src/pipeline/test_atomic.cxx \
../Dep/panda/src/pipeline/test_concurrency.cxx \
../Dep/panda/src/pipeline/test_delete.cxx \
../Dep/panda/src/pipeline/test_diners.cxx \
../Dep/panda/src/pipeline/test_mutex.cxx \
../Dep/panda/src/pipeline/test_setjmp.cxx \
../Dep/panda/src/pipeline/test_threaddata.cxx \
../Dep/panda/src/pipeline/thread.cxx \
../Dep/panda/src/pipeline/threadDummyImpl.cxx \
../Dep/panda/src/pipeline/threadPosixImpl.cxx \
../Dep/panda/src/pipeline/threadPriority.cxx \
../Dep/panda/src/pipeline/threadSimpleImpl.cxx \
../Dep/panda/src/pipeline/threadSimpleManager.cxx \
../Dep/panda/src/pipeline/threadWin32Impl.cxx 

OBJS += \
./Dep/panda/src/pipeline/asyncTaskBase.o \
./Dep/panda/src/pipeline/conditionVar.o \
./Dep/panda/src/pipeline/conditionVarDebug.o \
./Dep/panda/src/pipeline/conditionVarDirect.o \
./Dep/panda/src/pipeline/conditionVarDummyImpl.o \
./Dep/panda/src/pipeline/conditionVarFull.o \
./Dep/panda/src/pipeline/conditionVarFullDebug.o \
./Dep/panda/src/pipeline/conditionVarFullDirect.o \
./Dep/panda/src/pipeline/conditionVarFullWin32Impl.o \
./Dep/panda/src/pipeline/conditionVarPosixImpl.o \
./Dep/panda/src/pipeline/conditionVarSimpleImpl.o \
./Dep/panda/src/pipeline/conditionVarSpinlockImpl.o \
./Dep/panda/src/pipeline/conditionVarWin32Impl.o \
./Dep/panda/src/pipeline/config_pipeline.o \
./Dep/panda/src/pipeline/contextSwitch.o \
./Dep/panda/src/pipeline/contextSwitch_longjmp_src.o \
./Dep/panda/src/pipeline/contextSwitch_posix_src.o \
./Dep/panda/src/pipeline/contextSwitch_ucontext_src.o \
./Dep/panda/src/pipeline/contextSwitch_windows_src.o \
./Dep/panda/src/pipeline/cycleData.o \
./Dep/panda/src/pipeline/cycleDataLockedReader.o \
./Dep/panda/src/pipeline/cycleDataLockedStageReader.o \
./Dep/panda/src/pipeline/cycleDataReader.o \
./Dep/panda/src/pipeline/cycleDataStageReader.o \
./Dep/panda/src/pipeline/cycleDataStageWriter.o \
./Dep/panda/src/pipeline/cycleDataWriter.o \
./Dep/panda/src/pipeline/cyclerHolder.o \
./Dep/panda/src/pipeline/externalThread.o \
./Dep/panda/src/pipeline/lightMutex.o \
./Dep/panda/src/pipeline/lightMutexDirect.o \
./Dep/panda/src/pipeline/lightMutexHolder.o \
./Dep/panda/src/pipeline/lightReMutex.o \
./Dep/panda/src/pipeline/lightReMutexDirect.o \
./Dep/panda/src/pipeline/lightReMutexHolder.o \
./Dep/panda/src/pipeline/mainThread.o \
./Dep/panda/src/pipeline/mutexDebug.o \
./Dep/panda/src/pipeline/mutexDirect.o \
./Dep/panda/src/pipeline/mutexHolder.o \
./Dep/panda/src/pipeline/mutexSimpleImpl.o \
./Dep/panda/src/pipeline/pipeline.o \
./Dep/panda/src/pipeline/pipelineCycler.o \
./Dep/panda/src/pipeline/pipelineCyclerDummyImpl.o \
./Dep/panda/src/pipeline/pipelineCyclerTrivialImpl.o \
./Dep/panda/src/pipeline/pipelineCyclerTrueImpl.o \
./Dep/panda/src/pipeline/pipeline_composite.o \
./Dep/panda/src/pipeline/pipeline_composite1.o \
./Dep/panda/src/pipeline/pipeline_composite2.o \
./Dep/panda/src/pipeline/pmutex.o \
./Dep/panda/src/pipeline/psemaphore.o \
./Dep/panda/src/pipeline/pythonThread.o \
./Dep/panda/src/pipeline/reMutex.o \
./Dep/panda/src/pipeline/reMutexDirect.o \
./Dep/panda/src/pipeline/reMutexHolder.o \
./Dep/panda/src/pipeline/test_atomic.o \
./Dep/panda/src/pipeline/test_concurrency.o \
./Dep/panda/src/pipeline/test_delete.o \
./Dep/panda/src/pipeline/test_diners.o \
./Dep/panda/src/pipeline/test_mutex.o \
./Dep/panda/src/pipeline/test_setjmp.o \
./Dep/panda/src/pipeline/test_threaddata.o \
./Dep/panda/src/pipeline/thread.o \
./Dep/panda/src/pipeline/threadDummyImpl.o \
./Dep/panda/src/pipeline/threadPosixImpl.o \
./Dep/panda/src/pipeline/threadPriority.o \
./Dep/panda/src/pipeline/threadSimpleImpl.o \
./Dep/panda/src/pipeline/threadSimpleManager.o \
./Dep/panda/src/pipeline/threadWin32Impl.o 

C_DEPS += \
./Dep/panda/src/pipeline/contextSwitch.d \
./Dep/panda/src/pipeline/contextSwitch_longjmp_src.d \
./Dep/panda/src/pipeline/contextSwitch_posix_src.d \
./Dep/panda/src/pipeline/contextSwitch_ucontext_src.d \
./Dep/panda/src/pipeline/contextSwitch_windows_src.d 

CXX_DEPS += \
./Dep/panda/src/pipeline/asyncTaskBase.d \
./Dep/panda/src/pipeline/conditionVar.d \
./Dep/panda/src/pipeline/conditionVarDebug.d \
./Dep/panda/src/pipeline/conditionVarDirect.d \
./Dep/panda/src/pipeline/conditionVarDummyImpl.d \
./Dep/panda/src/pipeline/conditionVarFull.d \
./Dep/panda/src/pipeline/conditionVarFullDebug.d \
./Dep/panda/src/pipeline/conditionVarFullDirect.d \
./Dep/panda/src/pipeline/conditionVarFullWin32Impl.d \
./Dep/panda/src/pipeline/conditionVarPosixImpl.d \
./Dep/panda/src/pipeline/conditionVarSimpleImpl.d \
./Dep/panda/src/pipeline/conditionVarSpinlockImpl.d \
./Dep/panda/src/pipeline/conditionVarWin32Impl.d \
./Dep/panda/src/pipeline/config_pipeline.d \
./Dep/panda/src/pipeline/cycleData.d \
./Dep/panda/src/pipeline/cycleDataLockedReader.d \
./Dep/panda/src/pipeline/cycleDataLockedStageReader.d \
./Dep/panda/src/pipeline/cycleDataReader.d \
./Dep/panda/src/pipeline/cycleDataStageReader.d \
./Dep/panda/src/pipeline/cycleDataStageWriter.d \
./Dep/panda/src/pipeline/cycleDataWriter.d \
./Dep/panda/src/pipeline/cyclerHolder.d \
./Dep/panda/src/pipeline/externalThread.d \
./Dep/panda/src/pipeline/lightMutex.d \
./Dep/panda/src/pipeline/lightMutexDirect.d \
./Dep/panda/src/pipeline/lightMutexHolder.d \
./Dep/panda/src/pipeline/lightReMutex.d \
./Dep/panda/src/pipeline/lightReMutexDirect.d \
./Dep/panda/src/pipeline/lightReMutexHolder.d \
./Dep/panda/src/pipeline/mainThread.d \
./Dep/panda/src/pipeline/mutexDebug.d \
./Dep/panda/src/pipeline/mutexDirect.d \
./Dep/panda/src/pipeline/mutexHolder.d \
./Dep/panda/src/pipeline/mutexSimpleImpl.d \
./Dep/panda/src/pipeline/pipeline.d \
./Dep/panda/src/pipeline/pipelineCycler.d \
./Dep/panda/src/pipeline/pipelineCyclerDummyImpl.d \
./Dep/panda/src/pipeline/pipelineCyclerTrivialImpl.d \
./Dep/panda/src/pipeline/pipelineCyclerTrueImpl.d \
./Dep/panda/src/pipeline/pipeline_composite.d \
./Dep/panda/src/pipeline/pipeline_composite1.d \
./Dep/panda/src/pipeline/pipeline_composite2.d \
./Dep/panda/src/pipeline/pmutex.d \
./Dep/panda/src/pipeline/psemaphore.d \
./Dep/panda/src/pipeline/pythonThread.d \
./Dep/panda/src/pipeline/reMutex.d \
./Dep/panda/src/pipeline/reMutexDirect.d \
./Dep/panda/src/pipeline/reMutexHolder.d \
./Dep/panda/src/pipeline/test_atomic.d \
./Dep/panda/src/pipeline/test_concurrency.d \
./Dep/panda/src/pipeline/test_delete.d \
./Dep/panda/src/pipeline/test_diners.d \
./Dep/panda/src/pipeline/test_mutex.d \
./Dep/panda/src/pipeline/test_setjmp.d \
./Dep/panda/src/pipeline/test_threaddata.d \
./Dep/panda/src/pipeline/thread.d \
./Dep/panda/src/pipeline/threadDummyImpl.d \
./Dep/panda/src/pipeline/threadPosixImpl.d \
./Dep/panda/src/pipeline/threadPriority.d \
./Dep/panda/src/pipeline/threadSimpleImpl.d \
./Dep/panda/src/pipeline/threadSimpleManager.d \
./Dep/panda/src/pipeline/threadWin32Impl.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/pipeline/%.o: ../Dep/panda/src/pipeline/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Dep/panda/src/pipeline/%.o: ../Dep/panda/src/pipeline/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


