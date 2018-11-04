################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Matrix\ Multiplication.cpp 

OBJS += \
./src/Matrix\ Multiplication.o 

CPP_DEPS += \
./src/Matrix\ Multiplication.d 


# Each subdirectory must supply rules for building sources it contributes
src/Matrix\ Multiplication.o: ../src/Matrix\ Multiplication.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Matrix Multiplication.d" -MT"src/Matrix\ Multiplication.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


