################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Controllers/DungeonController.cpp \
../src/Controllers/Monk.cpp \
../src/Controllers/Monster.cpp \
../src/Controllers/Util.cpp 

CPP_DEPS += \
./src/Controllers/DungeonController.d \
./src/Controllers/Monk.d \
./src/Controllers/Monster.d \
./src/Controllers/Util.d 

OBJS += \
./src/Controllers/DungeonController.o \
./src/Controllers/Monk.o \
./src/Controllers/Monster.o \
./src/Controllers/Util.o 


# Each subdirectory must supply rules for building sources it contributes
src/Controllers/%.o: ../src/Controllers/%.cpp src/Controllers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-Controllers

clean-src-2f-Controllers:
	-$(RM) ./src/Controllers/DungeonController.d ./src/Controllers/DungeonController.o ./src/Controllers/Monk.d ./src/Controllers/Monk.o ./src/Controllers/Monster.d ./src/Controllers/Monster.o ./src/Controllers/Util.d ./src/Controllers/Util.o

.PHONY: clean-src-2f-Controllers

