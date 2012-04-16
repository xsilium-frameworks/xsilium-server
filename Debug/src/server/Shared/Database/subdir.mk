################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/server/Shared/Database/DatabaseWorker.cpp \
../src/server/Shared/Database/Field.cpp \
../src/server/Shared/Database/MySQLConnection.cpp \
../src/server/Shared/Database/PreparedStatement.cpp \
../src/server/Shared/Database/QueryResult.cpp \
../src/server/Shared/Database/SQLOperation.cpp \
../src/server/Shared/Database/SQLStorage.cpp \
../src/server/Shared/Database/Transaction.cpp 

OBJS += \
./src/server/Shared/Database/DatabaseWorker.o \
./src/server/Shared/Database/Field.o \
./src/server/Shared/Database/MySQLConnection.o \
./src/server/Shared/Database/PreparedStatement.o \
./src/server/Shared/Database/QueryResult.o \
./src/server/Shared/Database/SQLOperation.o \
./src/server/Shared/Database/SQLStorage.o \
./src/server/Shared/Database/Transaction.o 

CPP_DEPS += \
./src/server/Shared/Database/DatabaseWorker.d \
./src/server/Shared/Database/Field.d \
./src/server/Shared/Database/MySQLConnection.d \
./src/server/Shared/Database/PreparedStatement.d \
./src/server/Shared/Database/QueryResult.d \
./src/server/Shared/Database/SQLOperation.d \
./src/server/Shared/Database/SQLStorage.d \
./src/server/Shared/Database/Transaction.d 


# Each subdirectory must supply rules for building sources it contributes
src/server/Shared/Database/%.o: ../src/server/Shared/Database/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep/Raknet" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


