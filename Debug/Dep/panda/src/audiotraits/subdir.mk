################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/audiotraits/config_fmodAudio.cxx \
../Dep/panda/src/audiotraits/config_milesAudio.cxx \
../Dep/panda/src/audiotraits/config_openalAudio.cxx \
../Dep/panda/src/audiotraits/fmodAudioManager.cxx \
../Dep/panda/src/audiotraits/fmodAudioSound.cxx \
../Dep/panda/src/audiotraits/fmod_audio_composite.cxx \
../Dep/panda/src/audiotraits/fmod_audio_composite1.cxx \
../Dep/panda/src/audiotraits/globalMilesManager.cxx \
../Dep/panda/src/audiotraits/milesAudioManager.cxx \
../Dep/panda/src/audiotraits/milesAudioSample.cxx \
../Dep/panda/src/audiotraits/milesAudioSequence.cxx \
../Dep/panda/src/audiotraits/milesAudioSound.cxx \
../Dep/panda/src/audiotraits/milesAudioStream.cxx \
../Dep/panda/src/audiotraits/miles_audio_composite.cxx \
../Dep/panda/src/audiotraits/miles_audio_composite1.cxx \
../Dep/panda/src/audiotraits/openalAudioManager.cxx \
../Dep/panda/src/audiotraits/openalAudioSound.cxx \
../Dep/panda/src/audiotraits/openal_audio_composite.cxx \
../Dep/panda/src/audiotraits/openal_audio_composite1.cxx 

OBJS += \
./Dep/panda/src/audiotraits/config_fmodAudio.o \
./Dep/panda/src/audiotraits/config_milesAudio.o \
./Dep/panda/src/audiotraits/config_openalAudio.o \
./Dep/panda/src/audiotraits/fmodAudioManager.o \
./Dep/panda/src/audiotraits/fmodAudioSound.o \
./Dep/panda/src/audiotraits/fmod_audio_composite.o \
./Dep/panda/src/audiotraits/fmod_audio_composite1.o \
./Dep/panda/src/audiotraits/globalMilesManager.o \
./Dep/panda/src/audiotraits/milesAudioManager.o \
./Dep/panda/src/audiotraits/milesAudioSample.o \
./Dep/panda/src/audiotraits/milesAudioSequence.o \
./Dep/panda/src/audiotraits/milesAudioSound.o \
./Dep/panda/src/audiotraits/milesAudioStream.o \
./Dep/panda/src/audiotraits/miles_audio_composite.o \
./Dep/panda/src/audiotraits/miles_audio_composite1.o \
./Dep/panda/src/audiotraits/openalAudioManager.o \
./Dep/panda/src/audiotraits/openalAudioSound.o \
./Dep/panda/src/audiotraits/openal_audio_composite.o \
./Dep/panda/src/audiotraits/openal_audio_composite1.o 

CXX_DEPS += \
./Dep/panda/src/audiotraits/config_fmodAudio.d \
./Dep/panda/src/audiotraits/config_milesAudio.d \
./Dep/panda/src/audiotraits/config_openalAudio.d \
./Dep/panda/src/audiotraits/fmodAudioManager.d \
./Dep/panda/src/audiotraits/fmodAudioSound.d \
./Dep/panda/src/audiotraits/fmod_audio_composite.d \
./Dep/panda/src/audiotraits/fmod_audio_composite1.d \
./Dep/panda/src/audiotraits/globalMilesManager.d \
./Dep/panda/src/audiotraits/milesAudioManager.d \
./Dep/panda/src/audiotraits/milesAudioSample.d \
./Dep/panda/src/audiotraits/milesAudioSequence.d \
./Dep/panda/src/audiotraits/milesAudioSound.d \
./Dep/panda/src/audiotraits/milesAudioStream.d \
./Dep/panda/src/audiotraits/miles_audio_composite.d \
./Dep/panda/src/audiotraits/miles_audio_composite1.d \
./Dep/panda/src/audiotraits/openalAudioManager.d \
./Dep/panda/src/audiotraits/openalAudioSound.d \
./Dep/panda/src/audiotraits/openal_audio_composite.d \
./Dep/panda/src/audiotraits/openal_audio_composite1.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/audiotraits/%.o: ../Dep/panda/src/audiotraits/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


