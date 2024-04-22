################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Models/Character.cpp \
../src/Models/Room.cpp 

CPP_DEPS += \
./src/Models/Character.d \
./src/Models/Room.d 

OBJS += \
./src/Models/Character.o \
./src/Models/Room.o 


# Each subdirectory must supply rules for building sources it contributes
src/Models/%.o: ../src/Models/%.cpp src/Models/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-Models

clean-src-2f-Models:
	-$(RM) ./src/Models/Character.d ./src/Models/Character.o ./src/Models/Room.d ./src/Models/Room.o

.PHONY: clean-src-2f-Models

