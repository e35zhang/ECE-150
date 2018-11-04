################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Binary\ conversiton.cpp 

OBJS += \
./src/Binary\ conversiton.o 

CPP_DEPS += \
./src/Binary\ conversiton.d 


# Each subdirectory must supply rules for building sources it contributes
src/Binary\ conversiton.o: ../src/Binary\ conversiton.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Binary conversiton.d" -MT"src/Binary\ conversiton.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


