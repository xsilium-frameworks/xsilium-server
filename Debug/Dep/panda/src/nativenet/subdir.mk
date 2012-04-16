################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/nativenet/buffered_datagramconnection.cxx \
../Dep/panda/src/nativenet/config_nativenet.cxx \
../Dep/panda/src/nativenet/nativenet_composite1.cxx \
../Dep/panda/src/nativenet/socket_ip.cxx \
../Dep/panda/src/nativenet/socket_tcp.cxx \
../Dep/panda/src/nativenet/socket_tcp_listen.cxx \
../Dep/panda/src/nativenet/socket_tcp_ssl.cxx \
../Dep/panda/src/nativenet/socket_udp.cxx \
../Dep/panda/src/nativenet/socket_udp_incoming.cxx \
../Dep/panda/src/nativenet/socket_udp_outgoing.cxx 

OBJS += \
./Dep/panda/src/nativenet/buffered_datagramconnection.o \
./Dep/panda/src/nativenet/config_nativenet.o \
./Dep/panda/src/nativenet/nativenet_composite1.o \
./Dep/panda/src/nativenet/socket_ip.o \
./Dep/panda/src/nativenet/socket_tcp.o \
./Dep/panda/src/nativenet/socket_tcp_listen.o \
./Dep/panda/src/nativenet/socket_tcp_ssl.o \
./Dep/panda/src/nativenet/socket_udp.o \
./Dep/panda/src/nativenet/socket_udp_incoming.o \
./Dep/panda/src/nativenet/socket_udp_outgoing.o 

CXX_DEPS += \
./Dep/panda/src/nativenet/buffered_datagramconnection.d \
./Dep/panda/src/nativenet/config_nativenet.d \
./Dep/panda/src/nativenet/nativenet_composite1.d \
./Dep/panda/src/nativenet/socket_ip.d \
./Dep/panda/src/nativenet/socket_tcp.d \
./Dep/panda/src/nativenet/socket_tcp_listen.d \
./Dep/panda/src/nativenet/socket_tcp_ssl.d \
./Dep/panda/src/nativenet/socket_udp.d \
./Dep/panda/src/nativenet/socket_udp_incoming.d \
./Dep/panda/src/nativenet/socket_udp_outgoing.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/nativenet/%.o: ../Dep/panda/src/nativenet/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


