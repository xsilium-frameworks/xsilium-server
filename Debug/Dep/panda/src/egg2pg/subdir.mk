################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../Dep/panda/src/egg2pg/animBundleMaker.cxx \
../Dep/panda/src/egg2pg/characterMaker.cxx \
../Dep/panda/src/egg2pg/config_egg2pg.cxx \
../Dep/panda/src/egg2pg/deferredNodeProperty.cxx \
../Dep/panda/src/egg2pg/egg2pg_composite.cxx \
../Dep/panda/src/egg2pg/egg2pg_composite1.cxx \
../Dep/panda/src/egg2pg/egg2pg_composite2.cxx \
../Dep/panda/src/egg2pg/eggBinner.cxx \
../Dep/panda/src/egg2pg/eggLoader.cxx \
../Dep/panda/src/egg2pg/eggRenderState.cxx \
../Dep/panda/src/egg2pg/egg_parametrics.cxx \
../Dep/panda/src/egg2pg/load_egg_file.cxx \
../Dep/panda/src/egg2pg/loaderFileTypeEgg.cxx 

OBJS += \
./Dep/panda/src/egg2pg/animBundleMaker.o \
./Dep/panda/src/egg2pg/characterMaker.o \
./Dep/panda/src/egg2pg/config_egg2pg.o \
./Dep/panda/src/egg2pg/deferredNodeProperty.o \
./Dep/panda/src/egg2pg/egg2pg_composite.o \
./Dep/panda/src/egg2pg/egg2pg_composite1.o \
./Dep/panda/src/egg2pg/egg2pg_composite2.o \
./Dep/panda/src/egg2pg/eggBinner.o \
./Dep/panda/src/egg2pg/eggLoader.o \
./Dep/panda/src/egg2pg/eggRenderState.o \
./Dep/panda/src/egg2pg/egg_parametrics.o \
./Dep/panda/src/egg2pg/load_egg_file.o \
./Dep/panda/src/egg2pg/loaderFileTypeEgg.o 

CXX_DEPS += \
./Dep/panda/src/egg2pg/animBundleMaker.d \
./Dep/panda/src/egg2pg/characterMaker.d \
./Dep/panda/src/egg2pg/config_egg2pg.d \
./Dep/panda/src/egg2pg/deferredNodeProperty.d \
./Dep/panda/src/egg2pg/egg2pg_composite.d \
./Dep/panda/src/egg2pg/egg2pg_composite1.d \
./Dep/panda/src/egg2pg/egg2pg_composite2.d \
./Dep/panda/src/egg2pg/eggBinner.d \
./Dep/panda/src/egg2pg/eggLoader.d \
./Dep/panda/src/egg2pg/eggRenderState.d \
./Dep/panda/src/egg2pg/egg_parametrics.d \
./Dep/panda/src/egg2pg/load_egg_file.d \
./Dep/panda/src/egg2pg/loaderFileTypeEgg.d 


# Each subdirectory must supply rules for building sources it contributes
Dep/panda/src/egg2pg/%.o: ../Dep/panda/src/egg2pg/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/joda2/workspace/xsilium/Dep" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


