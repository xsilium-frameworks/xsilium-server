################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/server/Shared/Database/Implementation/CharacterDatabase.cpp \
../src/server/Shared/Database/Implementation/LoginDatabase.cpp \
../src/server/Shared/Database/Implementation/WorldDatabase.cpp 

OBJS += \
./src/server/Shared/Database/Implementation/CharacterDatabase.o \
./src/server/Shared/Database/Implementation/LoginDatabase.o \
./src/server/Shared/Database/Implementation/WorldDatabase.o 

CPP_DEPS += \
./src/server/Shared/Database/Implementation/CharacterDatabase.d \
./src/server/Shared/Database/Implementation/LoginDatabase.d \
./src/server/Shared/Database/Implementation/WorldDatabase.d 


# Each subdirectory must supply rules for building sources it contributes
src/server/Shared/Database/Implementation/%.o: ../src/server/Shared/Database/Implementation/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep/Raknet" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


