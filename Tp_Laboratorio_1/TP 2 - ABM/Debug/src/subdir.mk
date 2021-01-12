################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ArrayEmployees.c \
../src/TP\ 2\ -\ ABM.c \
../src/utn.c 

OBJS += \
./src/ArrayEmployees.o \
./src/TP\ 2\ -\ ABM.o \
./src/utn.o 

C_DEPS += \
./src/ArrayEmployees.d \
./src/TP\ 2\ -\ ABM.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/TP\ 2\ -\ ABM.o: ../src/TP\ 2\ -\ ABM.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/TP 2 - ABM.d" -MT"src/TP\ 2\ -\ ABM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


