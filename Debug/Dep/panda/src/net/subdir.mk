################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/net/config_net.cxx \
../Dep/panda/src/net/connection.cxx \
../Dep/panda/src/net/connectionListener.cxx \
../Dep/panda/src/net/connectionManager.cxx \
../Dep/panda/src/net/connectionReader.cxx \
../Dep/panda/src/net/connectionWriter.cxx \
../Dep/panda/src/net/datagramGeneratorNet.cxx \
../Dep/panda/src/net/datagramQueue.cxx \
../Dep/panda/src/net/datagramSinkNet.cxx \
../Dep/panda/src/net/datagramTCPHeader.cxx \
../Dep/panda/src/net/datagramUDPHeader.cxx \
../Dep/panda/src/net/datagram_ui.cxx \
../Dep/panda/src/net/fake_http_server.cxx \
../Dep/panda/src/net/netAddress.cxx \
../Dep/panda/src/net/netDatagram.cxx \
../Dep/panda/src/net/net_composite.cxx \
../Dep/panda/src/net/net_composite1.cxx \
../Dep/panda/src/net/net_composite2.cxx \
../Dep/panda/src/net/queuedConnectionListener.cxx \
../Dep/panda/src/net/queuedConnectionManager.cxx \
../Dep/panda/src/net/queuedConnectionReader.cxx \
../Dep/panda/src/net/recentConnectionReader.cxx \
../Dep/panda/src/net/test_datagram.cxx \
../Dep/panda/src/net/test_raw_server.cxx \
../Dep/panda/src/net/test_spam_client.cxx \
../Dep/panda/src/net/test_spam_server.cxx \
../Dep/panda/src/net/test_tcp_client.cxx \
../Dep/panda/src/net/test_tcp_server.cxx \
../Dep/panda/src/net/test_udp.cxx 

OBJS += \
./Dep/panda/src/net/config_net.o \
./Dep/panda/src/net/connection.o \
./Dep/panda/src/net/connectionListener.o \
./Dep/panda/src/net/connectionManager.o \
./Dep/panda/src/net/connectionReader.o \
./Dep/panda/src/net/connectionWriter.o \
./Dep/panda/src/net/datagramGeneratorNet.o \
./Dep/panda/src/net/datagramQueue.o \
./Dep/panda/src/net/datagramSinkNet.o \
./Dep/panda/src/net/datagramTCPHeader.o \
./Dep/panda/src/net/datagramUDPHeader.o \
./Dep/panda/src/net/datagram_ui.o \
./Dep/panda/src/net/fake_http_server.o \
./Dep/panda/src/net/netAddress.o \
./Dep/panda/src/net/netDatagram.o \
./Dep/panda/src/net/net_composite.o \
./Dep/panda/src/net/net_composite1.o \
./Dep/panda/src/net/net_composite2.o \
./Dep/panda/src/net/queuedConnectionListener.o \
./Dep/panda/src/net/queuedConnectionManager.o \
./Dep/panda/src/net/queuedConnectionReader.o \
./Dep/panda/src/net/recentConnectionReader.o \
./Dep/panda/src/net/test_datagram.o \
./Dep/panda/src/net/test_raw_server.o \
./Dep/panda/src/net/test_spam_client.o \
./Dep/panda/src/net/test_spam_server.o \
./Dep/panda/src/net/test_tcp_client.o \
./Dep/panda/src/net/test_tcp_server.o \
./Dep/panda/src/net/test_udp.o 

CXX_DEPS += \
./Dep/panda/src/net/config_net.d \
./Dep/panda/src/net/connection.d \
./Dep/panda/src/net/connectionListener.d \
./Dep/panda/src/net/connectionManager.d \
./Dep/panda/src/net/connectionReader.d \
./Dep/panda/src/net/connectionWriter.d \
./Dep/panda/src/net/datagramGeneratorNet.d \
./Dep/panda/src/net/datagramQueue.d \
./Dep/panda/src/net/datagramSinkNet.d \
./Dep/panda/src/net/datagramTCPHeader.d \
./Dep/panda/src/net/datagramUDPHeader.d \
./Dep/panda/src/net/datagram_ui.d \
./Dep/panda/src/net/fake_http_server.d \
./Dep/panda/src/net/netAddress.d \
./Dep/panda/src/net/netDatagram.d \
./Dep/panda/src/net/net_composite.d \
./Dep/panda/src/net/net_composite1.d \
./Dep/panda/src/net/net_composite2.d \
./Dep/panda/src/net/queuedConnectionListener.d \
./Dep/panda/src/net/queuedConnectionManager.d \
./Dep/panda/src/net/queuedConnectionReader.d \
./Dep/panda/src/net/recentConnectionReader.d \
./Dep/panda/src/net/test_datagram.d \
./Dep/panda/src/net/test_raw_server.d \
./Dep/panda/src/net/test_spam_client.d \
./Dep/panda/src/net/test_spam_server.d \
./Dep/panda/src/net/test_tcp_client.d \
./Dep/panda/src/net/test_tcp_server.d \
./Dep/panda/src/net/test_udp.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/net/%.o: ../Dep/panda/src/net/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


