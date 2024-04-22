################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Rooms/EmptyRoom.cpp \
../src/Rooms/MonsterRoom.cpp \
../src/Rooms/TreasureRoom.cpp 

CPP_DEPS += \
./src/Rooms/EmptyRoom.d \
./src/Rooms/MonsterRoom.d \
./src/Rooms/TreasureRoom.d 

OBJS += \
./src/Rooms/EmptyRoom.o \
./src/Rooms/MonsterRoom.o \
./src/Rooms/TreasureRoom.o 


# Each subdirectory must supply rules for building sources it contributes
src/Rooms/%.o: ../src/Rooms/%.cpp src/Rooms/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-Rooms

clean-src-2f-Rooms:
	-$(RM) ./src/Rooms/EmptyRoom.d ./src/Rooms/EmptyRoom.o ./src/Rooms/MonsterRoom.d ./src/Rooms/MonsterRoom.o ./src/Rooms/TreasureRoom.d ./src/Rooms/TreasureRoom.o

.PHONY: clean-src-2f-Rooms

