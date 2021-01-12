################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Primer\ Parcial\ LAB\ 1.c \
../src/cliente.c \
../src/prestamo.c \
../src/utn.c 

OBJS += \
./src/Primer\ Parcial\ LAB\ 1.o \
./src/cliente.o \
./src/prestamo.o \
./src/utn.o 

C_DEPS += \
./src/Primer\ Parcial\ LAB\ 1.d \
./src/cliente.d \
./src/prestamo.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/Primer\ Parcial\ LAB\ 1.o: ../src/Primer\ Parcial\ LAB\ 1.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Primer Parcial LAB 1.d" -MT"src/Primer\ Parcial\ LAB\ 1.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


