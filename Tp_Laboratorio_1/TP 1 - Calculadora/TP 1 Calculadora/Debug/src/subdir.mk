################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TP\ Calculadora.c \
../src/funcionestp.c 

OBJS += \
./src/TP\ Calculadora.o \
./src/funcionestp.o 

C_DEPS += \
./src/TP\ Calculadora.d \
./src/funcionestp.d 


# Each subdirectory must supply rules for building sources it contributes
src/TP\ Calculadora.o: ../src/TP\ Calculadora.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/TP Calculadora.d" -MT"src/TP\ Calculadora.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


