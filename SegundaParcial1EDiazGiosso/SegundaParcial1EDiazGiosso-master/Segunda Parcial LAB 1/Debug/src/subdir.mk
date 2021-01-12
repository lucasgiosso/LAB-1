################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Segunda\ Parcial\ LAB\ 1.c \
../src/articulos.c \
../src/controller.c \
../src/linkedList.c \
../src/parser.c \
../src/utn.c 

OBJS += \
./src/Segunda\ Parcial\ LAB\ 1.o \
./src/articulos.o \
./src/controller.o \
./src/linkedList.o \
./src/parser.o \
./src/utn.o 

C_DEPS += \
./src/Segunda\ Parcial\ LAB\ 1.d \
./src/articulos.d \
./src/controller.d \
./src/linkedList.d \
./src/parser.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/Segunda\ Parcial\ LAB\ 1.o: ../src/Segunda\ Parcial\ LAB\ 1.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Segunda Parcial LAB 1.d" -MT"src/Segunda\ Parcial\ LAB\ 1.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


