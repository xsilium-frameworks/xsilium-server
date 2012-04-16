################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/movies/config_movies.cxx \
../Dep/panda/src/movies/ffmpegAudio.cxx \
../Dep/panda/src/movies/ffmpegAudioCursor.cxx \
../Dep/panda/src/movies/ffmpegVideo.cxx \
../Dep/panda/src/movies/ffmpegVideoCursor.cxx \
../Dep/panda/src/movies/ffmpegVirtualFile.cxx \
../Dep/panda/src/movies/inkblotVideo.cxx \
../Dep/panda/src/movies/inkblotVideoCursor.cxx \
../Dep/panda/src/movies/microphoneAudio.cxx \
../Dep/panda/src/movies/microphoneAudioDS.cxx \
../Dep/panda/src/movies/movieAudio.cxx \
../Dep/panda/src/movies/movieAudioCursor.cxx \
../Dep/panda/src/movies/movieVideo.cxx \
../Dep/panda/src/movies/movieVideoCursor.cxx \
../Dep/panda/src/movies/movies_composite.cxx \
../Dep/panda/src/movies/movies_composite1.cxx \
../Dep/panda/src/movies/userDataAudio.cxx \
../Dep/panda/src/movies/userDataAudioCursor.cxx 

OBJS += \
./Dep/panda/src/movies/config_movies.o \
./Dep/panda/src/movies/ffmpegAudio.o \
./Dep/panda/src/movies/ffmpegAudioCursor.o \
./Dep/panda/src/movies/ffmpegVideo.o \
./Dep/panda/src/movies/ffmpegVideoCursor.o \
./Dep/panda/src/movies/ffmpegVirtualFile.o \
./Dep/panda/src/movies/inkblotVideo.o \
./Dep/panda/src/movies/inkblotVideoCursor.o \
./Dep/panda/src/movies/microphoneAudio.o \
./Dep/panda/src/movies/microphoneAudioDS.o \
./Dep/panda/src/movies/movieAudio.o \
./Dep/panda/src/movies/movieAudioCursor.o \
./Dep/panda/src/movies/movieVideo.o \
./Dep/panda/src/movies/movieVideoCursor.o \
./Dep/panda/src/movies/movies_composite.o \
./Dep/panda/src/movies/movies_composite1.o \
./Dep/panda/src/movies/userDataAudio.o \
./Dep/panda/src/movies/userDataAudioCursor.o 

CXX_DEPS += \
./Dep/panda/src/movies/config_movies.d \
./Dep/panda/src/movies/ffmpegAudio.d \
./Dep/panda/src/movies/ffmpegAudioCursor.d \
./Dep/panda/src/movies/ffmpegVideo.d \
./Dep/panda/src/movies/ffmpegVideoCursor.d \
./Dep/panda/src/movies/ffmpegVirtualFile.d \
./Dep/panda/src/movies/inkblotVideo.d \
./Dep/panda/src/movies/inkblotVideoCursor.d \
./Dep/panda/src/movies/microphoneAudio.d \
./Dep/panda/src/movies/microphoneAudioDS.d \
./Dep/panda/src/movies/movieAudio.d \
./Dep/panda/src/movies/movieAudioCursor.d \
./Dep/panda/src/movies/movieVideo.d \
./Dep/panda/src/movies/movieVideoCursor.d \
./Dep/panda/src/movies/movies_composite.d \
./Dep/panda/src/movies/movies_composite1.d \
./Dep/panda/src/movies/userDataAudio.d \
./Dep/panda/src/movies/userDataAudioCursor.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/movies/%.o: ../Dep/panda/src/movies/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


